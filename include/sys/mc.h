/*
 * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _SYS_MC_H
#define	_SYS_MC_H

#pragma ident	"@(#)mc.h	1.3	07/12/04 SMI"

/*
 * Public interfaces exposed by the memory controller driver
 */

#include <sys/cpuvar.h>

#ifdef __cplusplus
extern "C" {
#endif

#define	MC_UNUM_NAMLEN		192
#define	MC_UNUM_NDIMM		2

typedef struct mc_unum {
	int unum_board;			/* system board */
	int unum_chip;			/* chip/socket */
	int unum_mc;			/* memory-controller or branch */
	int unum_chan;			/* DRAM channel */
	int unum_cs;			/* chip-select */
	int unum_rank;			/* rank */
	uint64_t unum_offset;		/* row, column, bank-select etc */
	int unum_dimms[MC_UNUM_NDIMM];
} mc_unum_t;

/*
 * Invalid marker used in some numeric properties
 */
#define	MC_INVALNUM		((uint32_t)-1)

/*
 * /dev/mc/mc* ioctl cmds
 */
#define	MC_IOC			(0x4d43 << 16)
#define	MC_IOC_SNAPSHOT_INFO	(MC_IOC | 1)
#define	MC_IOC_SNAPSHOT		(MC_IOC | 2)
#define	MC_IOC_ONLINESPARE_EN	(MC_IOC | 4)

/*
 * Prior to requesting a copy of the snapshot, consumers are advised to request
 * information regarding the snapshot.  An mc_snapshot_info_t will be returned,
 * containing the snapshot size as well as the snapshot generation number.  Note
 * that, due to the potentially dynamic nature of the system, the snapshot may
 * change at any time.  As such, the information in the mc_snapshot_info_t may
 * be out of date by the time it is used.  The generation number is used to
 * track snapshot changes.  That is, the generation number will be updated each
 * time the source data for the snapshot is updated.  The consumer should not
 * attach any meaning to the magnitude of a generation number change, and pay
 * attention only to the fact that the number has changed.
 */
typedef struct mc_snapshot_info {
	uint32_t mcs_size;	/* snapshot size */
	uint_t mcs_gen;		/* snapshot generation number */
} mc_snapshot_info_t;

#ifdef __cplusplus
}
#endif

#endif /* _SYS_MC_H */
