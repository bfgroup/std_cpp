/*
Copyright 2017-2018 Rene Rivera
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
 */

#include "command_builder_msvc_like.hpp"
#include "util.hpp"

#ifdef BFG_STD_CPP_MSVC

namespace bfg_std_cpp {

class command_builder_msvc : public command_builder_msvc_like
{
    public:

    std::string standard;
    std::string cpp_dialect;

    command_builder_msvc()
    {
        this->operator<<(safe_getenv("CXX", "cl.exe"));
    }
};

std::shared_ptr<command_builder> command_builder::make()
{
    return std::make_shared<command_builder_msvc>();
}

}

#endif
