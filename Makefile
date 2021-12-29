CFLAGS += -static -ffreestanding -nostdinc -nostdlib -I include/ -I src/

static_library := bin/slibc.a

source_dirs := $(wildcard src/*)
source_files := $(wildcard src/*/*.c) $(wildcard src/*/*.s)
object_dirs := $(patsubst src/%, bin/%/, $(source_dirs))
object_files := $(patsubst src/%.c, bin/%.o, $(filter src/%.c, $(source_files))) $(patsubst src/%.s, bin/%.o, $(filter src/%.s, $(source_files)))

test_files := $(wildcard tests/*.c)
test_exes := $(patsubst tests/%.c, bin/tests/%, $(test_files))

all: $(static_library) $(test_exes)

$(static_library): $(object_files)
	rm -f $@
	$(AR) -cr $@ $^

bin/%.o: src/%.c | $(object_dirs)
	$(CC) $(CFLAGS) -c -o $@ $<

bin/%.o: src/%.s | $(object_dirs)
	$(CC) -c -o $@ $<

bin/tests/%: tests/%.c $(static_library) | bin/tests/
	$(CC) $(CFLAGS) -o $@ $^

bin/:
	mkdir -p $@

bin/%/:
	mkdir -p $@

clean:
	rm -f $(test_exes)
	rm -f $(static_library)
	rm -f $(filter %.o, $(object_files))
	rm -df $(object_dirs) bin/tests/ bin/

.PHONY: all clean
.PRECIOUS: $(object_dirs) bin/tests/
