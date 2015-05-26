/*
 * Copyright 2003 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _STDBOOL_H
#define	_STDBOOL_H

#pragma ident	"@(#)stdbool.h	1.1	03/12/04 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Included for alignment with the ISO/IEC 9899:1999 standard. The
 * contents of this header are only visible when using a c99
 * compiler, otherwise inclusion of this header will result in a
 * forced compilation failure.
 *
 * Note that the ability to undefine and redefine the macros bool,
 * true, and false  is an obsolescent feature which may be withdrawn
 * in a future version of the standards specifications.
 */

#include <sys/feature_tests.h>

#if defined(_STDC_C99)

#undef	bool
#undef	true
#undef	false

#define	bool	_Bool
#define	true	1
#define	false	0

#define	__bool_true_false_are_defined	1

#else /* _STDC_C99 */

#error "Use of <stdbool.h> is valid only in a c99 compilation environment."

#endif /* _STDC_C99 */

#ifdef	__cplusplus
}
#endif

#endif /* _STDBOOL_H */
