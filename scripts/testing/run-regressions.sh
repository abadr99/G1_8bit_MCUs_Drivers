#!/bin/bash

# Run this script at G1_AVR_Drivers/C
# sh run-regressionn.sh path/to/elf/dir

# Define ANSI color codes
RED='\033[0;31m'
BOLD_RED='\033[1;31m'
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
Magenta='\033[1;35m'
RESET='\033[0m'  # Reset color to default
OK='\033[1;34m [---- OK  ----]:\033[0m'
OPS='\033[0;31m [--- Ooops ---]:\033[0m'

main_C_test_directory=regression-tests/regression-tests

# -- Check for passed arguments
if [ $# != 1 ]
then 
    echo "$RED[run-regression]:$RESET Usage run-regression path/to/elf/dir or Usage run-regression all to run all tests"
    exit 1
fi


if [ -d "$1" ]
then
  echo "$YELLOW[-- RUNNING --]:$RESET $1"
  echo "$OK Directory has been found successfully: $1"
  make -C $1
  test_file=$(find "$1" -type f -name "*.testelf" | grep "\.testelf$")
  if [ -s "$test_file" ]
  then
    echo "$OK $RESET Test-elf file has been found : $test_file" 
  else
    echo "$OPS No testelf file found in the directory "
    exit 1
  fi
else
  echo "$OPS :$RESET $directory_to_search"
  exit 1 
fi

test_dir=$(dirname "$test_file")
echo "\033[1;36m [-- TESTING --]:$RESET $test_file $RESET" 

if [ -s "$test_dir/results.expected" ]
then
  echo "$OK Expected results file have been found : $test_file"
else
  echo "$OPS No results.expected file found in the directory: $test_dir"
  exit 1
fi

simulavr -d atmega32 -f $test_file -W 0x20,- -R 0x22,- -T exit > $test_dir/results.output
if [ -s "$test_dir/results.output" ]
then
  echo "$OK Output file has been generated successfully : $test_file"
fi
rm -rf *.testelf
diff $test_dir/results.output $test_dir/results.expected

if [ $? -eq 0 ]
then  
    echo "$GREEN [--- PASS  ---]: $RESET: $test_file" 
    rm -rf $test_dir/results.output
    echo "\n"
    exit 0
else
    echo "$BOLD_RED[--- FAIL  ---]::$RESET $test_file"
    rm -rf $test_dir/results.output
    echo "\n"
    exit 1
fi
