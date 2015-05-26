/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_ACCTCTL_H
#define	_SYS_ACCTCTL_H

#pragma ident	"@(#)acctctl.h	1.6	04/09/24 SMI"

#include <sys/types.h>
#include <sys/bitmap.h>
#include <sys/sysmacros.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Definitions for acctctl() system call
 */

/*
 * modes
 */
#define	AC_PROC		(0x1 << 28)	/* change process accounting settings */
#define	AC_TASK		(0x2 << 28)	/* change task accounting settings */
#define	AC_FLOW		(0x4 << 28)	/* change flow accounting settings */
#define	AC_MODE(x)	((x) & 0xf0000000)

/*
 * options
 */
#define	AC_FILE_SET	(0x01)	/* set accounting file name */
#define	AC_FILE_GET	(0x02)	/* get accounting file name */
#define	AC_RES_SET	(0x04)	/* set (enable/disable) resources */
#define	AC_RES_GET	(0x08)	/* get a list of enabled resources */
#define	AC_STATE_SET	(0x10)	/* set accounting mode state (on/off) */
#define	AC_STATE_GET	(0x20)	/* get accounting mode state */
#define	AC_OPTION(x)	((x) & 0x0fffffff)

/*
 * Process accounting resource IDs
 */
#define	AC_NONE			0	/* special end-of-list identifier */
#define	AC_PROC_PID		1	/* process ID */
#define	AC_PROC_UID		2	/* user ID */
#define	AC_PROC_GID		3	/* group ID */
#define	AC_PROC_PROJID		4	/* project ID */
#define	AC_PROC_TASKID		5	/* task ID */
#define	AC_PROC_CPU		6	/* user/system cpu time */
#define	AC_PROC_TIME		7	/* start/finish time */
#define	AC_PROC_COMMAND		8	/* command name */
#define	AC_PROC_TTY		9	/* control tty */
#define	AC_PROC_HOSTNAME	10	/* hostname */
#define	AC_PROC_MICROSTATE	11	/* microstate accounting */
#define	AC_PROC_FLAG		12	/* accounting flags */
#define	AC_PROC_ANCPID		13	/* ancestor process's ID */
#define	AC_PROC_WAIT_STATUS	14	/* process wait status */
#define	AC_PROC_ZONENAME	15	/* zone name */
#define	AC_PROC_MEM		16	/* memory usage */
#define	AC_PROC_MAX_RES		16	/* must be equal to the number above */

/*
 * Task accounting resource IDs
 */
#define	AC_TASK_TASKID		1	/* task ID */
#define	AC_TASK_PROJID		2	/* project ID */
#define	AC_TASK_CPU		3	/* user/system cpu time */
#define	AC_TASK_TIME		4	/* start/finish time */
#define	AC_TASK_HOSTNAME	5	/* hostname */
#define	AC_TASK_MICROSTATE	6	/* microstate accounting */
#define	AC_TASK_ANCTASKID	7	/* ancestor task's taskid */
#define	AC_TASK_ZONENAME	8	/* zone name */
#define	AC_TASK_MAX_RES		8	/* must be equal to the number above */

/*
 * Flow accounting resource IDs
 */
#define	AC_FLOW_SADDR		1	/* source address */
#define	AC_FLOW_DADDR		2	/* destination address */
#define	AC_FLOW_SPORT		3	/* source port */
#define	AC_FLOW_DPORT		4	/* destination port */
#define	AC_FLOW_PROTOCOL	5	/* protocol */
#define	AC_FLOW_DSFIELD		6	/* dsfield */
#define	AC_FLOW_CTIME		7	/* creation time for this flow */
#define	AC_FLOW_LSEEN		8	/* pkt last seen for this flow */
#define	AC_FLOW_NBYTES		9	/* no. of bytes in this flow */
#define	AC_FLOW_NPKTS		10	/* no. of packets for this flow */
#define	AC_FLOW_PROJID		11	/* project id */
#define	AC_FLOW_UID		12	/* user id */
#define	AC_FLOW_ANAME		13	/* action instance name */
#define	AC_FLOW_MAX_RES		13	/* must be equal to the number above */

#define	AC_MAX_RES_TMP		MAX(AC_PROC_MAX_RES, AC_TASK_MAX_RES)
#define	AC_MAX_RES		MAX(AC_MAX_RES_TMP, AC_FLOW_MAX_RES)
#define	AC_MASK_SZ		BT_BITOUL(AC_MAX_RES + 1)

/*
 * resource states
 */
#define	AC_ON		1	/* enabled resource */
#define	AC_OFF		0	/* disabled resource */

typedef struct ac_res {
	int	ar_id;		/* resource ID */
	int	ar_state;	/* resource state; see above */
} ac_res_t;

#ifdef	_KERNEL

#include <sys/vnode.h>
#include <sys/zone.h>
#include <sys/list.h>

typedef struct ac_info {
	kmutex_t	ac_lock;		/* protects the structure */
	vnode_t		*ac_vnode;		/* exacct file vnode pointer */
	char		*ac_file;		/* exacct file name */
	int		ac_state;		/* accounting state */
	ulong_t		ac_mask[AC_MASK_SZ];	/* bitmask of resources */
} ac_info_t;

/*
 * Key used for retrieving per-zone exacct settings.  This remains
 * uninitialized (ZONE_KEY_UNINITIALIZED) until the acctctl module is loaded.
 */
extern zone_key_t exacct_zone_key;

/*
 * Per-zone exacct settings.  Each zone may have its own settings for
 * process, task, and flow accounting.
 *
 * Per-zone flow accounting has not yet been implemented, so this
 * provides zones with the view that flow accounting in the zone hasn't
 * been initialized (which is true).  The various system calls will fail
 * to set flow accounting parameters from within a zone.
 *
 * The global list of accounting settings is used when we check to see
 * if the accounting file is already in use by any zone.
 */
struct exacct_globals {
	ac_info_t	ac_task;
	ac_info_t	ac_proc;
	ac_info_t	ac_flow;
	list_node_t	ac_link;
};

#else

extern int acctctl(int cmd, void *buf, size_t bufsz);

#endif	/* ifdef _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_ACCTCTL_H */
