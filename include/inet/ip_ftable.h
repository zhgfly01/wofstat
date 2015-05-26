/*
 * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _INET_IP_FTABLE_H
#define	_INET_IP_FTABLE_H

#pragma ident	"@(#)ip_ftable.h	1.3	08/11/11 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef 	_KERNEL

#include <net/radix.h>
#include <inet/common.h>
#include <inet/ip.h>

struct rt_entry {
	struct	radix_node rt_nodes[2];	/* tree glue, and other values */
	/*
	 * struct rt_entry must begin with a struct radix_node (or two!)
	 * to a 'struct rt_entry *'
	 */
	struct rt_sockaddr rt_dst;
	/*
	 * multiple routes to same dest/mask via varying gate/ifp are stored
	 * in the rt_irb bucket.
	 */
	irb_t rt_irb;
};

/*
 * vehicle for passing args through rn_walktree
 *
 * The comment below (and for other netstack_t references) refers
 * to the fact that we only do netstack_hold in particular cases,
 * such as the references from open streams (ill_t and conn_t's
 * pointers). Internally within IP we rely on IP's ability to cleanup e.g.
 * ire_t's when an ill goes away.
 */
struct rtfuncarg {
	pfv_t rt_func;
	char *rt_arg;
	uint_t rt_match_flags;
	uint_t rt_ire_type;
	ill_t  *rt_ill;
	zoneid_t rt_zoneid;
	ip_stack_t *rt_ipst;   	/* Does not have a netstack_hold */
};
int rtfunc(struct radix_node *, void *);

typedef struct rt_entry rt_t;
typedef struct rtfuncarg rtf_t;

/* For ire_forward() */
enum ire_forward_action {
	Forward_ok,			/* OK to use this IRE to forward */
	Forward_check_multirt,		/* CGTP multirt check required */
	Forward_ret_icmp_err,		/* Callers to return an ICMP error */
	Forward_blackhole		/* Packet is silently discarded */
};

struct ts_label_s;
extern	ire_t	*ire_ftable_lookup(ipaddr_t, ipaddr_t, ipaddr_t, int,
    const ipif_t *, ire_t **, zoneid_t, uint32_t,
    const struct ts_label_s *, int, ip_stack_t *);
extern	ire_t *ire_lookup_multi(ipaddr_t, zoneid_t, ip_stack_t *);
extern	ire_t *ipif_lookup_multi_ire(ipif_t *, ipaddr_t);
extern	void ire_delete_host_redirects(ipaddr_t, ip_stack_t *);
extern	ire_t *ire_ihandle_lookup_onlink(ire_t *);
extern	ire_t *ire_forward(ipaddr_t, enum ire_forward_action *, ire_t *,
    ire_t *, const struct ts_label_s *, ip_stack_t *);
extern void	ire_ftable_walk(struct rt_entry *, uint_t, uint_t,
    ill_t *, zoneid_t, pfv_t, char *, ip_stack_t *);
extern irb_t	*ire_get_bucket(ire_t *);
extern uint_t ifindex_lookup(const struct sockaddr *, zoneid_t);
extern int ipfil_sendpkt(const struct sockaddr *, mblk_t *, uint_t, zoneid_t);

extern void  irb_refhold_rn(struct radix_node *);
extern void  irb_refrele_rn(struct radix_node *);

#endif /* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _INET_IP_FTABLE_H */
