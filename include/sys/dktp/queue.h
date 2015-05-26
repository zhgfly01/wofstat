/*
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_DKTP_QUEUE_H
#define	_SYS_DKTP_QUEUE_H

#pragma ident	"@(#)queue.h	1.6	06/01/09 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

struct	que_obj {
	opaque_t		que_data;
	struct que_objops	*que_ops;
};

struct	que_objops {
	int	(*que_init)(struct que_data *, void *);
	int	(*que_free)(struct que_obj *);
	int	(*que_ins)(struct que_data *, struct buf *);
	struct buf *(*que_del)(struct que_data *);
	void	*que_res[2];
};

struct que_obj *qfifo_create();
struct que_obj *qmerge_create();
struct que_obj *qsort_create();
struct que_obj *qtag_create();

#define	QUE_INIT(X, lkarg) (*((struct que_obj *)(X))->que_ops->que_init) \
	(((struct que_obj *)(X))->que_data, (lkarg))
#define	QUE_FREE(X) (*((struct que_obj *)(X))->que_ops->que_free) ((X))
#define	QUE_ADD(X, bp) (*((struct que_obj *)(X))->que_ops->que_ins) \
	(((struct que_obj *)(X))->que_data, (bp))
#define	QUE_DEL(X) (*((struct que_obj *)(X))->que_ops->que_del) \
	(((struct que_obj *)(X))->que_data)

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_DKTP_QUEUE_H */
