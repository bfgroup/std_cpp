/*
 Copyright 2018 Rene Rivera
 Distributed under the Boost Software License, Version 1.0.
 (See accompanying file LICENSE_1_0.txt or copy at
 http://www.boost.org/LICENSE_1_0.txt)
 */

#include <iostream>

#include "compile.hpp"

#include "cli.hpp"
#include "command_builder.hpp"
#include "opt_core.hpp"
#include "inputs.hpp"
#include "util.hpp"

namespace std_cpp
{

using namespace bfg_std_cpp;

int compile(int argc, char * * argv) noexcept
{
    cli cli(command_builder::make());
    options::core opt_core(cli);
    inputs arg_inputs;
    arg_inputs >> cli;
    auto result = cli.parse(argc, argv);
    if (!result)
    {
        std::cerr << "Error in command line: " << result << std::endl;
        return -1;
    }
    if (*opt_core.help)
    {
        std::cout << cli;
    }
    else
    {
        std::cout << cli.command() << "\n";
        return exec_command(cli.command().get_command());
    }
    return 0;
}

}
