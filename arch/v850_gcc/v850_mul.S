/* libgcc routines for NEC V850.
   Copyright (C) 1996-2020 Free Software Foundation, Inc.
   This file is part of GCC.
   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 3, or (at your option) any
   later version.
   This file is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.
   Under Section 7 of GPL version 3, you are granted additional
   permissions described in the GCC Runtime Library Exception, version
   3.1, as published by the Free Software Foundation.
   You should have received a copy of the GNU General Public License and
   a copy of the GCC Runtime Library Exception along with this program;
   see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
   <http://www.gnu.org/licenses/>.  */


/* original code https://github.com/gcc-mirror/gcc/blob/master/libgcc/config/v850/lib1funcs.S */



#define TOPPERS_MACRO_ONLY
//#include "kernel_impl.h"
#include "v850asm.inc"
	.text
	.global ___muldi3
	.type	___muldi3,@function
___muldi3:
        jarl  __save_r26_r31, r10
/*        addi  16,  sp, sp */
        mov   r6,  r28
        shr   15,  r28
        movea lo(32767), r0, r14
        and   r14, r28
        mov   r8,  r10
        shr   15,  r10
        and   r14, r10
        mov   r6,  r19
        shr   30,  r19
        mov   r7,  r12
        shl   2,   r12
        or    r12, r19
        and   r14, r19
        mov   r8,  r13
        shr   30,  r13
        mov   r9,  r12
        shl   2,   r12
        or    r12, r13
        and   r14, r13
        mov   r7,  r11
        shr   13,  r11
        and   r14, r11
        mov   r9,  r31
        shr   13,  r31
        and   r14, r31
        mov   r7,  r29
        shr   28,  r29
        and   r14, r29
        mov   r9,  r12
        shr   28,  r12
        and   r14, r12
        and   r14, r6
        and   r14, r8
        mov   r6,  r14
        mulh  r8,  r14
        mov   r6,  r16
        mulh  r10, r16
        mov   r6,  r18
        mulh  r13, r18
        mov   r6,  r15
        mulh  r31, r15
        mulh  r12, r6
        mov   r28,  r17
        mulh  r10, r17
/*      add   -16, sp */
        mov   r28,  r12
        mulh  r8,  r12
        add   r17, r18
        mov   r28,  r17
        mulh  r31, r17
        add   r12, r16
        mov   r28,  r12
        mulh  r13, r12
        add   r17, r6
        mov   r19, r17
        add   r12, r15
        mov   r19, r12
        mulh  r8,  r12
        mulh  r10, r17
        add   r12, r18
        mov   r19, r12
        mulh  r13, r12
        add   r17, r15
        mov   r11, r13
        mulh  r8,  r13
        add   r12, r6
        mov   r11, r12
        mulh  r10, r12
        add   r13, r15
        mulh  r29, r8
        add   r12, r6
        mov   r16, r13
        shl   15,  r13
        add   r14, r13
        mov   r18, r12
        shl   30,  r12
        mov   r13, r26
        add   r12, r26
        shr   15,  r14
        movhi hi(131071), r0,  r12
        movea lo(131071), r12, r13
        and   r13, r14
        mov   r16, r12
        and   r13, r12
        add   r12, r14
        mov   r18, r12
        shl   15,  r12
        and   r13, r12
        add   r12, r14
        shr   17,  r14
        shr   17,  r16
        add   r14, r16
        shl   13,  r15
        shr   2,   r18
        add   r18, r15
        add   r15, r16
        mov   r16, r27
        add   r8,  r6
        shl   28,  r6
        add   r6,  r27
        mov   r26, r10
        mov   r27, r11
        jr    __return_r26_r31	
        
       .end

