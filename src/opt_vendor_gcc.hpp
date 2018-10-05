#ifndef BFG_STD_CPP_OPT_VENDOR_GCC_HPP
#define BFG_STD_CPP_OPT_VENDOR_GCC_HPP

/*
Copyright 2017-2018 Rene Rivera
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
 */

#ifdef BFG_STD_CPP_GCC

#include "cli.hpp"
#include "opt.hpp"

namespace bfg_std_cpp { namespace options {

struct vendor_gcc
{
    opt_string<struct vendor_gcc_cpp_dialect_key> cpp_dialect;
    opt_strings<struct vendor_gcc_options_key> options;
    opt_strings<struct vendor_gcc_library_dir_key> library_dir;

    vendor_gcc();
    vendor_gcc(cli & cli);
};

} }

#endif

#endif
