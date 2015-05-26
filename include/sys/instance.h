/*
 * Copyright (c) 1992, 2012, Oracle and/or its affiliates. All rights reserved.
 */

#ifndef	_SYS_INSTANCE_H
#define	_SYS_INSTANCE_H

#pragma ident	"@(#)instance.h	1.19	12/05/10 SMI"

/*
 * Instance number assignment data structures
 */

#include <sys/types.h>
#include <sys/param.h>
#include <sys/dditypes.h>
#include <sys/list.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define	INSTANCE_FILE	"/etc/path_to_inst"
#define	INSTANCE_FILE_SUFFIX	".old"

#if	defined(_KERNEL) || defined(_KMEMUSER)

/*
 * The form of a node;  These form a tree that is parallel to the
 * dev_info tree, but always fully populated.  The tree is rooted in
 * the in_softstate struct (e_ddi_inst_state.ins_root).
 *
 * Each node has one or more in_drv entries hanging from it.
 * (It will have more than one if it has been driven by more than one driver
 * over its lifetime.  This can happen due to a generic name
 * or to a "compatible" name giving a more specific driver).
 */

typedef struct in_node {
	char		*in_node_name;	/* devi_node_name of this node	*/
	char		*in_unit_addr;	/* address part of name		*/
	struct in_node	*in_child;	/* children of this node	*/
	struct in_node	*in_sibling;	/* "peers" of this node		*/
	struct in_drv	*in_drivers;	/* drivers bound to this node	*/
	struct in_node	*in_parent;	/* parent of this node		*/
	dev_info_t	*in_devi;	/* corresponding devinfo	*/
} in_node_t;

typedef struct in_drv {
	char		*ind_driver_name; /* canonical name of driver	*/
	int		ind_instance;	  /* current instance number	*/
	int		ind_state;	  /* see below			*/
	/*
	 * The following field is used to link instance numbers for the
	 * same driver off of devnamesp or in_no_major or in_no_instance
	 */
	struct in_drv	*ind_next;	  /* next for this driver	*/
	struct in_drv	*ind_next_drv;	  /* next driver this node	*/
	struct in_node	*ind_node;	  /* node that these hang on	*/
} in_drv_t;

/*
 * Values for in_state
 */
#define	IN_PROVISIONAL	0x1	/* provisional instance number assigned */
#define	IN_PERMANENT	0x2	/* instance number has been confirmed */
#define	IN_UNKNOWN	0x3	/* instance number not yet assigned */


/*
 * Guard for path to instance file
 */
#define	PTI_GUARD "#\n#\tCaution! This file contains critical kernel state\n#\n"


/*
 * special value for dn_instance
 */
#define	IN_SEARCHME (-1)

#endif	/* defined(_KERNEL) || defined(_KMEMUSER) */

#ifdef	_KERNEL
void e_ddi_instance_init(void);
uint_t e_ddi_assign_instance(dev_info_t *dip);
void e_ddi_keep_instance(dev_info_t *dip);
void e_ddi_free_instance(dev_info_t *dip);
int e_ddi_instance_majorinstance_to_path(major_t major,
	uint_t instance, char *path);
void e_ddi_unorphan_instance_nos(void);
void e_ddi_enter_instance(void);
void e_ddi_exit_instance(void);
in_node_t *e_ddi_instance_root(void);
int e_ddi_instance_is_clean(void);
void e_ddi_instance_set_clean(void);

/* Platform instance override functions */
uint_t impl_assign_instance(dev_info_t *dip);
int impl_keep_instance(dev_info_t *dip);
int impl_free_instance(dev_info_t *dip);

/* walk the instance tree */
int e_ddi_walk_instances(int (*)(const char *,
	in_node_t *, in_drv_t *, void *), void *);

/* for DDI-MP */
in_node_t *e_ddi_path_to_instance(char *path);

/* return values from e_ddi_walk_instances callback */
#define	INST_WALK_CONTINUE	0
#define	INST_WALK_TERMINATE	1


#else	/* _KERNEL */
#ifdef __STDC__
extern int inst_sync(char *pathname, int flags);
#else
extern int inst_sync();
#endif	/* __STDC__ */
#endif	/* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_INSTANCE_H */
