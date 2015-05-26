/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _NISPASSWD_H_RPCGEN
#define	_NISPASSWD_H_RPCGEN

#include <rpc/rpc.h>
#ifndef _KERNEL
#include <synch.h>
#include <thread.h>
#endif /* !_KERNEL */

#ifdef __cplusplus
extern "C" {
#endif

#include <limits.h>

enum nispasswd_status {
	NPD_SUCCESS = 0,
	NPD_TRYAGAIN = 1,
	NPD_PARTIALSUCCESS = 2,
	NPD_FAILED = 3
};
typedef enum nispasswd_status nispasswd_status;

enum nispasswd_code {
	NPD_NOTMASTER = 0,
	NPD_NOSUCHENTRY = 1,
	NPD_IDENTINVALID = 2,
	NPD_NOPASSWD = 3,
	NPD_NOSHDWINFO = 4,
	NPD_SHDWCORRUPT = 5,
	NPD_NOTAGED = 6,
	NPD_CKGENFAILED = 7,
	NPD_VERFINVALID = 8,
	NPD_PASSINVALID = 9,
	NPD_ENCRYPTFAIL = 10,
	NPD_DECRYPTFAIL = 11,
	NPD_KEYSUPDATED = 12,
	NPD_KEYNOTREENC = 13,
	NPD_PERMDENIED = 14,
	NPD_SRVNOTRESP = 15,
	NPD_NISERROR = 16,
	NPD_SYSTEMERR = 17,
	NPD_BUFTOOSMALL = 18,
	NPD_INVALIDARGS = 19,
	NPD_PROGVERSMISMATCH = 20
};
typedef enum nispasswd_code nispasswd_code;

enum nispasswd_field {
	NPD_PASSWD = 0,
	NPD_GECOS = 1,
	NPD_SHELL = 2,
	NPD_SECRETKEY = 3
};
typedef enum nispasswd_field nispasswd_field;

struct nispasswd_error {
	nispasswd_field npd_field;
	nispasswd_code npd_code;
	struct nispasswd_error *next;
};
typedef struct nispasswd_error nispasswd_error;

struct passwd_info {
	char *pw_gecos;
	char *pw_shell;
};
typedef struct passwd_info passwd_info;

struct npd_request {
	char *username;
	char *domain;
	char *key_type;
	struct {
		u_int user_pub_key_len;
		u_char *user_pub_key_val;
	} user_pub_key;
	struct {
		u_int npd_authpass_len;
		u_char *npd_authpass_val;
	} npd_authpass;
	u_int ident;
};
typedef struct npd_request npd_request;
#define	__NPD_MAXPASSBYTES 12

typedef char passbuf[__NPD_MAXPASSBYTES];

struct npd_newpass {
	u_int npd_xrandval;
	passbuf pass;
};
typedef struct npd_newpass npd_newpass;

struct npd_update {
	u_int ident;
	npd_newpass xnewpass;
	passwd_info pass_info;
};
typedef struct npd_update npd_update;
#define DESCREDPASSLEN sizeof (des_block)
#define	__NPD2_MAXPASSBYTES 256

struct npd_newpass2 {
	u_int npd_xrandval;
	char pass[__NPD2_MAXPASSBYTES];
	u_int npd_pad;
};
typedef struct npd_newpass2 npd_newpass2;

struct npd_update2 {
	u_int ident;
	npd_newpass2 xnewpass;
	passwd_info pass_info;
};
typedef struct npd_update2 npd_update2;

struct nispasswd_verf {
	u_int npd_xid;
	u_int npd_xrandval;
};
typedef struct nispasswd_verf nispasswd_verf;

struct nispasswd_authresult {
	nispasswd_status status;
	union {
		nispasswd_verf npd_verf;
		nispasswd_code npd_err;
	} nispasswd_authresult_u;
};
typedef struct nispasswd_authresult nispasswd_authresult;

struct nispasswd_updresult {
	nispasswd_status status;
	union {
		nispasswd_error reason;
		nispasswd_code npd_err;
	} nispasswd_updresult_u;
};
typedef struct nispasswd_updresult nispasswd_updresult;

#define	NISPASSWD_PROG	100303
#define	NISPASSWD_VERS	1

#if defined(__STDC__) || defined(__cplusplus)
#define	NISPASSWD_AUTHENTICATE	1
extern  enum clnt_stat nispasswd_authenticate_1(npd_request *, nispasswd_authresult *, CLIENT *);
extern  bool_t nispasswd_authenticate_1_svc(npd_request *, nispasswd_authresult *, struct svc_req *);
#define	NISPASSWD_UPDATE	2
extern  enum clnt_stat nispasswd_update_1(npd_update *, nispasswd_updresult *, CLIENT *);
extern  bool_t nispasswd_update_1_svc(npd_update *, nispasswd_updresult *, struct svc_req *);
extern int nispasswd_prog_1_freeresult(SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define	NISPASSWD_AUTHENTICATE	1
extern  enum clnt_stat nispasswd_authenticate_1();
extern  bool_t nispasswd_authenticate_1_svc();
#define	NISPASSWD_UPDATE	2
extern  enum clnt_stat nispasswd_update_1();
extern  bool_t nispasswd_update_1_svc();
extern int nispasswd_prog_1_freeresult();
#endif /* K&R C */
#define	NISPASSWD_VERS2	2

#if defined(__STDC__) || defined(__cplusplus)
extern  enum clnt_stat nispasswd_authenticate_2(npd_request *, nispasswd_authresult *, CLIENT *);
extern  bool_t nispasswd_authenticate_2_svc(npd_request *, nispasswd_authresult *, struct svc_req *);
extern  enum clnt_stat nispasswd_update_2(npd_update2 *, nispasswd_updresult *, CLIENT *);
extern  bool_t nispasswd_update_2_svc(npd_update2 *, nispasswd_updresult *, struct svc_req *);
extern int nispasswd_prog_2_freeresult(SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
extern  enum clnt_stat nispasswd_authenticate_2();
extern  bool_t nispasswd_authenticate_2_svc();
extern  enum clnt_stat nispasswd_update_2();
extern  bool_t nispasswd_update_2_svc();
extern int nispasswd_prog_2_freeresult();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_nispasswd_status(XDR *, nispasswd_status*);
extern  bool_t xdr_nispasswd_code(XDR *, nispasswd_code*);
extern  bool_t xdr_nispasswd_field(XDR *, nispasswd_field*);
extern  bool_t xdr_nispasswd_error(XDR *, nispasswd_error*);
extern  bool_t xdr_passwd_info(XDR *, passwd_info*);
extern  bool_t xdr_npd_request(XDR *, npd_request*);
extern  bool_t xdr_passbuf(XDR *, passbuf);
extern  bool_t xdr_npd_newpass(XDR *, npd_newpass*);
extern  bool_t xdr_npd_update(XDR *, npd_update*);
extern  bool_t xdr_npd_newpass2(XDR *, npd_newpass2*);
extern  bool_t xdr_npd_update2(XDR *, npd_update2*);
extern  bool_t xdr_nispasswd_verf(XDR *, nispasswd_verf*);
extern  bool_t xdr_nispasswd_authresult(XDR *, nispasswd_authresult*);
extern  bool_t xdr_nispasswd_updresult(XDR *, nispasswd_updresult*);

#else /* K&R C */
extern bool_t xdr_nispasswd_status();
extern bool_t xdr_nispasswd_code();
extern bool_t xdr_nispasswd_field();
extern bool_t xdr_nispasswd_error();
extern bool_t xdr_passwd_info();
extern bool_t xdr_npd_request();
extern bool_t xdr_passbuf();
extern bool_t xdr_npd_newpass();
extern bool_t xdr_npd_update();
extern bool_t xdr_npd_newpass2();
extern bool_t xdr_npd_update2();
extern bool_t xdr_nispasswd_verf();
extern bool_t xdr_nispasswd_authresult();
extern bool_t xdr_nispasswd_updresult();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_NISPASSWD_H_RPCGEN */
