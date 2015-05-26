/*-------------------------------------------------------------------------
 *
 * predtest.h
 *	  prototypes for predtest.c
 *
 *
 * Portions Copyright (c) 1996-2005, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * $PostgreSQL: pgsql/src/include/optimizer/predtest.h,v 1.3 2005/10/15 02:49:45 momjian Exp $
 *
 *-------------------------------------------------------------------------
 */
#ifndef PREDTEST_H
#define PREDTEST_H

#include "nodes/primnodes.h"


extern bool predicate_implied_by(List *predicate_list,
					 List *restrictinfo_list);
extern bool predicate_refuted_by(List *predicate_list,
					 List *restrictinfo_list);

#endif   /* PREDTEST_H */
