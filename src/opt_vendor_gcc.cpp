/*
 Copyright 2018 Rene Rivera
 Distributed under the Boost Software License, Version 1.0.
 (See accompanying file LICENSE_1_0.txt or copy at
 http://www.boost.org/LICENSE_1_0.txt)
 */

#include "opt_vendor_gcc.hpp"

#ifdef BFG_STD_CPP_GCC

namespace bfg_std_cpp { namespace options {

vendor_gcc::vendor_gcc() {}

vendor_gcc::vendor_gcc(cli & cli)
{
/* tag::std_cpp_vendor_gcc[]

= C++ dialect

[subs=+macros]
....
pass:q[++v:gcc:cppdialect=_cpp_dialect_]
....

[horizontal]
Vendor:: gcc
Argument:: One of: `iso`, `gnu`.
Effect:: Instructs compilation to use the given _cpp_dialect_ of
    the C++ language standard for the source TU.
Compatibility:: Link incompatible between _cpp_dialect_ values.

*/ // end::std_cpp_vendor_gcc[]
    cpp_dialect.hint("cpp_dialect")
        ["--v:gcc:cppdialect"]
        ("Specify that the input sources are for <cpp_dialect>.")
        >> cli;
}

}}

#endif
