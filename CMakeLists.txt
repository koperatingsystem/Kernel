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

set(CMAKE_SYSTEM_NAME Generic)

cmake_minimum_required(VERSION 3.0.0)
project(kOS.Kernel LANGUAGES C VERSION 1.0.0)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/BuildScripts)

include(RuntimeSetup)
include(Utilities)

add_executable(kOS.Kernel
    ${CMAKE_CURRENT_LIST_DIR}/Includes/Kernel/TerminalIO.h
    ${CMAKE_CURRENT_LIST_DIR}/Includes/Timing.h

    ${CMAKE_CURRENT_LIST_DIR}/Sources/Platforms/i386/TerminalIO.c
    ${CMAKE_CURRENT_LIST_DIR}/Sources/Platforms/i386/VGA.h

    ${CMAKE_CURRENT_LIST_DIR}/Sources/Kernel/Main.c
)

add_subdirectory(Other/libc)
add_dependencies(kOS.Kernel kOS.libc)

target_compile_definitions(kOS.libc PRIVATE __is_libk)
target_include_directories(kOS.libc PRIVATE ${CMAKE_CURRENT_LIST_DIR}/Includes)

target_compile_options(kOS.Kernel PRIVATE -mcmodel=large -mno-red-zone -mno-mmx -mno-sse -mno-sse2)
target_include_directories(kOS.Kernel PRIVATE ${CMAKE_CURRENT_LIST_DIR}/Includes)

target_link_options(kOS.Kernel PRIVATE -ekOS_main)
target_link_libraries(kOS.Kernel PRIVATE kOS.libc)

kOS_Set_Up_Target(kOS.Kernel)
