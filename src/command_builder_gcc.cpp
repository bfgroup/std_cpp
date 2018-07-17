/*
Copyright 2017-2018 Rene Rivera
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
 */

#include "command_builder_gcc_like.hpp"
#include "util.hpp"
#include "opt_vendor_gcc.hpp"

#ifdef BFG_STD_CPP_GCC

namespace bfg_std_cpp {

class command_builder_gcc : public command_builder_gcc_like
{
    public:

    std::string standard;
    std::string cpp_dialect;

    command_builder_gcc()
    {
        this->operator<<(safe_getenv("CXX", "gcc"));

        options::core core;
        set_processor(core.standard, &command_builder_gcc::process_standard);
        options::vendor_gcc vendor_gcc;
        set_processor(vendor_gcc.cpp_dialect, &command_builder_gcc::process_cpp_dialect);
    }

    result process_standard(void * v) { standard = value<std::string>(v); return result::ok_(); }
    result process_cpp_dialect(void * v) { cpp_dialect = value<std::string>(v);return result::ok_(); }

    result post() override
    {
        command_builder_gcc_like::post();
        std::string std_opt = "-std=";
        if (cpp_dialect == "gnu") std_opt += "gnu++";
        else std_opt += "c++";
        if (!standard.empty()) *this << std_opt+standard;
        return result::ok_();
    }
};

std::shared_ptr<command_builder> command_builder::make()
{
    return std::make_shared<command_builder_gcc>();
}

}

#endif
