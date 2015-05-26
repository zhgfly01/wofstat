/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

#ifndef _SYS_LOCK_H
#define	_SYS_LOCK_H

#pragma ident	"@(#)lock.h	1.10	92/07/14 SMI"	/* SVr4.0 11.7	*/

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * flags for locking procs and texts
 */
#define	UNLOCK	 0
#define	PROCLOCK 1
#define	TXTLOCK	 2
#define	DATLOCK	 4

#ifdef _KERNEL

#define	MEMLOCK	 8

#if defined(__STDC__)
int punlock(void);
#else
int punlock();
#endif	/* __STDC__ */

#else

#if defined(__STDC__)
int plock(int);
#else
int plock();
#endif	/* __STDC__ */

#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_LOCK_H */
