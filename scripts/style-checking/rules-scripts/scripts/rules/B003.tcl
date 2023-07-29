#!/usr/bin/tclsh
# All user defined data types must be ended with `_t`

foreach f [getSourceFileNames] {
    set lineNumber 1
    foreach line [getAllLines $f] {

        if [regexp {(^int(?! main)|^unsigned|^signed|^short|^long|^long long|^float|^double)} $line] {
            report $f $lineNumber "Using non-standard datatype not recommended"
        }
        incr lineNumber
    }
}