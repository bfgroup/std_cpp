#ifndef BFG_STD_CPP_CLI_HPP
#define BFG_STD_CPP_CLI_HPP

/*
Copyright 2017-2018 Rene Rivera
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
 */

#include <type_traits>

#include "clara.hpp"

#include "command_builder.hpp"

namespace bfg_std_cpp {

class cli
{
    public:

    cli(std::shared_ptr<command_builder> cb) : cb(cb) {}

    template <typename T>
    auto operator|=(T const &t) -> cli &
    {
        parser |= t;
        return *this;
    }

    class result
    {
        public:

        template <typename T>
        result(T const & r) : clara_result(r)
        {
        }

        operator bool() const { return bool(clara_result); }

        friend auto operator<<( std::ostream & os, result const & r) -> std::ostream &
        {
            if (!r.clara_result) os << r.clara_result.errorMessage();
            return os;
        }

        private:

        clara::detail::InternalParseResult clara_result;
    };

    auto parse(int argc, char * * argv) -> result
    {
        cb->pre();
        auto r = result(parser.parse(clara::Args(argc, argv), ClaraParserCustomize()));
        cb->post();
        return r;
    }

    friend auto operator<<(std::ostream &os, cli const &c) -> std::ostream&
    {
        c.parser.writeToStream(os);
        return os;
    }

    void process(bool v, void * o)
    {
        cb->process(v, o);
    }

    void process(std::string const & v, void * o)
    {
        cb->process(v, o);
    }

    void process(int v, void * o)
    {
        cb->process(v, o);
    }

    auto command() -> command_builder &
    {
        return *cb;
    }

    private:

    struct ClaraParserCustomize : clara::ParserCustomization
    {
        auto token_delimiters() const -> std::string override { return " ="; }
        auto option_prefix() const -> std::string override { return "+"; }
    };

    clara::Parser parser;
    std::shared_ptr<command_builder> cb;
};

}

#endif
