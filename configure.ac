# configure.in for CIL           -*- sh -*-
# Process this file with autoconf to produce a configure script.

# Autoconf runs this through the M4 macroprocessor first; lines
# starting with "dnl" are comments to M4.  The result is a bash
# script; any text which isn't an M4/autoconf directive gets
# copied verbatim to that script.

# also, in general, watch out: the M4 quoting charactes are
# the square brackets: [ and ].  if you want to pass brackets
# to something, you can quote the brackets with more brackets.
# I don't know how to pass a single (unbalanced) bracket ..

# sm: changed this file to use '#' for comments, since that's
# just as good (since this becomes an 'sh' script)




# -------------- usual initial stuff -------------
# this simply names a file somewhere in the source tree to verify
# we're in the right directory
AC_INIT
AC_CONFIG_SRCDIR([src/cil.mli])
AC_CONFIG_HEADERS(config.h)
AC_CONFIG_FILES([stamp-h], [echo timestamp > stamp-h])

# sm: require a late-enough autoconf; this is the version number
# that's on manju, so I assume it's ok
AC_PREREQ([2.69])

#
# Assign here the CIL version numbers
CIL_VERSION_MAJOR=1
CIL_VERSION_MINOR=7
CIL_VERSION_REV=3
CIL_VERSION=$CIL_VERSION_MAJOR.$CIL_VERSION_MINOR.$CIL_VERSION_REV

# make sure I haven't forgotten to run autoconf
if test configure -ot configure.in; then
  AC_MSG_ERROR(configure is older than configure.in; you forgot to run autoconf)
fi

# check for C compiler; this typically finds gcc; it sets the
# variable CC to whatever it finds, which then gets substituted
# for @CC@ in output files; you have to do this even if you don't
# care about @CC@, because system feature tests later on in
# the ./configure script will expect $CC to be set right
AC_PROG_CC

AC_PROG_INSTALL

# find system type (using this macro means we must include
# the files install-sh, config.sub, and config.guess (all from
# the autoconf distribution) in our source tree!)
AC_CANONICAL_TARGET

# Check if executables should end with .exe (windows)
AC_EXEEXT


# -------------- portable configuration ----------------

DEFAULT_COMPILER=_GNUCC
DEFAULT_CIL_MODE=GNUCC

# is the microsoft compiler available?
# hmm.. I think we should check the version or something, because
# sometimes people have Common Lisp's interpreter called 'cl' ..
AC_MSG_CHECKING(for msvc cl.exe (optional))
# See if CC points to the MS compiler
if "$CC" 2>&1 | grep "Microsoft" >/dev/null; then
  AC_MSG_RESULT([found, set as default])
  HAS_MSVC=yes
  DEFAULT_COMPILER=_MSVC
  DEFAULT_CIL_MODE=MSVC
  CFLAGS="-WX"
else
  if cl 2>&1 | grep "Microsoft" >/dev/null ;then
     AC_MSG_RESULT(found)
     HAS_MSVC=yes
  else
     AC_MSG_RESULT(not found)
     HAS_MSVC=no
  fi
fi

# ------------------- OCaml ----------------

AC_PROG_OCAML
if test "$OCAMLC" = "no"; then
  AC_MSG_ERROR([You must install the OCaml compiler])
fi

if test "$OCAMLBUILD" = "no"; then
  AC_MSG_ERROR([You must install ocamlbuild])
fi

AC_PROG_OCAMLLEX
if test "$OCAMLLEX" = "no"; then
  AC_MSG_ERROR([You must install ocamllex])
fi

AC_PROG_OCAMLYACC
if test "$OCAMLYACC" = "no"; then
  AC_MSG_ERROR([You must install ocamlyacc])
fi

AC_PROG_FINDLIB
if test "$OCAMLFIND" = "no"; then
  AC_MSG_ERROR([You must install OCaml findlib (the ocamlfind command)])
fi

# ------------------- Perl ----------------

AC_CHECK_TOOL([PERL],[perl],[no])
if test "$PERL" = "no"; then
  AC_MSG_ERROR([You must install perl])
fi

# ------------------- Cygpath -------------

