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

#include <stddef.h>
#include <stdint.h>

void Terminal_Init(void);

size_t Terminal_Get_Cursor_X();
size_t Terminal_Get_Cursor_Y();
void Terminal_Set_Cursor_Position(size_t x, size_t y);

void Terminal_Set_Color(uint8_t color);
void Terminal_Scroll_Up();
void Terminal_Clear_Screen();

void Terminal_Put_Character(char c);
void Terminal_Print_Data(const char* data, size_t size);
void Terminal_Print(const char* data);
void Terminal_Write_VGA(char c, uint8_t color, size_t x, size_t y);
