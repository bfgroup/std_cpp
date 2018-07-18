#ifndef BFG_STD_CPP_COMMAND_BUILDER_MSVC_LIKE_HPP
#define BFG_STD_CPP_COMMAND_BUILDER_MSVC_LIKE_HPP

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

class command_builder_msvc_like : public command_builder
{
    public:

    command_builder_msvc_like()
    {
        inputs inputs;
        set_processor(inputs, &command_builder_msvc_like::process_inputs);
        options::core core;
        set_processor(core.output, &command_builder_msvc_like::process_output);
        set_processor(core.include_dir, &command_builder_msvc_like::process_include_dir);
        set_processor(core.debug_info, &command_builder_msvc_like::process_debug_info);
        set_processor(core.standard, &command_builder_msvc_like::process_standard);
        set_processor(core.optimize, &command_builder_msvc_like::process_optimize);
        set_processor(core.warnings, &command_builder_msvc_like::process_warnings);
        set_processor(core.address_model, &command_builder_msvc_like::process_address_model);
        set_processor(core.define, &command_builder_msvc_like::process_define);
    }

    result process_inputs(void * v) { *this << value<std::string>(v); return result::ok_(); }
    result process_output(void * v) { *this << "/O" << value<std::string>(v); return result::ok_(); }
    result process_include_dir(void * v) { *this << "/I" << value<std::string>(v); return result::ok_(); }
    result process_debug_info(void * v) { return result::warning_("unimplemented"); }
    result process_standard(void * v) { return result::warning_("unimplemented"); }
    result process_warnings(void * v) { return result::warning_("unimplemented"); }
    result process_optimize(void * v) { return result::warning_("unimplemented"); }
    result process_address_model(void * v) { return result::warning_("unimplemented"); }
    result process_define(void * v) { return result::warning_("unimplemented"); }
};

}

#endif
