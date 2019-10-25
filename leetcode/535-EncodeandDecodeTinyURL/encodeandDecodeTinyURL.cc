#include <string>
#include <random>
#include <unordered_map>

using namespace std;

class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
      if (reverse_m.find(longUrl) != reverse_m.end()) {
        return reverse_m[longUrl];
      }
      auto unique_id = generate_unique_id();
      m[unique_id] = longUrl;
      reverse_m[longUrl] = unique_id;
      return unique_id;        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
      if (m.find(shortUrl) == m.end()) {
        return "-1";
      }
      return m[shortUrl];        
    }
private:
  std::string random_string(std::size_t length) {
    const std::string characters =
        "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, characters.size() - 1);
    std::string random_string;
    for (std::size_t i = 0; i < length; ++i) {
      random_string += characters[distribution(generator)];
    }
    return random_string;
  }
  string generate_unique_id() {
    string id = "";
    counter++;
    id = id +  random_string(3) + to_string(counter);
    return id;
  }
  unordered_map<string, string> m;         // unique_id, url
  unordered_map<string, string> reverse_m; // url, unique_id
  size_t counter = 0;  
};


// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

void test() {
  Solution solution;
  string url = "https://leetcode.com/problems/design-tinyurl";
  assert(url == solution.decode(solution.encode(url)));
}

int main() {
  test();
}
