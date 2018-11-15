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

[subs=normal]
....
{lopt}gcc:cppdialect=__cpp_dialect__
....

[horizontal]
Vendor:: gcc
Argument:: One of: `iso`, `gnu`.
Effect:: Instructs compilation to use the given _cpp_dialect_ of
    the C++ language standard for the source TU.
Compatibility:: Link incompatible.

*/ // end::std_cpp_vendor_gcc[]
    cpp_dialect.hint("cpp_dialect")
        ["--gcc:cppdialect"]
        ("Specify that the input sources are for <cpp_dialect>.")
        >> cli;

/* tag::std_cpp_vendor_gcc[]

= External options

[subs=normal]
....
{lopt}gcc:options=__file__
....

[horizontal]
Vendor:: gcc
Argument:: Path to a platform dependent file.
Effect:: Reads additional options from the given _file_.
Compatibility:: NA

*/ // end::std_cpp_vendor_gcc[]
    options.hint("file")
        ["--gcc:options"]
        ("Read additional options from <file>.")
        >> cli;
}

}}

#endif
