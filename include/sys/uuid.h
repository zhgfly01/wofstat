/*
 * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_UUID_H
#define	_SYS_UUID_H

#pragma ident	"@(#)uuid.h	1.4	07/01/17 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * The copyright in this file is taken from the original Leach
 * & Salz UUID specification, from which this implementation
 * is derived.
 */

/*
 * Copyright (c) 1990- 1993, 1996 Open Software Foundation, Inc.
 * Copyright (c) 1989 by Hewlett-Packard Company, Palo Alto, Ca. &
 * Digital Equipment Corporation, Maynard, Mass.  Copyright (c) 1998
 * Microsoft.  To anyone who acknowledges that this file is provided
 * "AS IS" without any express or implied warranty: permission to use,
 * copy, modify, and distribute this file for any purpose is hereby
 * granted without fee, provided that the above copyright notices and
 * this notice appears in all source code copies, and that none of the
 * names of Open Software Foundation, Inc., Hewlett-Packard Company,
 * or Digital Equipment Corporation be used in advertising or
 * publicity pertaining to distribution of the software without
 * specific, written prior permission.  Neither Open Software
 * Foundation, Inc., Hewlett-Packard Company, Microsoft, nor Digital
 * Equipment Corporation makes any representations about the
 * suitability of this software for any purpose.
 */

#include <sys/types.h>
#include <sys/byteorder.h>

typedef struct {
	uint8_t		nodeID[6];
} uuid_node_t;

/*
 * The uuid type used throughout when referencing uuids themselves
 */
struct uuid {
	uint32_t	time_low;
	uint16_t	time_mid;
	uint16_t	time_hi_and_version;
	uint8_t		clock_seq_hi_and_reserved;
	uint8_t		clock_seq_low;
	uint8_t		node_addr[6];
};

#define	UUID_LEN	16

#define	UUID_PRINTABLE_STRING_LENGTH 37

typedef uchar_t		uuid_t[UUID_LEN];

/*
 * Convert a uuid to/from little-endian format
 */
#define	UUID_LE_CONVERT(dest, src)					\
{									\
	(dest) = (src);							\
	(dest).time_low = LE_32((dest).time_low);			\
	(dest).time_mid = LE_16((dest).time_mid);			\
	(dest).time_hi_and_version = LE_16((dest).time_hi_and_version);	\
}

#ifdef __cplusplus
}
#endif

#endif /* _SYS_UUID_H */
