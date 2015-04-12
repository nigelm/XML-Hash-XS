#ifndef _XH_CONFIG_H_
#define _XH_CONFIG_H_

#include "EXTERN.h"
#include "perl.h"
#define NO_XSLOCKS
#include "XSUB.h"
#define NEED_newRV_noinc
#define NEED_newSVpvn_flags
#define NEED_sv_2pv_flags_GLOBAL
#include "ppport.h"
#include <stdint.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#ifdef WIN32
#include <windows.h>
#include <io.h>
#else
#include <sys/mman.h>
#endif

#ifndef MUTABLE_PTR
#if defined(__GNUC__) && !defined(PERL_GCC_BRACE_GROUPS_FORBIDDEN)
#  define MUTABLE_PTR(p) ({ void *_p = (p); _p; })
#else
#  define MUTABLE_PTR(p) ((void *) (p))
#endif
#endif

#ifndef MUTABLE_SV
#define MUTABLE_SV(p)   ((SV *)MUTABLE_PTR(p))
#endif

#if __GNUC__ >= 3
# define expect(expr,value)         __builtin_expect ((expr), (value))
# define XH_INLINE                  static inline
#else
# define expect(expr,value)         (expr)
# define XH_INLINE                  static
#endif

#define expect_false(expr) expect ((expr) != 0, 0)
#define expect_true(expr)  expect ((expr) != 0, 1)

typedef uintptr_t xh_bool_t;
typedef uintptr_t xh_uint_t;
typedef intptr_t  xh_int_t;
typedef u_char    xh_char_t;

#define XH_CHAR_CAST    (xh_char_t *)
#define XH_EMPTY_STRING (XH_CHAR_CAST "")

#if defined(XH_HAVE_ICONV) || defined(XH_HAVE_ICU)
#define XH_HAVE_ENCODER
#endif

#if defined(XH_HAVE_XML2) && defined(XH_HAVE_XML__LIBXML)
#define XH_HAVE_DOM
#endif

#ifdef XH_HAVE_DOM
#include <libxml/parser.h>
#endif

#define XH_HAVE_MMAP

#endif /* _XH_CONFIG_H_ */