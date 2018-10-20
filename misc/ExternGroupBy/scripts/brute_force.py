#!/usr/bin/env python

import sys
import string
import random


def main():
    # Ignore mem_limit in this brute force implementation.
    mem_limit = sys.stdin.readline()

    key_dict = {}
    for line in sys.stdin.readlines():
        [key, value] = line.strip().split(' ')
        if key in key_dict:
            key_dict[key].append(value)
        else:
            key_dict[key] = [value]
    keys = sorted(key_dict.keys())
    for key in keys:
        values = sorted(key_dict[key])
        print("%s %s" % (key, ' '.join(values)))


if __name__ == '__main__':
    main()
