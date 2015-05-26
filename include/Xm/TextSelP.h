/*
 *  @OSF_COPYRIGHT@
 *  COPYRIGHT NOTICE
 *  Copyright (c) 1990, 1991, 1992, 1993 Open Software Foundation, Inc.
 *  ALL RIGHTS RESERVED (MOTIF). See the file named COPYRIGHT.MOTIF for
 *  the full copyright text.
*/

/*
 *	TextSelP.h	version 1.3, last updated 02/05/16.
*/


/* (c) Copyright 1989, DIGITAL EQUIPMENT CORPORATION, MAYNARD, MASS. */
/* (c) Copyright 1987, 1988, 1989, 1990, 1991, 1992 HEWLETT-PACKARD COMPANY */

#ifndef _XmTextSelP_h
#define _XmTextSelP_h

#include <Xm/XmP.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void
_XmTextGetVisualCharList(XmTextWidget, XmTextPosition, XmTextPosition, XmTextPosition *, int *);

#ifdef __cplusplus
}  /* Close scope of 'extern "C"' declaration which encloses file. */
#endif

#endif /* _XmTextSelP_h */
/* DON't ADD STUFF AFTER THIS #endif */
