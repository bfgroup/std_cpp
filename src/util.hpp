#ifndef BFG_STD_CPP_UTIL_HPP
#define BFG_STD_CPP_UTIL_HPP

/*
Copyright 2017-2018 Rene Rivera
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
 */

#include <cstdlib>
#include <string>

namespace bfg_std_cpp {

std::string safe_getenv(std::string const & name, std::string const & default_val = "")
{
    const char * from_env = std::getenv(name.c_str());
    std::string result = from_env ? from_env : "";
    if (result.empty()) result = default_val;
    return result;
}

}

#endif
