/*
Copyright 2017-2018 Rene Rivera
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
 */

#include "command_builder.hpp"
#include "opt_core.hpp"

namespace bfg_std_cpp {

std::type_index command_builder::opt_index(opt_type const & o)
{
    return o.index();
}

}
