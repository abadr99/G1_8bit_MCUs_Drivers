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

main_C_test_directory=regression-tests/regression-tests

# -- Check for passed arguments
if [ $# != 1 ]
then 
    echo "[run-regression]: Usage run-regression path/to/elf/dir or Usage run-regression all to run all tests"
    exit 1
fi


if [ -d "$1" ]
then
  echo "$GREEN [--- OK ---]:$RESET Directory has been found successfully: $1"
  test_file=$(find "$1" -type f -name "*.elf" | grep "\.elf$")
  if [ -s "$test_file" ]
  then
    echo "$GREEN [--- OK ---]:$RESET Test-elf file has been found : $test_file" 
  else
    echo "$RED No elf file found in the directory $RESET"
    exit 1
  fi
else
  echo "$RED Directory not found $RESET: $directory_to_search"
  exit 1 
fi

test_dir=$(dirname "$test_file")
echo "$YELLOW Testing: $test_file $RESET" 

if [ -s "$test_dir/results.expected" ]
then
  echo "$GREEN [--- OK ---]:$RESET Expected results file have been found : $test_file"
else
  echo "$RED No results.expected file found in the directory$RESET: $test_dir"
  exit 1
fi

simulavr -d atmega32 -f $test_file -W 0x20,- -R 0x22,- -T exit > $test_dir/results.output
if [ -s "$test_dir/results.output" ]
then
  echo "$GREEN [--- OK ---]:$RESET Output file has been generated successfully : $test_file"
fi

diff $test_dir/results.output $test_dir/results.expected

if [ $? -eq 0 ]
then 
    echo "[$test_file]:$GREEN PASS $RESET" 
    rm -rf $test_dir/results.output
    exit 0
else
    echo "$BOLD_RED[FAIL]:$RESET $test_file"
    rm -rf $test_dir/results.output
    exit 1
fi
