/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_FIBRE_CHANNEL_FC_APPIF_H
#define	_SYS_FIBRE_CHANNEL_FC_APPIF_H

#pragma ident	"@(#)fc_appif.h	1.6	04/10/12 SMI"
#include <sys/note.h>

#ifdef	__cplusplus
extern "C" {
#endif

#if !defined(_BIT_FIELDS_LTOH) && !defined(_BIT_FIELDS_HTOL)
#error	One of _BIT_FIELDS_LTOH or _BIT_FIELDS_HTOL must be defined
#endif	/* _BIT_FIELDS_LTOH */

/*
 * port topology definitions
 */
#define	FC_TOP_UNKNOWN 		0
#define	FC_TOP_PRIVATE_LOOP	1
#define	FC_TOP_PUBLIC_LOOP	2
#define	FC_TOP_FABRIC		3
#define	FC_TOP_PT_PT		4
#define	FC_TOP_NO_NS		5

#define	FC_TOP_EXTERNAL(t)	FC_IS_TOP_SWITCH(t)

#define	FC_IS_TOP_SWITCH(t)	(((t) == FC_TOP_FABRIC) ||\
				((t) == FC_TOP_PUBLIC_LOOP))

/*
 * fc_port_device state (map_state) definitions.
 */
#define	PORT_DEVICE_INVALID	0
#define	PORT_DEVICE_VALID	1
#define	PORT_DEVICE_LOGGED_IN	2

/*
 * Firmware, FCode revision field lengths
 */
#define	FC_FCODE_REV_SIZE	25
#define	FC_FW_REV_SIZE		25

typedef struct ct_header {
#if defined(_BIT_FIELDS_LTOH)
	uint32_t	ct_inid	: 24,		/* Initial Node ID */
			ct_rev	: 8;		/* Revision */

	uint32_t	ct_reserved1 : 8,
			ct_options : 8,
			ct_fcssubtype : 8,
			ct_fcstype : 8;

	uint32_t	ct_aiusize : 16,
			ct_cmdrsp : 16;

	uint32_t	ct_vendor : 8,
			ct_expln : 8,
			ct_reason : 8,
			ct_reserved2 : 8;

#else
	uint32_t	ct_rev : 8,		/* revision */
			ct_inid : 24;		/* initial node ID */
	uint32_t	ct_fcstype : 8,		/* type of service */
			ct_fcssubtype : 8,	/* subtype of service */
			ct_options : 8,		/* options */
			ct_reserved1 : 8;	/* reserved */

	uint32_t	ct_cmdrsp : 16,		/* command/response code */
			ct_aiusize : 16;	/* AIU/residual size */

	uint32_t	ct_reserved2 : 8,	/* reserved */
			ct_reason : 8,		/* reason code */
			ct_expln : 8,		/* reason explanation */
			ct_vendor : 8;		/* vendor unique */

#endif	/* _BIT_FIELDS_LTOH */
} fc_ct_header_t;

/* World Wide Name format */
typedef union la_wwn {
	uchar_t			raw_wwn[8];

#if defined(_BIT_FIELDS_LTOH)
	struct {
		uint32_t	wwn_hi : 16,
				nport_id : 12,
				naa_id : 4;
		uint32_t	wwn_lo;
	}w;

#else
	struct {
		uint32_t	naa_id : 4,
				nport_id : 12,
				wwn_hi : 16;
		uint32_t	wwn_lo;
	}w;
#endif	/* _BIT_FIELDS_LTOH */
} la_wwn_t;

/*
 * Values for naa_id
 */
#define	NAA_ID_IEEE		1
#define	NAA_ID_IEEE_EXTENDED	2

#ifndef	FC_WWN_SIZE
#define	FC_WWN_SIZE		(sizeof (la_wwn_t))
#endif /* FC_WWN_SIZE */

typedef struct service_param {
	uint16_t	class_opt;
	uint16_t	initiator_ctl;
	uint16_t	recipient_ctl;
	uint16_t	rcv_size;
	uint16_t	conc_sequences;
	uint16_t	n_port_e_to_e_credit;
	uint16_t	open_seq_per_xchng;
	uint16_t	rsvd;
} svc_param_t;

typedef struct common_service {
	uint16_t    fcph_version;
	uint16_t    btob_credit;
	uint16_t    cmn_features;
	uint16_t    rx_bufsize;
	uint16_t    conc_sequences;
	uint16_t    relative_offset;
	uint32_t    e_d_tov;
} com_svc_t;

typedef struct ls_code {
#if defined(_BIT_FIELDS_LTOH)
	uint32_t	mbz : 24,
			ls_code : 8;

#else
	uint32_t	ls_code : 8,
			mbz : 24;
#endif	/* _BIT_FIELDS_LTOH */
} ls_code_t;


/* Login Payload. */
typedef struct la_els_logi {
	ls_code_t	ls_code;
	com_svc_t	common_service;

	la_wwn_t	nport_ww_name;
	la_wwn_t	node_ww_name;

	svc_param_t	class_1;
	svc_param_t	class_2;
	svc_param_t	class_3;

	uchar_t		reserved[16];
	uchar_t		vendor_version[16];
} la_els_logi_t;

