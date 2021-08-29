// Copyright (c) 2021 The kOS authors.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software.
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <stdint.h>

enum VGA_Color
{
    VGA_Color_Black,
    VGA_Color_Blue,
    VGA_Color_Green,
    VGA_Color_Turqoise,     // Cyan
    VGA_Color_Red,
    VGA_Color_Magenta,
    VGA_Color_Brown,
    VGA_Color_Light_Gray,
    VGA_Color_Gray,         // Dark Gray
    VGA_Color_Light_Blue,
    VGA_Color_Light_Green,
    VGA_Color_Cyan,         // Light Cyan
    VGA_Color_Light_Red,
    VGA_Color_Pink,         // Light Magenta
    VGA_Color_Yellow,       // Light Brown
    VGA_Color_White
};

#define VGA_COLOR(foreground, background) ((uint8_t)(foreground | background << 4))
#define VGA_TEXT(text, color) ((uint16_t)((uint16_t)text | (uint16_t)color << 8))
