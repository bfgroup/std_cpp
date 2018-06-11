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
/* tag::std_cpp[]

= help

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

[subs=+macros]
....
pass:q[+o _file_]
pass:q[++output=_file_]
....

[horizontal]
Argument:: An implementation defined path to a _file_.
Effect:: Sets the destination file of the compilation.

*/ // end::std_cpp[]
    output.hint("file")
        ["-o"]["--output"]
        ("Write output to <file>.")
        >> cli;

/* tag::std_cpp[]

= include directory

[subs=+macros]
....
pass:q[+I _directory_]
pass:q[++include-dir=_directory_]
....

[horizontal]
Argument:: An implementation defined path to a _directory_.
Effect:: Adds the given _directory_ to the end of the search path of the preprocessor.

*/ // end::std_cpp[]
    include_dir.hint("directory")
        ["-I"]["--include-dir"]
        ("Add <directory> to the main include path of the preprocessor.")
        >> cli;

/* tag::std_cpp[]

= debug information

....
+g
++debug
....

[horizontal]
Effect:: Adds source-level debug information to the compiled output.

*/ // end::std_cpp[]
    debug_info.flag()
        ["-g"]["--debug"]
        ("Generate source-level debug information.")
        >> cli;

/* tag::std_cpp[]

= standard conformance

[subs=+macros]
....
pass:q[+std _standard_]
pass:q[++standard=_standard_]
....

[horizontal]
Argument:: One of: `98`, `03`, `11`, `14`, `17`, or `2a` indicating the year of the _standard_.
Effect:: Instructs compilation to use the given _standard_ as the version of
    the C++ language standard for the source TU.
Support:: The language levels accepted, within the allowed values, is implementation defined.
Compatibility:: Link incompatible between _standard_ values.

*/ // end::std_cpp[]
    standard.hint("standard")
        ["-std"]["--standard"]
        ("Specify that the input sources are for <standard>.")
        >> cli;
}

} }
