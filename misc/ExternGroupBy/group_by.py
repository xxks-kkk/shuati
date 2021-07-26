#!/usr/bin/env python3

import sys

def saveBuffer(filename, buffer):
    pass

def externGroupBy():
    # Ignore mem_limit in this brute force implementation.
    mem_limit = sys.stdin.readline()
    L = mem_limit / 2
    max_key_val_size = 0
    accumulate_size = 0
    runNum = 0
    buffer = []

    for line in sys.stdin:
        key, val = line.split(" ")
        key_val_size = len(key) + len(val)
        max_key_val_size = max(max_key_val_size, key_val_size)
        if accumulate_size + key_val_size > L:
            filename = "run" + runNum
            accumulate_size = 0
            saveBuffer(filename, buffer)
            runNum += 1
        buffer.append((key, val))
        accumulate_size += key_val_size

    

if __name__ == "__main__":
    externGroupBy()