/*
 Copyright 2018 Rene Rivera
 Distributed under the Boost Software License, Version 1.0.
 (See accompanying file LICENSE_1_0.txt or copy at
 http://www.boost.org/LICENSE_1_0.txt)
 */

#include "opt_core.hpp"

namespace bfg_std_cpp { namespace options {

core::core() {}

core::core(cli & cli)
{
    /////////////////////////////////////////////////////////////////////////////

    help.flag()
        ["-?"]["-h"]["--help"]
        ("Show usage.")
        >> cli;

    /////////////////////////////////////////////////////////////////////////////

    output.hint("file")
        ["-o"]["--output"]
        ("Write output to <file>.")
        >> cli;

    include_dir.hint("directory")
        ["-I"]["--include-dir"]
        ("Add <directory> to the main include path of the preprocessor.")
        >> cli;

    /////////////////////////////////////////////////////////////////////////////

    debug_info.flag()
        ["-g"]["--debug"]
        ("Generate source-level debug information.")
        >> cli;

    /////////////////////////////////////////////////////////////////////////////

    standard.hint("standard")
        ["-std"]["--standard"]
        ("Specify that the input sources are for <standard>.")
        >> cli;
}

} }
