#!/bin/bash

# Run this script at G1_AVR_Drivers/C
# sh run-regressionn.sh path/to/elf/dir

# Define ANSI color codes
# RED='\033[0;31m'
# GREEN='\033[0;32m'
# YELLOW='\033[0;33m'
# RESET='\033[0m'  # Reset color to default

main_C_test_directory=regression-tests/regression-tests

if [ $# != 1 ]
then 
    #echo "[run-regression]: Usage run-regression path/to/elf/dir or Usage run-regression all to run all tests"
    exit 1
fi

case $1 in

  all)

    if [ -d "$main_C_test_directory" ]; then
      test_files=$(find "$main_C_test_directory" -type f -name "*.elf")
    else
      #echo "Directory not found: $main_C_test_directory"
      exit 1 
    fi
    for test_file in $test_files
    do
        #echo "Testing: $test_file"
        test_dir=$(dirname "$test_file")
        sh ../scripts/testing/run-regressions.sh $test_dir
        if [ $? -eq 1 ]
        then
            exit 1
        fi
    done
    ;;
  *)
    if [ -d "$1" ]; then
      test_file=$(find "$1" -type f -name "*.elf" | grep "\.elf$")
    else
      #echo "Directory not found: $directory_to_search"
      exit 1 
    fi
    test_dir=$(dirname "$test_file")
    if [ -s "$test_file" ]
    then
      #echo "$YELLOW========================================================================================================================================================$RESET"
      echo "RUNNING $test_file test"  
    else
      echo "No elf file found in the directory"
      exit 1
    fi

    if [ -s "$test_dir/results.expected" ]
    then
      echo "Comparing $test_dir/results.output vs. $test_dir/results.expected"
    else
      echo "No results.expected file found in the directory"
      exit 1
    fi

    rm -rf results.output

    simulavr -d atmega32 -f $test_file -W 0x20,- -R 0x22,- -T exit > $test_dir/results.output
    #echo "RESULTS:"
    diff $test_dir/results.output $test_dir/results.expected

    if [ $? -eq 0 ]
    then 
        #echo "[$test_file]:$GREEN PASS $RESET" 
        echo "[$test_file]: PASS" 
    else
        #echo "[$test_file]:$RED FAIL$RESET"
        exit 1
    fi
    ;;
esac
rm -rf $test_dir/results.output

#exit $EXIT


