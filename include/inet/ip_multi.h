/*
 * Copyright 2010 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_INET_IP_MULTI_H
#define	_INET_IP_MULTI_H

#pragma ident	"@(#)ip_multi.h	1.29	10/01/19 SMI"

#ifdef	__cplusplus
extern "C" {
#endif

#if defined(_KERNEL)

#define	INFINITY	0xffffffffU
/*
 * Enum used to pass ilg status to ip_addmulti() and friends. There
 * are three possibilities: the group is being joined from within ip,
 * in which case there is no associated ilg; the group is being joined
 * from an upper layer with an associated ilg that's been newly created
 * by this join; or the upper layer is changing its group membership
 * state (the ilg existed before this call).
 */
typedef enum {
	ILGSTAT_NONE,
	ILGSTAT_NEW,
	ILGSTAT_CHANGE
} ilg_stat_t;

/*
 * Flags shared via ips_mrt_flags, used by mcast_restart_timers_thread().
 */
typedef enum {
	IP_MRT_STOP	= 0x1,  /* request to stop thread */
	IP_MRT_DONE	= 0x2,  /* indication that thread is stopped */
	IP_MRT_RUN	= 0x4   /* request to restart timers */
} ip_mrt_flags_t;

/*
 * Extern functions
 */
extern	mblk_t		*igmp_input(queue_t *, mblk_t *, ill_t *);
extern	void		igmp_joingroup(ilm_t *);
extern	void		igmp_leavegroup(ilm_t *);
extern	void		igmp_slowtimo(void *);
extern	void		igmp_timeout_handler(void *);
extern	void		igmp_timeout_start(int);
extern	void		igmp_statechange(ilm_t *, mcast_record_t, slist_t *);

extern	void		mld_joingroup(ilm_t *);
extern	void		mld_leavegroup(ilm_t *);
extern	void		mld_statechange(ilm_t *, mcast_record_t, slist_t *);
extern	void		mld_slowtimo(void *);

extern	void		ilg_delete_all(conn_t *connp);
extern	ilg_t		*ilg_lookup_ill_v6(conn_t *, const in6_addr_t *,
    ill_t *);
extern	ilg_t		*ilg_lookup_ill_withsrc(conn_t *, ipaddr_t, ipaddr_t,
    ill_t *);
extern	ilg_t		*ilg_lookup_ill_withsrc_v6(conn_t *, const in6_addr_t *,
    const in6_addr_t *, ill_t *);

extern void		ill_leave_multicast(ill_t *);
extern void		ill_recover_multicast(ill_t *);
extern	int		ip_get_dlpi_mbcast(ill_t *, mblk_t *);

extern	void		ilm_free(ipif_t *);
extern	ilm_t		*ilm_lookup_ill_withsrc(ill_t *, ipaddr_t, ipaddr_t);
extern	ilm_t		*ilm_lookup_ill_withsrc_v6(ill_t *, const in6_addr_t *,
    const in6_addr_t *);
extern	ilm_t		*ilm_lookup_ill(ill_t *, ipaddr_t, zoneid_t);
extern	ilm_t		*ilm_lookup_ill_v6(ill_t *, const in6_addr_t *,
    zoneid_t);
extern	ilm_t		*ilm_lookup_ill_index_v6(ill_t *, const in6_addr_t *,
    int, zoneid_t);
extern	ilm_t		*ilm_lookup_ipif(ipif_t *, ipaddr_t);

extern int		ilm_numentries_v6(ill_t *, const in6_addr_t *);
extern int		ilm_walk_ipif(ipif_t *);
extern int		ilm_walk_ill(ill_t *);
extern void		ilm_walker_cleanup(ill_t *);
extern int		ip_ll_send_disabmulti_req(ill_t *, const in6_addr_t *);
extern int		ip_ll_send_enabmulti_req(ill_t *, const in6_addr_t *);

extern	int		ip_addmulti(ipaddr_t, ipif_t *, ilg_stat_t,
    mcast_record_t, slist_t *);
extern	int		ip_addmulti_v6(const in6_addr_t *, ill_t *, int,
    zoneid_t, ilg_stat_t, mcast_record_t, slist_t *);
extern	int		ip_delmulti(ipaddr_t, ipif_t *, boolean_t, boolean_t);
extern	int		ip_delmulti_v6(const in6_addr_t *, ill_t *, int,
    zoneid_t, boolean_t, boolean_t);
extern	int		ip_join_allmulti(ipif_t *);
extern	int		ip_leave_allmulti(ipif_t *);
extern	void		ip_multicast_loopback(queue_t *, ill_t *, mblk_t *,
    int, zoneid_t);
extern	int		ip_mforward(ill_t *, ipha_t *, mblk_t *);
extern	void		ip_mroute_decap(queue_t *, mblk_t *, ill_t *);
extern	int		ip_mroute_mrt(mblk_t *, ip_stack_t *);
extern	int		ip_mroute_stats(mblk_t *, ip_stack_t *);
extern	int		ip_mroute_vif(mblk_t *, ip_stack_t *);
extern	int		ip_mrouter_done(mblk_t *, ip_stack_t *);
extern	int		ip_mrouter_get(int, queue_t *, uchar_t *);
extern	int		ip_mrouter_set(int, queue_t *, int, uchar_t *, int,
    mblk_t *);
extern	void		ip_mrouter_stack_init(ip_stack_t *);
extern	void		ip_mrouter_stack_destroy(ip_stack_t *);

extern	int		ip_opt_add_group(conn_t *, boolean_t, ipaddr_t,
    ipaddr_t, uint_t *, mcast_record_t, ipaddr_t, mblk_t *first_mp);
extern	int		ip_opt_delete_group(conn_t *, boolean_t, ipaddr_t,
    ipaddr_t, uint_t *, mcast_record_t, ipaddr_t, mblk_t *first_mp);
extern	int		ip_opt_add_group_v6(conn_t *, boolean_t,
    const in6_addr_t *, int, mcast_record_t, const in6_addr_t *, mblk_t *);
extern	int		ip_opt_delete_group_v6(conn_t *, boolean_t,
    const in6_addr_t *, int, mcast_record_t, const in6_addr_t *, mblk_t *);

extern	int		ip_sioctl_msfilter(ipif_t *, sin_t *, queue_t *,
    mblk_t *, ip_ioctl_cmd_t *, void *);
extern	int		ip_extract_msfilter(queue_t *, mblk_t *, ipif_t **,
    ipsq_func_t);
extern	int		ip_copyin_msfilter(queue_t *, mblk_t *);

extern	void		ip_wput_ctl(queue_t *, mblk_t *);

extern  int	mrt_ioctl(ipif_t *ipif, sin_t *sin, queue_t *q, mblk_t *mp,
    ip_ioctl_cmd_t *ipip, void *if_req);

extern	int		pim_input(queue_t *, mblk_t *, ill_t *);
extern	void		reset_conn_ipif(ipif_t *);
extern	void		reset_conn_ill(ill_t *);
extern	void		reset_mrt_ill(ill_t *);
extern	void		reset_mrt_vif_ipif(ipif_t *);
extern	void		mcast_restart_timers_thread(ip_stack_t *);
/*
 * Extern variables
 */

#endif /* _KERNEL */

#ifdef	__cplusplus
}
#endif

#endif	/* _INET_IP_MULTI_H */
