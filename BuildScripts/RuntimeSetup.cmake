# Copyright (c) 2021 The kOS authors.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software.
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

if(NOT ${CMAKE_ASM_COMPILER_ID} STREQUAL "Clang" OR NOT ${CMAKE_C_COMPILER_ID} STREQUAL "Clang" OR NOT ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
message(FATAL_ERROR "kOS does not support GCC, MSVC and other compilers other than LLVM.")
endif()

if(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows")
find_program(LD_LLD NAMES ld.lld REQUIRED)
set(CMAKE_C_LINK_EXECUTABLE "\"${LD_LLD}\" <OBJECTS> -o <TARGET> <LINK_LIBRARIES> <LINK_FLAGS>")
endif()
