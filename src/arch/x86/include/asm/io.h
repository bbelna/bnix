/*
 * Copyright (c) 2022, Brandon Alex Belna
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the name of the University nor the names of its contributors
 *      may be used to endorse or promote products derived from this
 *      software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <asm/stddef.h>

inline static uint8_t inportb(uint16_t _port) {
  uint8_t rv;
  asm volatile("inb %1, %0":"=a"(rv):"dN"(_port));
  return rv;
}

inline static wchar_t inportw(uint16_t _port) {
  wchar_t rv;
  asm volatile("inw %1, %0":"=a"(rv):"dN"(_port));
  return rv;
}

inline static uint32_t inportl(uint16_t _port) {
  uint32_t rv;
  asm volatile("inl %1, %0":"=a"(rv):"dN"(_port));
  return rv;
}

inline static void outportb(uint16_t _port, uint8_t _data) {
  asm volatile("outb %1, %0"::"dN"(_port), "a"(_data));
}

inline static void outportw(uint16_t _port, uint16_t _data) {
  asm volatile("outw %1, %0"::"dN"(_port), "a"(_data));
}

inline static void outportl(uint16_t _port, uint32_t _data) {
  asm volatile("outl %1, %0"::"dN"(_port), "a"(_data));
}
