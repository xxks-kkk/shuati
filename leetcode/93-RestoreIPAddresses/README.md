## Solution explanation

According to []wikipedia on IPv4 addresses](https://en.wikipedia.org/wiki/IP_address#IPv4_addresses),
an IP address in IPv4 is 32-bits in size. Specifically, 
IPv4 addresses are usually represented in dot-decimal notation, 
consisting of four decimal numbers, each ranging from 0 to 255, separated by dots, e.g., 172.16.254.1. 
Each part represents a group of 8 bits (octet) of the address.

There are several constraints for an IP address to be valid:

- each part has to be a number between 0 and 255
- For part with two or more digits, we cannot have 0 on the most significant bit (i.e., 010 is invalid)

The solution to this problem is backtracking, which has very similar code structure to other
backtracking problems. For `last_two_digit` and `last_three_digit`, we check their length to make
sure we indeed get two digits and three digits number. In python, for example `b = '0'` and `b[-2:]`
gives `'0'` even though we only have one digit in `b`.