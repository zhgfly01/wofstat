/*
 * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SHAREFS_SHARE_H
#define	_SHAREFS_SHARE_H

#pragma ident	"@(#)share.h	1.1	08/02/14 SMI"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * struct share defines the format of an exported filesystem.
 *
 * It is also the interface between the userland tools and
 * the kernel.
 */
typedef struct share {
	char		*sh_path;
	char		*sh_res;
	char		*sh_fstype;
	char		*sh_opts;
	char		*sh_descr;
	size_t		sh_size;
	struct share	*sh_next;
} share_t;

#ifdef _SYSCALL32
typedef struct share32 {
	caddr32_t	sh_path;
	caddr32_t	sh_res;
	caddr32_t	sh_fstype;
	caddr32_t	sh_opts;
	caddr32_t	sh_descr;
	size32_t	sh_size;
	caddr32_t	sh_next;
} share32_t;
#endif /* _SYSCALL32 */

#define	SHARETAB	"/etc/dfs/sharetab"
#define	MAXBUFSIZE	65536

/*
 * Flavors of the system call.
 */
enum sharefs_sys_op { SHAREFS_ADD, SHAREFS_REMOVE, SHAREFS_REPLACE };

#ifdef _KERNEL

extern int sharefs(enum sharefs_sys_op opcode, struct share *sh,
    uint32_t iMaxLen);

#else

extern int _sharefs(enum sharefs_sys_op opcode, struct share *sh);

#endif

#ifdef __cplusplus
}
#endif

#endif /* !_SHAREFS_SHARE_H */
