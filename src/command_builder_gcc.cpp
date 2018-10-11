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

    bool standard_option_added = false;
    std::string standard;
    std::string cpp_dialect = "c++";

    command_builder_gcc()
    {
        this->operator<<(safe_getenv("CXX", "gcc"));

        options::core core;
        set_processor(core.standard, &command_builder_gcc::process_standard);
        options::vendor_gcc vendor_gcc;
        set_processor(vendor_gcc.cpp_dialect, &command_builder_gcc::process_cpp_dialect);
        set_processor(vendor_gcc.options, &command_builder_gcc::process_options);
    }

    result process_standard(void * v)
    {
        standard = value<std::string>(v);
        if (!standard_option_added)
        {
            standard_option_added = true;
            *this << [this](std::vector<std::string>& arguments) -> void {
                if (!this->standard.empty())
                {
                    std::string std_opt = "-std=";
                    if (this->cpp_dialect == "gnu") std_opt += "gnu++";
                    else std_opt += "c++";
                    arguments.emplace_back(std_opt+this->standard);
                }
            };
        }
        return result::ok_();
    }
    result process_cpp_dialect(void * v) { cpp_dialect = value<std::string>(v);return result::ok_(); }
    result process_options(void * v) { *this << "@"+value<std::string>(v); return result::ok_(); }
};

std::shared_ptr<command_builder> command_builder::make()
{
    return std::make_shared<command_builder_gcc>();
}

}

#endif
