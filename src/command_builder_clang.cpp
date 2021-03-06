/*
Copyright 2017-2018 Rene Rivera
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
 */

#include "command_builder_gcc_like.hpp"
#include "util.hpp"


namespace bfg_std_cpp {

class command_builder_clang : public command_builder_gcc_like
{
    public:

    command_builder_clang()
    {
        this->operator<<(safe_getenv("CXX", "clang"));
    }
};

#ifdef BFG_STD_CPP_CLANG
std::shared_ptr<command_builder> command_builder::make()
{
    return std::make_shared<command_builder_clang>();
}
#endif

}