AC_CHECK_PROG([CYGPATH],[cygpath],[cygpath])

#
# -------------------- GCC --------------
#

AC_MSG_CHECKING([for gcc version])
AC_CHECK_TYPE(__builtin_va_list,
              HAVE_BUILTIN_VA_LIST=true,
              HAVE_BUILTIN_VA_LIST=false)
# When testing for float types, we really care about whether
# they are defined as builtins by the compiler, not as typedefs
# by the standard headers. So we substitute INCLUDES with -nostdinc
AC_CHECK_TYPE([short float],
              HAVE_SHORT_FLOAT=1,
              HAVE_SHORT_FLOAT=0)
AC_CHECK_TYPE(__float128,
              HAVE___FLOAT128=1,
              HAVE___FLOAT128=0)
AC_CHECK_TYPE(_Float128,
              HAVE_FLOAT128=1,
              HAVE_FLOAT128=0,[[]])
AC_CHECK_TYPE(_Float128x,
              HAVE_FLOAT128X=1,
              HAVE_FLOAT128X=0,[[]])
AC_CHECK_TYPE(_Float64,
              HAVE_FLOAT64=1,
              HAVE_FLOAT64=0,[[]])
AC_CHECK_TYPE(_Float64x,
              HAVE_FLOAT64X=1,
              HAVE_FLOAT64X=0,[[]])
AC_CHECK_TYPE(_Float32,
              HAVE_FLOAT32=1,
              HAVE_FLOAT32=0,[[]])
AC_CHECK_TYPE(_Float32x,
              HAVE_FLOAT32X=1,
              HAVE_FLOAT32X=0,[[]])
AC_CHECK_TYPE(_Float16,
              HAVE_FLOAT16=1,
              HAVE_FLOAT16=0,[[]])
AC_CHECK_TYPE(_Float16x,
              HAVE_FLOAT16X=1,
              HAVE_FLOAT16X=0,[[]])
AC_CHECK_TYPE([short float _Complex],
              HAVE_SHORT_FLOAT_COMPLEX=1,
              HAVE_SHORT_FLOAT_COMPLEX=0,[[]])
AC_CHECK_TYPE([_Float128 _Complex],
              HAVE_FLOAT128_COMPLEX=1,
              HAVE_FLOAT128_COMPLEX=0,[[]])
AC_CHECK_TYPE([_Float128x _Complex],
              HAVE_FLOAT128X_COMPLEX=1,
              HAVE_FLOAT128X_COMPLEX=0,[[]])
AC_CHECK_TYPE([_Float64 _Complex],
              HAVE_FLOAT64_COMPLEX=1,
              HAVE_FLOAT64_COMPLEX=0,[[]])
AC_CHECK_TYPE([_Float64x _Complex],
              HAVE_FLOAT64X_COMPLEX=1,
              HAVE_FLOAT64X_COMPLEX=0,[[]])
AC_CHECK_TYPE([_Float32 _Complex],
              HAVE_FLOAT32_COMPLEX=1,
              HAVE_FLOAT32_COMPLEX=0,[[]])
AC_CHECK_TYPE([_Float32x _Complex],
              HAVE_FLOAT32X_COMPLEX=1,
              HAVE_FLOAT32X_COMPLEX=0,[[]])
AC_CHECK_TYPE([_Float16 _Complex],
              HAVE_FLOAT16_COMPLEX=1,
              HAVE_FLOAT16_COMPLEX=0,[[]])
AC_CHECK_TYPE([_Float16x _Complex],
              HAVE_FLOAT16X_COMPLEX=1,
              HAVE_FLOAT16X_COMPLEX=0,[[]])
AC_MSG_CHECKING([if __thread is a keyword])
AC_COMPILE_IFELSE([AC_LANG_SOURCE([int main(int __thread) { return 0; }])],
                  THREAD_IS_KEYWORD=false,
                  THREAD_IS_KEYWORD=true)
AC_MSG_RESULT($THREAD_IS_KEYWORD)

