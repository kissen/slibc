CFLAGS += -g -std=c11 -pedantic -Wall -Wextra -static -ffreestanding -nostdinc -nostdlib -I include/ -I src/

static_library := bin/slibc.a

source_dirs := $(wildcard src/*)
source_files := $(wildcard src/*/*.c) $(wildcard src/*/*.s)
object_dirs := $(patsubst src/%, bin/%/, $(source_dirs))
object_files := $(patsubst src/%.c, bin/%.o, $(filter src/%.c, $(source_files))) $(patsubst src/%.s, bin/%.o, $(filter src/%.s, $(source_files)))

example_files := $(wildcard examples/*.c)
example_exes := $(patsubst examples/%.c, bin/examples/%, $(example_files))

test_files := $(wildcard tests/*.c)
test_exes := $(patsubst tests/%.c, bin/tests/%, $(test_files))

all: $(static_library) $(example_exes) $(test_exes)

release:
	$(MAKE) clean
	CFLAGS="-O3 -flto -Wno-lto-type-mismatch" $(MAKE) all

$(static_library): $(object_files)
	rm -f $@
	$(AR) -cr $@ $^

bin/%.o: src/%.c | $(object_dirs)
	$(CC) $(CFLAGS) -c -o $@ $<

bin/%.o: src/%.s | $(object_dirs)
	$(CC) -c -o $@ $<

bin/examples/%: examples/%.c $(static_library) | bin/examples/
	$(CC) $(CFLAGS) -o $@ $^

bin/tests/%: tests/%.c $(static_library) | bin/tests/
	$(CC) $(CFLAGS) -D__STDC_NO_ATOMICS__ -DMUNIT_NO_NL_LANGINFO -D__thread="" -I ports/munit -o $@ ports/munit/munit.c $^

bin/:
	mkdir -p $@

bin/%/:
	mkdir -p $@

compile_commands.json:
	$(MAKE) clean
	compiledb $(MAKE)

format:
	clang-format -i src/*/*.c src/*/*.h include/*.h include/sys/*.h examples/*.c tests/*.c

clean:
	rm -f $(example_exes)
	rm -f $(static_library)
	rm -f $(test_exes)
	rm -f $(filter %.o, $(object_files))
	rm -df $(object_dirs) bin/examples/ bin/tests/ bin/
	rm -f compile_commands.json
	rm -rf .cache

.PHONY: all release format clean
.PRECIOUS: $(object_dirs) bin/examples/ bin/tests/
