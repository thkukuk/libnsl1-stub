/*
 * Copyright (c) 2010, Oracle America, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials
 *       provided with the distribution.
 *     * Neither the name of the "Oracle America, Inc." nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *   FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *   COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 *   INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 *   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 *   GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __RPCSVC_YP_H__
#define __RPCSVC_YP_H__

#include <stdint.h>

typedef unsigned int u_int;
typedef int32_t bool_t;

#ifndef FALSE
#       define FALSE    (0)
#endif

enum xdr_op {
        XDR_ENCODE=0,
        XDR_DECODE=1,
        XDR_FREE=2
};

typedef struct __rpc_xdr {
        enum xdr_op     x_op;           /* operation; fast additional param */
        const struct xdr_ops {
                /* get a long from underlying stream */
                bool_t  (*x_getlong)(struct __rpc_xdr *, long *);
                /* put a long to " */
                bool_t  (*x_putlong)(struct __rpc_xdr *, const long *);
                /* get some bytes from " */
                bool_t  (*x_getbytes)(struct __rpc_xdr *, char *, u_int);
                /* put some bytes to " */
                bool_t  (*x_putbytes)(struct __rpc_xdr *, const char *, u_int);
                /* returns bytes off from beginning */
                u_int   (*x_getpostn)(struct __rpc_xdr *);
                /* lets you reposition the stream */
                bool_t  (*x_setpostn)(struct __rpc_xdr *, u_int);
                /* buf quick ptr to buffered data */
                int32_t *(*x_inline)(struct __rpc_xdr *, u_int);
                /* free privates of this xdr_stream */
                void    (*x_destroy)(struct __rpc_xdr *);
                bool_t  (*x_control)(struct __rpc_xdr *, int, void *);
        } *x_ops;
        char *          x_public;       /* users' data */
        void *          x_private;      /* pointer to private data */
        char *          x_base;         /* private used for position info */
        u_int           x_handy;        /* extra private word */
} XDR;


#define YPMAXRECORD 1024
#define YPMAXDOMAIN 64
#define YPMAXMAP 64
#define YPMAXPEER 64

enum ypstat {
	YP_TRUE = 1,
	YP_NOMORE = 2,
	YP_FALSE = 0,
	YP_NOMAP = -1,
	YP_NODOM = -2,
	YP_NOKEY = -3,
	YP_BADOP = -4,
	YP_BADDB = -5,
	YP_YPERR = -6,
	YP_BADARGS = -7,
	YP_VERS = -8,
};
typedef enum ypstat ypstat;

enum ypxfrstat {
	YPXFR_SUCC = 1,
	YPXFR_AGE = 2,
	YPXFR_NOMAP = -1,
	YPXFR_NODOM = -2,
	YPXFR_RSRC = -3,
	YPXFR_RPC = -4,
	YPXFR_MADDR = -5,
	YPXFR_YPERR = -6,
	YPXFR_BADARGS = -7,
	YPXFR_DBM = -8,
	YPXFR_FILE = -9,
	YPXFR_SKEW = -10,
	YPXFR_CLEAR = -11,
	YPXFR_FORCE = -12,
	YPXFR_XFRERR = -13,
	YPXFR_REFUSED = -14,
};
typedef enum ypxfrstat ypxfrstat;

typedef char *domainname;
typedef char *mapname;
typedef char *peername;

typedef struct {
  u_int keydat_len;
  char *keydat_val;
} keydat;

typedef struct {
  u_int valdat_len;
  char *valdat_val;
} valdat;

struct ypmap_parms {
  domainname domain;
  mapname map;
  u_int ordernum;
  peername peer;
};
typedef struct ypmap_parms ypmap_parms;

struct ypreq_key {
  domainname domain;
  mapname map;
  keydat key;
};
typedef struct ypreq_key ypreq_key;

struct ypreq_nokey {
  domainname domain;
  mapname map;
};
typedef struct ypreq_nokey ypreq_nokey;

struct ypreq_xfr {
  ypmap_parms map_parms;
  u_int transid;
  u_int prog;
  u_int port;
};
typedef struct ypreq_xfr ypreq_xfr;

struct ypresp_val {
  ypstat stat;
  valdat val;
};
typedef struct ypresp_val ypresp_val;

struct ypresp_key_val {
  ypstat stat;
#ifdef STUPID_SUN_BUG
  /* This is the form as distributed by Sun.  But even the Sun NIS
     servers expect the values in the other order.  So their
     implementation somehow must change the order internally.  We
     don't want to follow this bad example since the user should be
     able to use rpcgen on this file.  */
  keydat key;
  valdat val;
#else
  valdat val;
  keydat key;
#endif
};
typedef struct ypresp_key_val ypresp_key_val;

struct ypresp_master {
  ypstat stat;
  peername peer;
};
typedef struct ypresp_master ypresp_master;

struct ypresp_order {
  ypstat stat;
  u_int ordernum;
};
typedef struct ypresp_order ypresp_order;

struct ypresp_all {
  bool_t more;
  union {
    ypresp_key_val val;
  } ypresp_all_u;
};
typedef struct ypresp_all ypresp_all;

