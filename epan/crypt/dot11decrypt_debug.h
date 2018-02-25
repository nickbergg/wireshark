/* airpcap_debug.h
 *
 * Copyright (c) 2006 CACE Technologies, Davis (California)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the project nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * Alternatively, this software may be distributed under the terms of the
 * GNU General Public License ("GPL") version 2 as published by the Free
 * Software Foundation.
 *
 * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef	_DOT11DECRYPT_DEBUG_H
#define	_DOT11DECRYPT_DEBUG_H

#include "dot11decrypt_interop.h"

/* #define DOT11DECRYPT_DEBUG 1 */

#ifdef DOT11DECRYPT_DEBUG
#ifdef	__FUNCTION__
#define	DOT11DECRYPT_DEBUG_PRINT_LINE(notdefined, msg, level) print_debug_line(__FUNCTION__, msg, level);
#else
#define	DOT11DECRYPT_DEBUG_PRINT_LINE(function, msg, level) print_debug_line(function, msg, level);
#endif
#else
#ifdef	__FUNCTION__
#define	DOT11DECRYPT_DEBUG_PRINT_LINE(notdefined, msg, level)
#else
#define	DOT11DECRYPT_DEBUG_PRINT_LINE(function, msg, level)
#endif
#endif

/******************************************************************************/
/* Debug section: internal function to print debug information						*/
/*																										*/
#ifdef DOT11DECRYPT_DEBUG
#include <stdio.h>
#include <time.h>

#include <epan/to_str.h>

/*	Debug level definition																		*/
#define	DOT11DECRYPT_DEBUG_LEVEL_1	1
#define	DOT11DECRYPT_DEBUG_LEVEL_2	2
#define	DOT11DECRYPT_DEBUG_LEVEL_3	3
#define	DOT11DECRYPT_DEBUG_LEVEL_4	4
#define	DOT11DECRYPT_DEBUG_LEVEL_5	5

#define	DOT11DECRYPT_DEBUG_USED_LEVEL	DOT11DECRYPT_DEBUG_LEVEL_3

static inline void print_debug_line(const CHAR *function, const CHAR *msg, const INT level)
{
    if (level<=DOT11DECRYPT_DEBUG_USED_LEVEL)
        g_warning("dbg(%d)|(%s) %s", level, function, msg);
}

#ifdef	_TRACE
#ifdef	__FUNCTION__
#define	DOT11DECRYPT_DEBUG_TRACE_START(notdefined) print_debug_line(__FUNCTION__, "Start!", DOT11DECRYPT_DEBUG_USED_LEVEL);
#define	DOT11DECRYPT_DEBUG_TRACE_END(notdefined) print_debug_line(__FUNCTION__, "End!", DOT11DECRYPT_DEBUG_USED_LEVEL);
#else
#define	DOT11DECRYPT_DEBUG_TRACE_START(function) print_debug_line(function, "Start!", DOT11DECRYPT_DEBUG_USED_LEVEL);
#define	DOT11DECRYPT_DEBUG_TRACE_END(function) print_debug_line(function, "End!", DOT11DECRYPT_DEBUG_USED_LEVEL);
#endif
#else
#ifdef	__FUNCTION__
#define	DOT11DECRYPT_DEBUG_TRACE_START(notdefined)
#define	DOT11DECRYPT_DEBUG_TRACE_END(notdefined)
#else
#define	DOT11DECRYPT_DEBUG_TRACE_START(function)
#define	DOT11DECRYPT_DEBUG_TRACE_END(function)
#endif
#endif

static inline void DEBUG_DUMP(const char* x, const guint8* y, int z)
{
    char* tmp_str = bytes_to_str(NULL, y, (z));
    g_warning("%s: %s", x, tmp_str);
    wmem_free(NULL, tmp_str);
}

#else	/* !defined DOT11DECRYPT_DEBUG	*/

#define	DOT11DECRYPT_DEBUG_LEVEL_1
#define	DOT11DECRYPT_DEBUG_LEVEL_2
#define	DOT11DECRYPT_DEBUG_LEVEL_3
#define	DOT11DECRYPT_DEBUG_LEVEL_4
#define	DOT11DECRYPT_DEBUG_LEVEL_5

#define	DOT11DECRYPT_DEBUG_TRACE_START(function)
#define	DOT11DECRYPT_DEBUG_TRACE_END(function)

#define DEBUG_DUMP(x,y,z)

#endif	/* ?defined DOT11DECRYPT_DEBUG	*/


#endif	/* ?defined _DOT11DECRYPT_DEBUG_H	*/