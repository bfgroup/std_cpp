#ifndef BFG_STD_CPP_UTIL_HPP
#define BFG_STD_CPP_UTIL_HPP

/*
Copyright 2017-2018 Rene Rivera
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
 */

#include <string>
#include <vector>

namespace bfg_std_cpp {

std::string safe_getenv(std::string const & name, std::string const & default_val = "");

int exec_command(std::vector<std::string> const & command);

}

#endif
