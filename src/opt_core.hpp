#ifndef BFG_STD_CPP_OPT_CORE_HPP
#define BFG_STD_CPP_OPT_CORE_HPP

/*
Copyright 2017-2018 Rene Rivera
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
 */

#include "cli.hpp"
#include "opt.hpp"

namespace bfg_std_cpp { namespace options {

struct core
{
    /////////////////////////////////////////////////////////////////////////////

    opt_flag<struct help_key> help;

    /////////////////////////////////////////////////////////////////////////////

    opt_string<struct output_key> output;
    opt_strings<struct include_dir_key> include_dir;

    /////////////////////////////////////////////////////////////////////////////

    opt_flag<struct debug_info_key> debug_info;

    /////////////////////////////////////////////////////////////////////////////

    opt_string<struct standard_key> standard;

    core();
    core(cli & cli);
};

} }

#endif
