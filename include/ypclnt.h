/* Copyright (C) 1996-2025 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */


#ifndef	__RPCSVC_YPCLNT_H__
#define	__RPCSVC_YPCLNT_H__

#define YPERR_YPERR     6               /* Internal yp server or client error */

/* struct ypall_callback * is the arg which must be passed to yp_all.  */
struct ypall_callback
  {
    int (*foreach) (int __status, char *__key, int __keylen,
                    char *__val, int __vallen, char *__data);
    char *data;
  };

/* External NIS client function references.  */
extern int yp_bind (const char *);
extern void yp_unbind (const char *);
extern int yp_get_default_domain (char **);
extern int yp_match (const char *, const char *, const char *,
		     const int, char **, int *);
extern int yp_first (const char *, const char *, char **,
		     int *, char **, int *);
extern int yp_next (const char *, const char *, const char *,
		    const int, char **, int *, char **, int *);
extern int yp_master (const char *, const char *, char **);
extern int yp_order (const char *, const char *, unsigned int *);
extern int yp_all (const char *, const char *,
		   const struct ypall_callback *);
extern const char *yperr_string (const int);
extern const char *ypbinderr_string (const int);
extern int ypprot_err (const int);
extern int yp_update (char *, char *, unsigned int,  char *,
		      int, char *, int);

/* This functions exists only under BSD and Linux systems.  */
extern int __yp_check (char **);

#endif	/* __RPCSVC_YPCLNT_H__ */
