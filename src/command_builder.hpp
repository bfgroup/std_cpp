#ifndef BFG_STD_CPP_COMMAND_BUILDER_HPP
#define BFG_STD_CPP_COMMAND_BUILDER_HPP

/*
Copyright 2017-2018 Rene Rivera
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
 */

#include <functional>
#include <memory>
#include <string>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <vector>

namespace bfg_std_cpp {

class opt_type;

class command_builder
{
    public:

    struct result
    {
        enum { ok, error, warning } kind;
        std::string message;
        static inline result ok_() { return result({ok, ""}); }
        static inline result error_(std::string const & m) { return result({error, m}); }
        static inline result warning_(std::string const & m) { return result({warning, m}); }
    };

    using arguments_vector = std::vector<std::string>;

    static std::shared_ptr<command_builder> make();

    virtual ~command_builder();

    virtual result pre() { return result::ok_(); }
    virtual result post() { return result::ok_(); }

    template <typename V>
    result process(V v, void * o)
    {
        opt_type * ot = static_cast<opt_type*>(o);
        if (this->processor.count(opt_index(*ot)) > 0)
        {
            return this->processor[opt_index(*ot)](*this, *ot, &v);
        }
        return result::ok_();
    }

    auto operator<<(std::string arg) -> command_builder &
    {
        arguments.emplace_back([arg](arguments_vector& args)->void{ args.push_back(arg); });
        return *this;
    }

    auto operator<<(std::function<void (arguments_vector&)> arg) -> command_builder &
    {
        arguments.emplace_back(arg);
        return *this;
    }

    friend auto operator<<(std::ostream &os, command_builder const &c) -> std::ostream&
    {
        for (auto & argument: c.get_command())
        {
            os << std::string("\"") << argument << std::string("\" ");
        }
        return os;
    }

    std::vector<std::string> get_command() const
    {
        std::vector<std::string> result;
        for (auto & argument : arguments)
        {
            argument(result);
        }
        return result;
    }

    protected:

    std::vector<std::function<void (arguments_vector &)>> arguments;
    std::unordered_map<std::type_index, std::function<result (command_builder &, opt_type &, void*)>> processor;

    template <typename F>
    void set_processor(opt_type const & o, F const & f)
    {
        this->processor[opt_index(o)] = f;
    }

    template <typename C>
    void set_processor(opt_type const & o, result (C::*mf)(void*))
    {
        this->processor[opt_index(o)]
            = [this,mf](command_builder&, opt_type &, void* v)->result { return (static_cast<C*>(this)->*mf)(v); };
    }

    template <typename V> constexpr V & value(void * v) const { return *static_cast<V*>(v); }

    static std::type_index opt_index(opt_type const & o);

    #if 0
    static std::string quoted(std::string const & s)
    {
        return "\""+s+"\"";
    }
    #endif
};

}

#endif
