#ifndef BFG_STD_CPP_CLI_HPP
#define BFG_STD_CPP_CLI_HPP

/*
Copyright 2017-2018 Rene Rivera
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
 */

#include <type_traits>
#include <iostream>

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

        result(clara::detail::InternalParseResult const & r)
        {
            is_error = !bool(r);
            message = r.errorMessage();
        }

        result(command_builder::result const & r)
        {
            is_error = r.kind == command_builder::result::error;
            message = r.message;
        }

        operator bool() const { return !is_error; }

        friend auto operator<<( std::ostream & os, result const & r) -> std::ostream &
        {
            if (!r) os << r.message;
            return os;
        }

        operator clara::ParserResult() const
        {
            if (is_error) return clara::ParserResult::runtimeError(message);
            if (!message.empty())
            {
                std::cout << message << "\n";
            }
            return clara::ParserResult::ok();
        }

        private:

        bool is_error = false;
        std::string message;
    };

    auto parse(int argc, char * * argv) -> result
    {
        auto pre_r = result(cb->pre());
        if (!pre_r) return pre_r;
        auto parse_r = result(parser.parse(clara::Args(argc, argv), ClaraParserCustomize()));
        if (!parse_r) return parse_r;
        auto post_r = result(cb->post());
        return post_r;
    }

    friend auto operator<<(std::ostream &os, cli const &c) -> std::ostream&
    {
        c.parser.writeToStream(os);
        return os;
    }

    result process(bool v, void * o)
    {
        return cb->process(v, o);
    }

    result process(std::string const & v, void * o)
    {
        return cb->process(v, o);
    }

    result process(int v, void * o)
    {
        return cb->process(v, o);
    }

    auto command() -> command_builder &
    {
        return *cb;
    }

    private:

    struct ClaraParserCustomize : clara::ParserCustomization
    {
        auto token_delimiters() const -> std::string override { return " ="; }
        // auto option_prefix() const -> std::string override { return "+"; }
        auto option_prefix() const -> std::string override { return "-"; }
    };

    clara::Parser parser;
    std::shared_ptr<command_builder> cb;
};

}

#endif
