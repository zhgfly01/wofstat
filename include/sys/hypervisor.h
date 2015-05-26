/*
 * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/*
 *
 * Communication to/from hypervisor.
 *
 * Copyright (c) 2002-2004, K A Fraser
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this source file (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy, modify,
 * merge, publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef _SYS_HYPERVISOR_H
#define	_SYS_HYPERVISOR_H

#pragma ident	"@(#)hypervisor.h	1.1	08/05/17 SMI"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef XPV_HVM_DRIVER
#include <sys/xpv_support.h>
#else
#include <sys/xpv_impl.h>
#endif
#include <sys/xen_errno.h>

#if !defined(_ASM)

#include <sys/processor.h>
#include <sys/cpuvar.h>
#ifndef XPV_HVM_DRIVER
#include <sys/xen_mmu.h>
#endif
#include <sys/systm.h>
#include <xen/public/callback.h>
#include <xen/public/event_channel.h>
#include <xen/public/grant_table.h>
#include <xen/public/io/blkif.h>
#include <xen/public/io/xenbus.h>
#include <xen/public/memory.h>
#include <xen/public/nmi.h>
#include <xen/public/physdev.h>
#include <xen/public/sched.h>
#include <xen/public/sysctl.h>
#include <xen/public/platform.h>
#include <xen/public/vcpu.h>
#include <xen/public/version.h>
#include <xen/public/acm_ops.h>
#include <xen/public/hvm/params.h>

extern shared_info_t *HYPERVISOR_shared_info;
extern void *HYPERVISOR_console_page;

/* -- move these definitions elsewhere -- */

extern int xen_debug_handler(void *);
extern void xen_printf(const char *, ...) __KPRINTFLIKE(1);
#pragma rarely_called(xen_printf)

extern void xen_callback(void);
extern void xen_failsafe_callback(void);

extern hrtime_t xpv_gethrtime(void);
extern hrtime_t xpv_getsystime(void);

extern void xpv_time_suspend(void);
extern void xpv_time_resume(void);

extern void startup_xen_version(void);

extern void mach_cpucontext_reset(cpu_t *);
extern void mach_cpucontext_restore(cpu_t *);

extern void mp_enter_barrier(void);
extern void mp_leave_barrier(void);

extern cpuset_t cpu_suspend_lost_set;

extern int xen_gdt_setprot(cpu_t *, uint_t);
extern int xen_ldt_setprot(user_desc_t *, size_t, uint_t);

/*
 * Wrappered versions of the hypercalls that diagnose/panic on failure
 */
extern void xen_set_gdt(ulong_t *, int);
extern void xen_set_ldt(user_desc_t *, uint_t);
extern void xen_stack_switch(ulong_t, ulong_t);
extern long xen_set_trap_table(trap_info_t *);

#if defined(__amd64)
extern void xen_set_segment_base(int, ulong_t);
#endif	/* __amd64 */
extern long xen_vcpu_up(processorid_t);
extern long xen_vcpu_down(processorid_t);
extern void xen_enable_user_iopl(void);
extern void xen_disable_user_iopl(void);

/*
 * A quick way to ask if we're DOM0 or not ..
 */
#ifdef XPV_HVM_DRIVER

#define	DOMAIN_IS_INITDOMAIN(info)	(__lintzero)
#define	DOMAIN_IS_PRIVILEGED(info)	(__lintzero)

#else

#define	DOMAIN_IS_INITDOMAIN(info)	\
	(((info)->flags & SIF_INITDOMAIN) == SIF_INITDOMAIN)

#define	DOMAIN_IS_PRIVILEGED(info)	\
	(((info)->flags & SIF_PRIVILEGED) == SIF_PRIVILEGED)

#endif

/*
 * start of day information passed up from the hypervisor
 */
extern start_info_t *xen_info;

extern long __hypercall0(int);
extern long __hypercall1(int, ulong_t);
extern long __hypercall2(int, ulong_t, ulong_t);
extern long __hypercall3(int, ulong_t, ulong_t, ulong_t);
extern long __hypercall4(int, ulong_t, ulong_t, ulong_t, ulong_t);
extern long __hypercall5(int, ulong_t, ulong_t, ulong_t, ulong_t, ulong_t);

