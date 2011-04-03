/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License, Version 1.0 only
 * (the "License").  You may not use this file except in compliance
 * with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
/*
 * Copyright (c) 1998-2001 by Sun Microsystems, Inc.
 * All rights reserved.
 */

#pragma ident	"%Z%%M%	%I%	%E% SMI"

#include "libctf/ctf_impl.h"
#include "common/utils.h"

/*LINTLIBRARY*/

static const char *pname;

#pragma init(getpname)
const char *
getpname(void)
{
	const char *p, *q;

	if (pname != NULL)
		return (pname);

#if HAVE_GETEXECNAME
	p = getexecname();
#elif HAVE_GETPROGNAME
	p = getprogname();
#else
# error dont know how to find my executable name
#endif

	if (p != NULL)
		q = strrchr(p, '/');
	else
		q = NULL;

	if (q == NULL)
		pname = p;
	else
		pname = q + 1;

	return (pname);
}

void
vwarn(const char *format, va_list alist)
{
	int err = errno;

	if (pname != NULL)
		(void) fprintf(stderr, "%s: ", pname);

	(void) vfprintf(stderr, format, alist);

	if (strchr(format, '\n') == NULL)
		(void) fprintf(stderr, ": %s\n", strerror(err));
}

/*PRINTFLIKE1*/
void
warn(const char *format, ...)
{
	va_list alist;

	va_start(alist, format);
	vwarn(format, alist);
	va_end(alist);
}

void
vdie(const char *format, va_list alist)
{
	vwarn(format, alist);
	exit(E_ERROR);
}

/*PRINTFLIKE1*/
void
die(const char *format, ...)
{
	va_list alist;

	va_start(alist, format);
	vdie(format, alist);
	va_end(alist);
}
