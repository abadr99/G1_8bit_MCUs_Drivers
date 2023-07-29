#!/usr/bin/tclsh
# All user defined data types must be ended with `_t`

foreach f [getSourceFileNames] {
    set lineNumber 1
    foreach line [getAllLines $f] {

        if [regexp {\#define\s+[a-z]+} $line] {
            report $f $lineNumber "All defined macros should be uppercase"
        }
        incr lineNumber
    }
}