extern int __hypercall0_int(int);
extern int __hypercall1_int(int, ulong_t);
extern int __hypercall2_int(int, ulong_t, ulong_t);
extern int __hypercall3_int(int, ulong_t, ulong_t, ulong_t);
extern int __hypercall4_int(int, ulong_t, ulong_t, ulong_t, ulong_t);
extern int __hypercall5_int(int, ulong_t, ulong_t, ulong_t, ulong_t, ulong_t);

extern long HYPERVISOR_set_trap_table(trap_info_t *);
extern int HYPERVISOR_mmu_update(mmu_update_t *, int, int *, domid_t);
extern long HYPERVISOR_set_gdt(ulong_t *, int);
extern long HYPERVISOR_stack_switch(ulong_t, ulong_t);
#if defined(__amd64)
extern long HYPERVISOR_set_callbacks(ulong_t, ulong_t, ulong_t);
#else
extern long HYPERVISOR_set_callbacks(ulong_t, ulong_t, ulong_t, ulong_t);
#endif
extern long HYPERVISOR_fpu_taskswitch(int);
/* *** __HYPERVISOR_sched_op_compat *** OBSOLETED */
extern long HYPERVISOR_platform_op(xen_platform_op_t *);
/* *** __HYPERVISOR_set_debugreg *** NOT IMPLEMENTED */
/* *** __HYPERVISOR_get_debugreg *** NOT IMPLEMENTED */
extern long HYPERVISOR_update_descriptor(maddr_t, uint64_t);
extern long HYPERVISOR_memory_op(int, void *);
extern long HYPERVISOR_multicall(void *, uint_t);
extern int HYPERVISOR_update_va_mapping(ulong_t, uint64_t, ulong_t);
extern long HYPERVISOR_set_timer_op(uint64_t);
/* *** __HYPERVISOR_event_channel_op_compat *** OBSOLETED */
extern long HYPERVISOR_xen_version(int, void *);
extern long HYPERVISOR_console_io(int, int, char *);
/* *** __HYPERVISOR_physdev_op_compat *** OBSOLETED */
extern long HYPERVISOR_grant_table_op(unsigned int, void *, unsigned int);
extern long HYPERVISOR_vm_assist(unsigned int, unsigned int);
extern int HYPERVISOR_update_va_mapping_otherdomain(ulong_t,
    uint64_t, ulong_t, domid_t);
/* *** __HYPERVISOR_iret *** IN i86xpv/sys/machprivregs.h */
extern long HYPERVISOR_vcpu_op(int, int, void *);
#if defined(__amd64)
extern long HYPERVISOR_set_segment_base(int, ulong_t);
#endif	/* __amd64 */
extern int HYPERVISOR_mmuext_op(struct mmuext_op *, int, uint_t *, domid_t);
extern long HYPERVISOR_acm_op(struct xen_acmctl *);
extern long HYPERVISOR_nmi_op(int cmd, void *);
extern long HYPERVISOR_sched_op(int, void *);
extern long HYPERVISOR_callback_op(int, void *);
/* *** __HYPERVISOR_xenoprof_op *** NOT IMPLEMENTED */
extern long HYPERVISOR_event_channel_op(int, void *); /* does return long */
extern long HYPERVISOR_physdev_op(int, void *);
extern long HYPERVISOR_hvm_op(int cmd, void *);
extern long HYPERVISOR_sysctl(xen_sysctl_t *);
extern long HYPERVISOR_domctl(xen_domctl_t *domctl);
/* *** __HYPERVISOR_kexec_op *** NOT IMPLEMENTED */


/*
 * HYPERCALL HELPER ROUTINES
 *    These don't have their own unique hypercalls.
 */
extern long HYPERVISOR_yield(void);
extern long HYPERVISOR_block(void);
extern long HYPERVISOR_shutdown(uint_t);
extern long HYPERVISOR_poll(evtchn_port_t *, uint_t, uint64_t);
extern long HYPERVISOR_suspend(ulong_t);

#endif /* !_ASM */

#ifdef __cplusplus
}
#endif

#endif /* _SYS_HYPERVISOR_H */