struct ypresp_xfr {
  u_int transid;
  ypxfrstat xfrstat;
};
typedef struct ypresp_xfr ypresp_xfr;

struct ypmaplist {
  mapname map;
  struct ypmaplist *next;
};
typedef struct ypmaplist ypmaplist;

struct ypresp_maplist {
  ypstat stat;
  ypmaplist *maps;
};
typedef struct ypresp_maplist ypresp_maplist;

enum yppush_status {
  YPPUSH_SUCC = 1,
  YPPUSH_AGE = 2,
  YPPUSH_NOMAP = -1,
  YPPUSH_NODOM = -2,
  YPPUSH_RSRC = -3,
  YPPUSH_RPC = -4,
  YPPUSH_MADDR = -5,
  YPPUSH_YPERR = -6,
  YPPUSH_BADARGS = -7,
  YPPUSH_DBM = -8,
  YPPUSH_FILE = -9,
  YPPUSH_SKEW = -10,
  YPPUSH_CLEAR = -11,
  YPPUSH_FORCE = -12,
  YPPUSH_XFRERR = -13,
  YPPUSH_REFUSED = -14,
};
typedef enum yppush_status yppush_status;

struct yppushresp_xfr {
  u_int transid;
  yppush_status status;
};
typedef struct yppushresp_xfr yppushresp_xfr;

enum ypbind_resptype {
  YPBIND_SUCC_VAL = 1,
  YPBIND_FAIL_VAL = 2,
};
typedef enum ypbind_resptype ypbind_resptype;

struct ypbind_binding {
  char ypbind_binding_addr[4];
  char ypbind_binding_port[2];
};
typedef struct ypbind_binding ypbind_binding;

struct ypbind_resp {
  ypbind_resptype ypbind_status;
  union {
    u_int ypbind_error;
    ypbind_binding ypbind_bindinfo;
  } ypbind_resp_u;
};
typedef struct ypbind_resp ypbind_resp;

#define YPBIND_ERR_ERR 1
#define YPBIND_ERR_NOSERV 2
#define YPBIND_ERR_RESC 3

struct ypbind_setdom {
  domainname ypsetdom_domain;
  ypbind_binding ypsetdom_binding;
  u_int ypsetdom_vers;
};
typedef struct ypbind_setdom ypbind_setdom;


typedef struct {
        u_int yp_buf_len;
        char *yp_buf_val;
} yp_buf;

struct ypupdate_args {
        char *mapname;
        yp_buf key;
        yp_buf datum;
};
typedef struct ypupdate_args ypupdate_args;

struct ypdelete_args {
        char *mapname;
        yp_buf key;
};
typedef struct ypdelete_args ypdelete_args;

extern  bool_t xdr_ypstat (XDR *, ypstat*);
extern  bool_t xdr_ypxfrstat (XDR *, ypxfrstat*);
extern  bool_t xdr_domainname (XDR *, domainname*);
extern  bool_t xdr_mapname (XDR *, mapname*);
extern  bool_t xdr_peername (XDR *, peername*);
extern  bool_t xdr_keydat (XDR *, keydat*);
extern  bool_t xdr_valdat (XDR *, valdat*);
extern  bool_t xdr_ypmap_parms (XDR *, ypmap_parms*);
extern  bool_t xdr_ypreq_key (XDR *, ypreq_key*);
extern  bool_t xdr_ypreq_nokey (XDR *, ypreq_nokey*);
extern  bool_t xdr_ypreq_xfr (XDR *, ypreq_xfr*);
extern  bool_t xdr_ypresp_val (XDR *, ypresp_val*);
extern  bool_t xdr_ypresp_key_val (XDR *, ypresp_key_val*);
extern  bool_t xdr_ypresp_master (XDR *, ypresp_master*);
extern  bool_t xdr_ypresp_order (XDR *, ypresp_order*);
extern  bool_t xdr_ypresp_all (XDR *, ypresp_all*);
extern  bool_t xdr_ypresp_xfr (XDR *, ypresp_xfr*);
extern  bool_t xdr_ypmaplist (XDR *, ypmaplist*);
extern  bool_t xdr_ypresp_maplist (XDR *, ypresp_maplist*);
extern  bool_t xdr_yppush_status (XDR *, yppush_status*);
extern  bool_t xdr_yppushresp_xfr (XDR *, yppushresp_xfr*);
extern  bool_t xdr_ypbind_resptype (XDR *, ypbind_resptype*);
extern  bool_t xdr_ypbind_binding (XDR *, ypbind_binding*);
extern  bool_t xdr_ypbind_resp (XDR *, ypbind_resp*);
extern  bool_t xdr_ypbind_setdom (XDR *, ypbind_setdom*);
extern  bool_t xdr_yp_buf (XDR *, yp_buf*);
extern  bool_t xdr_ypupdate_args (XDR *, ypupdate_args*);
extern  bool_t xdr_ypdelete_args (XDR *, ypdelete_args*);

#endif /* !__RPCSVC_YP_H__ */
