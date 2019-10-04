// You will be provided with N lines of what are possibly IP addresses. You need to detect if the text contained in each of the lines represents an (a)IPv4 address (b)IPv6 address or (c)None of these.

// IPv4 was the first publicly used Internet Protocol which used 4 byte addresses which permitted for 232 addresses. The typical format of an IPv4 address is A.B.C.D where A, B, C and D are Integers lying between 0 and 255 (both inclusive).

// IPv6, with 128 bits was developed to permit the expansion of the address space. To quote from the linked article: The 128 bits of an IPv6 address are represented in 8 groups of 16 bits each. Each group is written as 4 hexadecimal digits and the groups are separated by colons (:). The address 2001:0db8:0000:0000:0000:ff00:0042:8329 is an example of this representation. Consecutive sections of zeros will be left as they are.
// An IPv6 value such as "...:0:..." or "...:5:..." is address-wise identical to "...:0000:..." or "...:0005:....". Leading zeros may be omitted in writing the address.

// Input Format
// An integer N such that N <= 50. This is followed by N lines such that each the text in each line is either an IPv4 address or an IPv6 address, or a chunk of text which does not equal either of these. There will be no extra text or whitespace leading or trailing the IP address in a line (if it is an IP address). The number of characters in each line will not exceed 500.

// Output Format
// N lines.
// The ith output line should equal (a)IPv4 or (b)IPv6 or (c)Neither depending on what you detected the ith input line to be.

// Sample Input

// 3
// This line has junk text.  
// 121.18.19.20  
// 2001:0db8:0000:0000:0000:ff00:0042:8329  

// Sample Output

// Neither    
// IPv4  
// IPv6  

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <regex>
#include "cppinclude/cpputility.h"

using namespace std;

void ipAddressValidation() {
  string line;
  getline(cin, line);
  int numCands = stoi(line);
  for (string cand; std::getline(std::cin, cand);) {
    if (regex_match(cand, regex("^([0-9]|[01]?[0-9][0-9]|2[0-4][0-9]|25[0-5])(\\.([0-9]|[01]?[0-9][0-9]|2[0-4][0-9]|25[0-5])){3}$"))) {
      cout << "IPv4\n";
    } else if (regex_match(cand, regex("^([0-9a-fA-F]{1,4})(:([0-9a-fA-F]{1,4})){7}$"))) {
      cout << "IPv6\n";
    } else {
      cout << "Neither\n";
    }
  }
}

void
test(const vector<string> &input_filenames,
     const vector<string> &output_filenames,
     const vector<string> &expected) {
  assert(input_filenames.size() == output_filenames.size());
  for(int i = 0; i < input_filenames.size(); ++i) {
    std::ifstream in(input_filenames[i]);
    std::ofstream out(output_filenames[i]);
    std::streambuf *cinbuf = std::cin.rdbuf();
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cin.rdbuf(in.rdbuf());
    std::cout.rdbuf(out.rdbuf());
    ipAddressValidation();
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    if (!CPPUtility::check_file_identical(output_filenames[i], expected[i])) {
      printf("%s and %s are different\n", output_filenames[i].c_str(), expected[i].c_str());
      assert(false);
    }
  }
}


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  vector<string> input_filenames = {"input001.txt"};
  vector<string> output_filenames = {"output001.txt"};
  vector<string> expected = {"output001_exp.txt"};
  test(input_filenames, output_filenames, expected);
}
