#!/usr/bin/tclsh
# We should have space between operators e.g. x <= 2

foreach f [getSourceFileNames] {
    set lineNumber 1
    foreach line [getAllLines $f] {
        #TODO #29 : Check How can we check divede and * operands
        if [regexp {(\s)(\=|<<|>>|\<\=|\>\=|\=\=|\!\=|\!|\~|\^|\%|\+|\-)(\S)} $line] {
            report $f $lineNumber "Operators should be prefixed and postfixed by space"
        } elseif [regexp {(\S)(\=|\<\<|>>|\<\=|\>\=|\=\=|\!\=|\!|\~|\^|\%|\+|\-)(\s)} $line] {
            report $f $lineNumber "Operators should be prefixed and postfixed by space"
        } elseif [regexp {(\S)(\=|\<\<|>>|\<\=|\>\=|\=\=|\!\=|\!|\~|\^|\%|\+|\-)(\S)} $line] {
            report $f $lineNumber "Operators should be prefixed and postfixed by space"
        }

        incr lineNumber
    }
}
