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

#include <errno.h>

#include "yp.h"
#include "ypclnt.h"

bool_t
xdr_ypstat (XDR *xdrs, ypstat *objp)
{
  return FALSE;
}

bool_t
xdr_ypxfrstat (XDR *xdrs, ypxfrstat *objp)
{
  return FALSE;
}

bool_t
xdr_domainname (XDR *xdrs, domainname *objp)
{
  return FALSE;
}

bool_t
xdr_mapname (XDR *xdrs, mapname *objp)
{
  return FALSE;
}

bool_t
xdr_peername (XDR *xdrs, peername *objp)
{
  return FALSE;
}

bool_t
xdr_keydat (XDR *xdrs, keydat *objp)
{
  return FALSE;
}

bool_t
xdr_valdat (XDR *xdrs, valdat *objp)
{
  return FALSE;
}

bool_t
xdr_ypmap_parms (XDR *xdrs, ypmap_parms *objp)
{
  return FALSE;
}

bool_t
xdr_ypreq_key (XDR *xdrs, ypreq_key *objp)
{
  return FALSE;
}

bool_t
xdr_ypreq_nokey (XDR *xdrs, ypreq_nokey *objp)
{
  return FALSE;
}

bool_t
xdr_ypreq_xfr (XDR *xdrs, ypreq_xfr *objp)
{
  return FALSE;
}

bool_t
xdr_ypresp_val (XDR *xdrs, ypresp_val *objp)
{
  return FALSE;
}

bool_t
xdr_ypresp_key_val (XDR *xdrs, ypresp_key_val *objp)
{
  return FALSE;
}

bool_t
xdr_ypresp_master (XDR *xdrs, ypresp_master *objp)
{
  return FALSE;
}

bool_t
xdr_ypresp_order (XDR *xdrs, ypresp_order *objp)
{
  return FALSE;
}

bool_t
xdr_ypresp_all (XDR *xdrs, ypresp_all *objp)
{
  return FALSE;
}

bool_t
xdr_ypresp_xfr (XDR *xdrs, ypresp_xfr *objp)
{
  return FALSE;
}

bool_t
xdr_ypmaplist (XDR *xdrs, ypmaplist *objp)
{
  return FALSE;
}

bool_t
xdr_ypresp_maplist (XDR *xdrs, ypresp_maplist *objp)
{
  return FALSE;
}

bool_t
xdr_yppush_status (XDR *xdrs, yppush_status *objp)
{
  return FALSE;
}

bool_t
xdr_yppushresp_xfr (XDR *xdrs, yppushresp_xfr *objp)
{
  return FALSE;
}

bool_t
xdr_ypbind_resptype (XDR *xdrs, ypbind_resptype *objp)
{
  return FALSE;
}

bool_t
xdr_ypbind_binding (XDR *xdrs, ypbind_binding *objp)
{
  return FALSE;
}

bool_t
xdr_ypbind_resp (XDR *xdrs, ypbind_resp *objp)
{
  return FALSE;
}

bool_t
xdr_ypbind_setdom (XDR *xdrs, ypbind_setdom *objp)
{
  return FALSE;
}

bool_t
xdr_ypall(XDR *xdrs, struct ypall_callback *incallback)
{
  return FALSE;
}

bool_t
xdr_yp_buf (XDR *xdrs, yp_buf *objp)
{
  return FALSE;
}

bool_t
xdr_ypupdate_args (XDR *xdrs, ypupdate_args *objp)
{
  return FALSE;
}

bool_t
xdr_ypdelete_args (XDR *xdrs, ypdelete_args *objp)
{
  return FALSE;
}
