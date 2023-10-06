#!/bin/bash

main_C_test_directory=regression-tests/regression-tests

if [ -d "$main_C_test_directory" ]; then
  test_files_dirs=$(ls "$main_C_test_directory")
else
  echo "Directory not found: $main_C_test_directory"
  exit 1 
fi

# Loop over the tests directories
for test_file_dir in $test_files_dirs
do
    #echo "Running test: $main_C_test_directory/$test_file_dir"
    sh ../scripts/testing/run-regressions.sh $main_C_test_directory/$test_file_dir
done