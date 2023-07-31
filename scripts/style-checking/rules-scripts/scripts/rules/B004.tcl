#!/usr/bin/tclsh
# Check if the variables : (1) Doesn't contain underscores   (2) begin with lowercase 

foreach f [getSourceFileNames] {
    set lineNumber 1
    foreach line [getAllLines $f] {
        # TODO : We may use uint16 not uint16_t so we have to modify script
        if [regexp {(_t)\;} $line] {

        } elseif [regexp {(char|[a-zA-Z]+_t)\s+[a-zA-Z0-9]+_+[a-zA-Z0-9]+\s*(\;|\=|\))} $line] {
            report $f $lineNumber "Variables names shouldn't contain underscores"
        }
        if [regexp {(char|([a-zA-Z0-9]+_t))\s+[A-Z][a-zA-Z0-9]+\s*(\;|\=|\))} $line] {
            report $f $lineNumber "Variables names should start with lowercase"
        }
        incr lineNumber
    }
}