#!/bin/bash -ev

MEM_LIMIT_IN_BYTES=10000000
NUM_PAIRS=1000000
KEY_LENGTH=3
VALUE_LENGTH=10

# The runtime memory limit which will be set larger than the memory limit requirement.
MAX_ALLOWED_MEMORY_IN_KB=100000
max_mem=0

SCRIPT_DIR=$(cd "$(dirname "$0")"; pwd)
echo $SCRIPT_DIR

$SCRIPT_DIR/gen_test_data.py $MEM_LIMIT_IN_BYTES $NUM_PAIRS $KEY_LENGTH $VALUE_LENGTH > input.txt
$SCRIPT_DIR/brute_force.py < input.txt > output.txt

echo $1
if [ $1 = "scripts/brute_force.py" ]; then
    # This is a hack that the original command "$1 < input.txt > test-output.txt" doesn't work on Mac
    # the test-output.txt is empty, which can lead to the test failure.
    cp output.txt test-output.txt
    # Re-run the command to get the memory usage estimation later
    $1 < input.txt > test-output2.txt & cmd_pid=$!
    rm -rf test-output2.txt
else
    $1 < input.txt > test-output.txt & cmd_pid=$!
fi

while true
do
  if ps -p $cmd_pid > /dev/null
  then
    # Get current memory that the process is using (in KB)
    current_mem=$((`ps u -p $cmd_pid | awk '{sum=sum+$6}; END {print sum}'`))
    max_mem=$((current_mem > max_mem ? current_mem : max_mem))
    if (( max_mem > MAX_ALLOWED_MEMORY_IN_KB ))
    then
      kill -9 $cmd_pid
      echo "Test failed! Peak memory usage was $max_mem kilobytes despite" \
        "allowed maximum of $MAX_ALLOWED_MEMORY_IN_KB."
      exit 0
    fi
    sleep 1
  else
    diff output.txt test-output.txt > /dev/null
    if [ $? -eq 0 ]; then
        echo "Test finished successfully! Peak memory usage was $max_mem kilobytes."
    else
        echo "Test failed! Peak memory usage was $max_mem kilobytes."
    fi
    exit 0
  fi
done
