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

#include <errno.h>
#include <stdlib.h>

#include "ypclnt.h"

int
yp_bind (const char *indomain)
{
  errno = ENOSYS;
  return YPERR_YPERR;
}

void
yp_unbind (const char *indomain)
{
  errno = ENOSYS;
}

int
yp_get_default_domain (char **outdomain)
{
  if (outdomain)
    *outdomain = NULL;

  errno = ENOSYS;
  return YPERR_YPERR;
}

int
__yp_check (char **domain)
{
  if (domain)
    *domain = NULL;

  errno = ENOSYS;
  return 1;
}

int
yp_match (const char *indomain, const char *inmap, const char *inkey,
	  const int inkeylen, char **outval, int *outvallen)
{
  if (outval)
    *outval = NULL;
  if (outvallen)
    *outvallen = 0;

  errno = ENOSYS;
  return YPERR_YPERR;
}

int
yp_first (const char *indomain, const char *inmap, char **outkey,
	  int *outkeylen, char **outval, int *outvallen)
{
  if (outval)
    *outval = NULL;
  if (outvallen)
    *outvallen = 0;

  errno = ENOSYS;
  return YPERR_YPERR;
}

int
yp_next (const char *indomain, const char *inmap, const char *inkey,
	 const int inkeylen, char **outkey, int *outkeylen, char **outval,
	 int *outvallen)
{
  if (outval)
    *outval = NULL;
  if (outvallen)
    *outvallen = 0;

  errno = ENOSYS;
  return YPERR_YPERR;
}

int
yp_master (const char *indomain, const char *inmap, char **outname)
{
  if (outname)
    *outname = 0;

  errno = ENOSYS;
  return YPERR_YPERR;
}

int
yp_order (const char *indomain, const char *inmap, unsigned int *outorder)
{
  if (outorder)
    *outorder = 0;

  errno = ENOSYS;
  return YPERR_YPERR;
}

int
yp_all (const char *indomain, const char *inmap,
	const struct ypall_callback *incallback)
{
  errno = ENOSYS;
  return YPERR_YPERR;
}

typedef char *mapname;
struct ypmaplist {
  mapname map;
  struct ypmaplist *next;
};
typedef struct ypmaplist ypmaplist;

int
yp_maplist (const char *indomain, struct ypmaplist **outmaplist)
{
  if (outmaplist)
    *outmaplist = NULL;

  errno = ENOSYS;
  return YPERR_YPERR;

}

const char *
yperr_string (const int error)
{
  errno = ENOSYS;
  return NULL;
}

int
ypprot_err (const int code)
{
  errno = ENOSYS;
  return YPERR_YPERR;
}

const char *
ypbinderr_string (const int error)
{
  errno = ENOSYS;
  return NULL;
}

int
yp_update (char *domain, char *map, unsigned ypop,
	   char *key, int keylen, char *data, int datalen)
{
  errno = ENOSYS;
  return YPERR_YPERR;
}
