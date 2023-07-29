#!/usr/bin/tclsh
# Check if the variables :
# 1. doesn't contain underscores 
# 2. begin with lowercase 

foreach f [getSourceFileNames] {
    set lineNumber 1
    foreach line [getAllLines $f] {
        # TODO : We may use uint16 not uint16_t so we have to modify script
        if [regexp {(char|uint16_t|int16_t|uint32_t|int32_t|uint64_t|int64_t|float32|float64)\s+[a-zA-Z]+_+[a-zA-Z]+} $line] {
            report $f $lineNumber "Variables names shouldn't contain underscores"
        }
        if [regexp {(char|uint16_t|int16_t|uint32_t|int32_t|uint64_t|int64_t|float32|float64)\s+[A-Z_]} $line] {
            report $f $lineNumber "Variables names should start with lowercase"
        }
        incr lineNumber
    }
}