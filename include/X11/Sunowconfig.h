#pragma ident   "@(#)Sunowconfig.h	1.18    95/08/24 SMI"

/*
 *   -----------------------------------------------------------------
 *          Copyright (C) 1986,1991  Sun Microsystems, Inc
 *                      All rights reserved.
 *            Notice of copyright on this source code
 *            product does not indicate publication.
 *
 *                    RESTRICTED RIGHTS LEGEND:
 *   Use, duplication, or disclosure by the Government is subject
 *   to restrictions as set forth in subparagraph (c)(1)(ii) of
 *   the Rights in Technical Data and Computer Software clause at
 *   DFARS 52.227-7013 and in similar clauses in the FAR and NASA
 *   FAR Supplement.
 *   -----------------------------------------------------------------
 */

/*
 *  This file defines the private and public interfaces to the OWconfig API.
 */

#ifndef  _X_CONFIG_H_
#define  _X_CONFIG_H_

#include <stdio.h>
#include <sys/types.h>
#include <X11/X.h>

#define OWCFG_OK		(Success)
#define OWCFG_OPEN1FAIL		(Success+1)
#define OWCFG_OPEN2FAIL		(Success+2)
#define OWCFG_OPENBOTHFAIL	(Success+3)
#define OWCFG_FSTAT1FAIL	(Success+4)
#define OWCFG_FSTAT2FAIL	(Success+5)
#define OWCFG_LOCK1FAIL		(Success+6)
#define OWCFG_LOCK2FAIL		(Success+7)
#define OWCFG_SYNTAX1		(Success+8)
#define OWCFG_SYNTAX2		(Success+9)
#define OWCFG_PKGNAME		(Success+10)
#define OWCFG_CLASSNAME		(Success+11)
#define OWCFG_INSTANCENAME	(Success+12)
#define OWCFG_ALLOC		(Success+13)
#define OWCFG_ARGS		(Success+14)
#define OWCFG_OPENTMPFAIL	(Success+15)
#define OWCFG_OPENWFAIL		(Success+16)
#define OWCFG_LOCKWFAIL		(Success+17)
#define OWCFG_RENAMEFAIL	(Success+18)


typedef struct {
	char *attribute;
	char *value;
} OWconfigAttribute, *OWconfigAttributePtr;





#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif /* __cplusplus */




/*
 * The functions:
 *		OWconfigGetClassNames
 *		OWconfigFreeClassNames
 *		OWconfigGetAttribute
 *		OWconfigFreeAttribute
 *		OWconfigGetInstance
 *		OWconfigFreeInstance
 *
 * are provided for the use of those wishing to develop DDX drivers
 * for the Xsun server.  Please refer to the OpenWindows Server
 * Device Developer's Guide for more information.
 */

#if defined(__STDC__)

extern char **
OWconfigGetClassNames(char * /*class*/);

extern void
OWconfigFreeClassNames(char ** /*list*/);

extern char *
OWconfigGetAttribute(char * /*class*/, char * /*name*/, char * /*attribute*/);

extern void
OWconfigFreeAttribute(char * /*attribute*/);

extern OWconfigAttributePtr
OWconfigGetInstance(char * /*class*/, char * /*name*/, int * /*numberInattr*/);

extern void
OWconfigFreeInstance(OWconfigAttributePtr /*attr*/, int /*numberInAttr*/);


#else /* ! __STDC__ */

extern char **
OWconfigGetClassNames(/*char *class*/);

extern void
OWconfigFreeClassNames(/*char **list*/);

extern char *
OWconfigGetAttribute(/*char *class, char *name, char *attribute*/);

extern void
OWconfigFreeAttribute(/*char *attribute*/);

extern OWconfigAttributePtr
OWconfigGetInstance(/*char *class, char *name, int *numberInattr*/);

extern void
OWconfigFreeInstance(/*OWconfigAttributePtr attr, int numberInAttr*/);

#endif /* __STDC__ */





/*
 * The functions:
 *		OWconfigInit
 *		OWconfigValidate
 *		OWconfigSetInstance
 *		OWconfigRemoveInstance
 *		OWconfigSetAttribute
 *		OWconfigSetPackage
 *		OWconfigRemovePackage
 *		OWconfigClose
 *
 * are categorized as "Sun Private".  They should not be used by
 * developers outside of Sun Microsystems Inc., or its subsidiaries.
 */

#define OWFLAG_RETAIN 1

#if defined(__STDC__)

extern int
OWconfigInit(char * /*readfile1*/, char * /*readfile2*/, int /*flags*/,
             void *(* /*allocmem*/)(unsigned), void (* /*freemem*/)(void *));

extern int
OWconfigValidate(void);

extern int
OWconfigSetInstance(char * /*class*/, char * /*name*/, 
                    OWconfigAttributePtr /*attr*/,
                    int /*numberInattr*/);

extern int
OWconfigRemoveInstance(char * /*class*/, char * /*name*/);

extern int
OWconfigSetAttribute(char * /*class*/, char * /*name*/, char * /*attribute*/, 
                     char * /*value*/);

extern void
OWconfigSetPackage(char * /*package*/);

extern int
OWconfigRemovePackage(char * /*package*/);

extern int
OWconfigClose(char */*writeFile*/);


#else /* ! __STDC__ */


extern int
OWconfigInit(/*char *readfile1, char *readfile2, int flags,
             void *(*allocmem)(), void (*freemem)()*/);

extern int
OWconfigValidate(/*void*/);

extern int
OWconfigSetInstance(/*char *class, char *name, 
                    OWconfigAttributePtr attr,
                    int numberInattr*/);

extern int
OWconfigRemoveInstance(/*char *class, char *name*/);

extern int
OWconfigSetAttribute(/*char *class, char *name, char *attribute, 
                     char *value*/);

extern void
OWconfigSetPackage(/*char *package*/);

extern int
OWconfigRemovePackage(/*char *package*/);

extern int
OWconfigClose(/*char *writeFile*/);


#endif /* __STDC__ */




#if defined(__cplusplus) || defined(c_plusplus)
}
#endif /* __cplusplus */

#endif /* _X_CONFIG_H_ */
