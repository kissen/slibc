CFLAGS += -ffreestanding -nostdinc -I include/ -I src/

static_library := bin/slibc.a

source_dirs := $(wildcard src/*)
source_files := $(wildcard src/*/*.c) $(wildcard src/*/*.s)
object_dirs := $(patsubst src/%, bin/%/, $(source_dirs))
object_files := $(patsubst src/%.c, bin/%.o, $(source_files))

all: $(static_library)

$(static_library): $(object_files)
	$(AR) -cr $@ $?

bin/%.o: src/%.c | $(object_dirs)
	$(CC) $(CFLAGS) -c -o $@ $<

bin/%.o: src/%.s | $(object_dirs)
	$(CC) -c -o $@ $<

bin/:
	mkdir -p $@

bin/%/:
	mkdir -p $@

clean:
	rm -f $(static_library)
	rm -f $(filter %.o, $(object_files))
	rm -df $(object_dirs) bin/

.PHONY: all clean
.PRECIOUS: $(object_dirs)
