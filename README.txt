slibc
=====

This is a very much incomplete standard C/POSIX library for Linux amd64 systems.
I wrote it because it is fun and interesting to learn about core software. Maybe
it will be useful to you.

Highlights
----------

* Basic `printf`.

* Many system calls such as `open`, `read` and `close`.

* `mmap`-based `malloc`.

* Basic `FILE` I/O.

Requirements and Building
-------------------------

You will need somewhat recent versions of `gcc` and GNU `make`.

With those requirements installed, you can just run `make` and it should build
the static library (`bin/slibc.a`) as well as a bunch of test programs
(`bin/tests`).

Hacking
-------

If you feel like spending a delightful afternoon implementing some standard C
library functions, you can do that here. Please try to keep to the conventions
used throughout the code base. You will figure it out.

Before issuing your pull request, do run `clang-format` and make sure the
project builds without warnings or errors.

Credit
------

Unless stated otherwise in the given file, the following copyright and license
applies.

   Copyright 2021 Andreas Schärtl

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

For your enjoyment, a copy of the license (`LICENSE.txt`) is also included in
this repository.