typedef struct fc_ns_cmd {
	uint32_t	ns_flags;		/* for future use */
	uint16_t	ns_cmd;			/* NS command type */
	uint16_t	ns_req_len;
	caddr_t		ns_req_payload;		/* No CT header */
	uint16_t	ns_resp_len;
	caddr_t		ns_resp_payload;	/* no CT header */
	void		*ns_fctl_private;	/* Transport private */
	fc_ct_header_t	ns_resp_hdr;		/* for the curious */
} fc_ns_cmd_t;

#if defined(_SYSCALL32)

#if _LONG_LONG_ALIGNMENT == 8 && _LONG_LONG_ALIGNMENT_32 == 4
#pragma pack(4)
#endif

typedef struct la_els_logi32 {
	ls_code_t	ls_code;
	com_svc_t	common_service;
	la_wwn_t	nport_ww_name;
	la_wwn_t	node_ww_name;
	svc_param_t	class_1;
	svc_param_t	class_2;
	svc_param_t	class_3;
	uchar_t		reserved[16];
	uchar_t		vendor_version[16];
} la_els_logi32_t;

typedef struct fc_ns_cmd32 {
	uint32_t	ns_flags;		/* for future use */
	uint16_t	ns_cmd;			/* NS command type */
	uint16_t	ns_req_len;
	caddr_t		ns_req_payload;		/* No CT header */
	uint16_t	ns_resp_len;
	caddr_t		ns_resp_payload;	/* no CT header */
	void		*ns_fctl_private;	/* Transport private */
	fc_ct_header_t	ns_resp_hdr;		/* for the curious */
} fc_ns_cmd32_t;

#if _LONG_LONG_ALIGNMENT == 8 && _LONG_LONG_ALIGNMENT_32 == 4
#pragma pack()
#endif

#endif	/* _SYSCALL32 */

/* Link Error Parameters in the RLS Accept payload */
typedef struct fc_rls_acc_params {
	uint32_t	rls_link_fail;		/* link failure count */
	uint32_t	rls_sync_loss;		/* loss of sync count */
	uint32_t	rls_sig_loss;		/* loss of signal count */
	uint32_t	rls_prim_seq_err;	/* primitive seq error */
	uint32_t	rls_invalid_word;	/* invalid tx word */
	uint32_t	rls_invalid_crc;	/* invalid CRC count */
} fc_rls_acc_t;

/* RLS Payload. */
typedef struct la_els_rls {
	ls_code_t	ls_code;
	fc_portid_t	rls_portid;		/* port identifier */
} la_els_rls_t;

/* RLS accept payload */
typedef struct la_els_rls_acc {
	ls_code_t	ls_code;
	fc_rls_acc_t	rls_link_params;	/* link error status block */
} la_els_rls_acc_t;

/* Node Id Parameters in the RNID Get/Set Accept/Request payload */
typedef struct fc_rnid_params {
	uchar_t		global_id[16];		/* global name */
	uint32_t	unit_type;		/* unit type */
	uint32_t	port_id;		/* port id */
	uint32_t	num_attached;		/* number of attached nodes */
	uint16_t	ip_version;		/* ip version */
	uint16_t	udp_port;		/* udp port number */
	uchar_t		ip_addr[16];		/* ip address */
	uint16_t	specific_id_resv;	/* reserved */
	uint16_t	topo_flags;		/* topology discovery flags */
} fc_rnid_t;

/* RNID get data format flag */
#define	FCIO_CFLAGS_RNID_GET_GENERAL_TOPOLOGY	0xDF
#define	FCIO_CFLAGS_RNID_GET_VENDOR_SPECIFIC	0xE0

/* RNID maximum data length - common data(16) + specific data(252) */
#define	FCIO_RNID_MAX_DATA_LEN	268

/* RNID Payload. */
typedef struct la_els_rnid {
	ls_code_t	ls_code;
	uchar_t		data_format;		/* data format returned */
	uchar_t		resv[3];
} la_els_rnid_t;

/*
 * ELS RNID header
 * - cmn_len can be 0 or 16 - if it is 0 then specific data starts at
 *   offset 8 else specific data starts at offset 24 in the RNID els response
 */
typedef struct fc_rnid_hdr {
	uchar_t		data_format;
	uchar_t		cmn_len;
	uchar_t		resv;
	uchar_t		specific_len;
}fc_rnid_hdr_t;

typedef struct la_els_rnid_acc {
	ls_code_t	ls_code;
	fc_rnid_hdr_t  	hdr;
	uchar_t		data[FCIO_RNID_MAX_DATA_LEN];
} la_els_rnid_acc_t;

#if	!defined(__lint)
_NOTE(SCHEME_PROTECTS_DATA("unique per request", fc_ns_cmd))
_NOTE(SCHEME_PROTECTS_DATA("unique per request", ct_header))
_NOTE(SCHEME_PROTECTS_DATA("unique per request", la_els_logi))
_NOTE(SCHEME_PROTECTS_DATA("unique per request", la_wwn))
_NOTE(SCHEME_PROTECTS_DATA("unique per request", fc_rls_acc_params))
_NOTE(SCHEME_PROTECTS_DATA("unique per request", la_els_rls))
_NOTE(SCHEME_PROTECTS_DATA("unique per request", la_els_rls_acc))
_NOTE(SCHEME_PROTECTS_DATA("unique per request", fc_rnid_params))
_NOTE(SCHEME_PROTECTS_DATA("unique per request", la_els_rnid))
_NOTE(SCHEME_PROTECTS_DATA("unique per request", la_els_rnid_acc))
#endif /* __lint */

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_FIBRE_CHANNEL_FC_APPIF_H */
