#ifndef BFG_STD_CPP_INPUTS_HPP
#define BFG_STD_CPP_INPUTS_HPP

/*
Copyright 2017-2018 Rene Rivera
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
 */

#include <memory>
#include <string>
#include <typeindex>
#include <typeinfo>
#include <vector>

#include <clara.hpp>

#include "cli.hpp"
#include "opt.hpp"

namespace bfg_std_cpp {

class inputs : public opt_type
{
    public:

    inputs()
    {
        clara_arg.reset(new clara::Arg(
            [this](std::string const & v) {
                this->value.push_back(v);
                this->cli->process(v, this);
            },
            "inputs"
        ));
    }

    std::vector<std::string> const & get() const
    {
        return value;
    }

    auto operator>>(cli & c) -> class cli &
    {
        cli = &c;
        return (c |= *clara_arg);
    }

    auto index() const -> std::type_index override
    {
        return std::type_index(typeid(inputs));
    }

    protected:

    std::vector<std::string> value;
    std::unique_ptr<clara::Arg> clara_arg;
    cli * cli = nullptr;
};

}

#endif
