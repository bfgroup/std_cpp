/*
 Copyright 2018 Rene Rivera
 Distributed under the Boost Software License, Version 1.0.
 (See accompanying file LICENSE_1_0.txt or copy at
 http://www.boost.org/LICENSE_1_0.txt)
 */

#include "opt_core.hpp"

namespace bfg_std_cpp { namespace options {

core::core() {}

core::core(cli & cli)
{
/////////////////////////////////////////////////////////////////////////////

/* tag::std_cpp[]

= help

[subs=normal]
....
+h
+?
++help
....

[horizontal]
Effect:: Displays all available options and exits.

*/ // end::std_cpp[]
    help.flag()
        ["-?"]["-h"]["--help"]
        ("Show usage.")
        >> cli;

/* tag::std_cpp[]

= output

[subs=normal]
....
+o __file__
++output=__file__
....

[horizontal]
Argument:: An implementation defined path to a _file_.
Effect:: Sets the destination file of the compilation.
Support:: Required
Compatibility:: NA

*/ // end::std_cpp[]
    output.hint("file")
        ["-o"]["--output"]
        ("Write output to <file>.")
        >> cli;

/* tag::std_cpp[]

= define

[subs=normal]
....
+D __definition__
++define=__definition__
....

[horizontal]
Argument:: A preprocessor _definition_ of the for `_name_=_value_`
Effect:: Instructs the preprocessing phase to define the given _name_ symbol
    to the given _value_, or to `1` if _value_ is not given.
Support:: Required
Compatibility:: NA

*/ // end::std_cpp[]
    define.hint("_definition_").many()
        ["-D"]["--define"]
        ("Predefine given macro _definition_.")
        >> cli;

/* tag::std_cpp[]

= include directory

[subs=normal]
....
+I __directory__
++include-dir=__directory__
....

[horizontal]
Argument:: An implementation defined path to a _directory_.
Effect:: Adds the given _directory_ to the end of the search path of the preprocessor.
Support:: Required
Compatibility:: NA

*/ // end::std_cpp[]
    include_dir.hint("directory").many()
        ["-I"]["--include-dir"]
        ("Add <directory> to the main include path of the preprocessor.")
        >> cli;

/* tag::std_cpp[]

= debug information

[subs=normal]
....
+g
++debug
....

[horizontal]
Argument:: None
Effect:: Adds source-level debug information to the compiled output.
Support:: Required if supported by the environment.
Compatibility:: NA

*/ // end::std_cpp[]
    debug_info.flag()
        ["-g"]["--debug"]
        ("Generate source-level debug information.")
        >> cli;

/* tag::std_cpp[]

= standard conformance

[subs=normal]
....
+std __standard__
++standard=__standard__
....

[horizontal]
Argument:: One of: `98`, `03`, `11`, `14`, `17`, or `2a` indicating the year of the _standard_.
Effect:: Instructs compilation to use the given _standard_ as the version of
    the C++ language standard for the source TU.
Support:: The language levels accepted, within the allowed values, is implementation defined.
Compatibility:: Link incompatible.

*/ // end::std_cpp[]
    standard.hint("standard")
        ["-std"]["--standard"]
        ("Specify that the input sources are for <standard>.")
        >> cli;

/* tag::std_cpp[]

= warnings

[subs=normal]
....
+W __warning_option__
++warnings=__warning_option__
....

[horizontal]
Argument:: One of: `off`, `on`, `all`, `error` indicating the level of
    warnings to report and whether to treat warnings as errors.
Effect:: Instructs compilation to: not report warning (`off`), report a default
    set of warnings that is implementation defined (`on`), to report all
    possible warnings (`all`), and if instead of reporting warnings they
    should be considered compilation errors (`errors`).
Support:: Implementations are only required to have an effect for `off` and
    `on` values. Other unimplemented values must be ignored.
Compatibility:: Link compatible.

*/ // end::std_cpp[]
    warnings.hint("warning_option")
        ["-W"]["--warnings"]
        ("Specify what kind of warnings to report during compilation.")
        >> cli;

/* tag::std_cpp[]

= optimize

[subs=normal]
....
+O __optimization_level__
++optimize=__optimization_level__
....

[horizontal]
Argument:: One of: `off`, `on`, `speed`, or `size`.
Effect:: Instructs compilation to optimize the generated code using the
    indicated level and type.
Support:: Implementations are only required to have an effect for `off` and
    `on` values. Other unimplemented values must be ignored.
Compatibility:: Link compatible.

*/ // end::std_cpp[]
    optimize.hint("optimization_level")
        ["-O"]["--optimize"]
        ("Specify the level and type of optimizations.")
        >> cli;

/* tag::std_cpp[]

= address_model

[subs=normal]
....
++address_model=__bits__
....

[horizontal]
Argument:: A positive number greater than 0 indicating the number of bits
    to base pointer and number generated instructions on.
Effect:: Instructs compilation to generate instructions that conform to an
    implementation defined size of pointers and numbers.
Support:: The values accepted are implementation defined. And any not
    understood values shall fail compilation and produce an error.
Compatibility:: Link incompatible.

*/ // end::std_cpp[]
    address_model.hint("address_model")
        ["--address_model"]
        ("Addressing model, in bits, to generate instructions for.")
        >> cli;


/* tag::std_cpp[]

= library

[subs=normal]
....
+l __library__
++library=__library__
....

[horizontal]
Argument:: An implementation defined name of the _library_.
Effect:: Adds the given _library_ to the program linking as an already compiled
    single translation unit, or collection thereof.
Support:: Required
Compatibility:: NA

*/ // end::std_cpp[]
    library.hint("library").many()
        ["-l"]["--library"]
        ("Add <library> to the link as a source of translation units.")
        >> cli;
/////////////////////////////////////////////////////////////////////////////
}

} }
