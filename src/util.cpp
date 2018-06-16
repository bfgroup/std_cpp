/*
Copyright 2017-2018 Rene Rivera
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
 */

#include <cstdlib>
#include <string>
#include <vector>

#include <boost/predef.h>

#include "util.hpp"

#if BOOST_OS_WINDOWS
#else
#include <unistd.h>  // vfork() and such
#endif

namespace bfg_std_cpp {

std::string safe_getenv(std::string const & name, std::string const & default_val)
{
    const char * from_env = std::getenv(name.c_str());
    std::string result = from_env ? from_env : "";
    if (result.empty()) result = default_val;
    return result;
}

int exec_command(std::vector<std::string> const & command)
{
    #if BOOST_OS_WINDOWS
    #else
    int child_pid = ::vfork();
    if (child_pid == -1)
    {
        return -1;
    }
    if (child_pid == 0)
    {
        const char * command_exec = command[0].c_str();
        std::vector<const char *> command_args;
        for (int i = 1; i < command.size(); ++i) command_args.push_back(command[i].c_str());
        int exec_result = ::execvp(command_exec, const_cast<char * const *>(&command_args[1]));
        if (exec_result == -1)
        {
            return -1;
        }
    }
    else
    {
        int status = 0;
        while (::wait(&status) != child_pid) ;
        return status;
    }
    #endif
    return 0;
}

}
