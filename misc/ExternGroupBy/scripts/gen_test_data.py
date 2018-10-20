#!/usr/bin/env python

import sys
import string
import random


def gen_word(length, chars=string.ascii_lowercase):
    return ''.join(random.choice(chars) for _ in range(length))


def main():
    if len(sys.argv) < 5:
        print("Usage: gen_test_data.py mem_limit num_pairs key_length value_length")
        sys.exit(1)

    mem_limit = int(sys.argv[1])
    num_pairs = int(sys.argv[2])
    key_length = int(sys.argv[3])
    value_length = int(sys.argv[4])

    print(mem_limit)
    for i in range(num_pairs):
        key = gen_word(key_length)
        value = gen_word(value_length)
        print("%s %s" % (key, value))


if __name__ == '__main__':
    main()