# Does gcc add underscores to identifiers to make assembly labels?
# (I think MSVC always does)
AC_MSG_CHECKING([if gcc adds underscores to assembly labels.])
AC_LINK_IFELSE([AC_LANG_SOURCE([int main() { __asm__("jmp _main"); }])],
                  UNDERSCORE_NAME=true,
                  UNDERSCORE_NAME=false)
AC_MSG_RESULT($UNDERSCORE_NAME)


# ----------- some stuff 'autoscan' put here --------------
# (autoscan is part of the autoconf distribution)

# checks for header files
AC_HEADER_STDC
AC_CHECK_HEADERS(stdlib.h strings.h sys/time.h unistd.h wchar.h stdbool.h)

# checks for typedefs, structures, and compiler characteristics
AC_C_CONST
AC_C_INLINE
AC_HEADER_TIME
AC_TYPE_INTPTR_T

# checks for library functions; more autoscan stuff
AC_FUNC_MEMCMP
AC_CHECK_FUNCS(mkdir select socket __sysv_signal)

# Find out the true definitions of some integer types
CIL_CHECK_INTEGER_TYPE(size_t, TYPE_SIZE_T)
CIL_CHECK_INTEGER_TYPE(wchar_t, TYPE_WCHAR_T)

# ----------------- finish up -------------------
# names of the variables that get substituted in files; for example,
# write @CIL_VERSION@ somewhere in a written file to get it substituted
AC_SUBST(EMUL)
AC_SUBST(HAS_MSVC)
AC_SUBST(DEFAULT_COMPILER)
AC_SUBST(DEFAULT_CIL_MODE)
AC_SUBST(CIL_VERSION_MAJOR)
AC_SUBST(CIL_VERSION_MINOR)
AC_SUBST(CIL_VERSION_REV)
AC_SUBST(CIL_VERSION)
AC_SUBST(HAVE_BUILTIN_VA_LIST)
AC_SUBST(HAVE_SHORT_FLOAT)
AC_SUBST(HAVE___FLOAT128)
AC_SUBST(HAVE_FLOAT128)
AC_SUBST(HAVE_FLOAT128X)
AC_SUBST(HAVE_FLOAT64)
AC_SUBST(HAVE_FLOAT64X)
AC_SUBST(HAVE_FLOAT32)
AC_SUBST(HAVE_FLOAT32X)
AC_SUBST(HAVE_FLOAT16)
AC_SUBST(HAVE_FLOAT16X)
AC_SUBST(HAVE_SHORT_FLOAT_COMPLEX)
AC_SUBST(HAVE_FLOAT128_COMPLEX)
AC_SUBST(HAVE_FLOAT128X_COMPLEX)
AC_SUBST(HAVE_FLOAT64_COMPLEX)
AC_SUBST(HAVE_FLOAT64X_COMPLEX)
AC_SUBST(HAVE_FLOAT32_COMPLEX)
AC_SUBST(HAVE_FLOAT32X_COMPLEX)
AC_SUBST(HAVE_FLOAT16_COMPLEX)
AC_SUBST(HAVE_FLOAT16X_COMPLEX)
AC_SUBST(THREAD_IS_KEYWORD)
AC_SUBST(UNDERSCORE_NAME)

# finish the configure script and generate various files; ./configure
# will apply variable substitutions to <filename>.in to generate <filename>;

CIL_CONFIG_FILES(Makefile)
CIL_CONFIG_FILES(META)
CIL_CONFIG_FILES(config.mk)
CIL_CONFIG_FILES(test/Makefile)
CIL_CONFIG_FILES(lib/perl5/App/Cilly/CilConfig.pm)
CIL_CONFIG_FILES(doc/index.html)
CIL_CONFIG_FILES(doc/header.html)
CIL_CONFIG_FILES(src/machdep-ml.c)
CIL_CONFIG_FILES(src/cilversion.ml)

AC_OUTPUT

# show the user what the variables have been set to
cat <<EOF

CIL configuration:
  (optional) cl.exe found:    HAS_MSVC           $HAS_MSVC
  gcc to use                  CC                 $CC
  default compiler            DEFAULT_COMPILER   $DEFAULT_COMPILER
  CIL version                 CIL_VERSION        $CIL_VERSION
  Native OCaml CIL libs                          $OCAMLNATDYNLINK
EOF
