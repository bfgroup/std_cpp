#ifndef BFG_STD_CPP_COMMAND_BUILDER_GCC_LIKE_HPP
#define BFG_STD_CPP_COMMAND_BUILDER_GCC_LIKE_HPP

/*
Copyright 2017-2018 Rene Rivera
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
 */

#include "command_builder.hpp"
#include "opt_core.hpp"
#include "inputs.hpp"

namespace bfg_std_cpp {

class command_builder_gcc_like : public command_builder
{
    public:

    command_builder_gcc_like()
    {
        inputs inputs;
        set_processor(inputs, &command_builder_gcc_like::process_inputs);
        options::core core;
        set_processor(core.output, &command_builder_gcc_like::process_output);
        set_processor(core.include_dir, &command_builder_gcc_like::process_include_dir);
        set_processor(core.debug_info, &command_builder_gcc_like::process_debug_info);
        set_processor(core.standard, &command_builder_gcc_like::process_standard);
        set_processor(core.optimize, &command_builder_gcc_like::process_optimize);
        set_processor(core.warnings, &command_builder_gcc_like::process_warnings);
    }

    void process_inputs(void * v) { *this << value<std::string>(v); }
    void process_output(void * v) { *this << "-o" << value<std::string>(v); }
    void process_include_dir(void * v) { *this << "-I" << value<std::string>(v); }
    void process_debug_info(void * v) { if (value<bool>(v)) *this << "-g"; }
    void process_standard(void * v) { *this << "-std=c++"+value<std::string>(v); }
    void process_warnings(void * v)
    {
        std::string warnings = value<std::string>(v);
        if (warnings == "off") *this << "-w";
        else if (warnings == "on") *this << "-Wall";
        else if (warnings == "all") *this << "-Wall" << "-pedantic";
        if (warnings == "error") *this << "-Werror";
    }
    void process_optimize(void * v)
    {
        std::string level = value<std::string>(v);
        if (level == "off") *this << "-O0";
        else if (level == "on") *this << "-O2";
        else if (level == "speed") *this << "-O3";
        else if (level == "size") *this << "-Os";
    }
};

}

#endif
