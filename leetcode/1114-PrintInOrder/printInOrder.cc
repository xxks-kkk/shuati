#include "cpputility.h"
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>
#include "mysemaphore.h"

using namespace std;

void printFirst()
{
  cout << "first" << std::flush;
}

void printSecond()
{
  cout << "second" << std::flush;
}

void printThird()
{
  cout << "third" << std::flush;
}

class Foo
{
  Semaphore firstJobDone;
  Semaphore secondJobDone;
public:
  Foo(): firstJobDone(0), secondJobDone(0) {}

  void first(function<void()> printFirst)
  {
    printFirst();
    firstJobDone.post();
  }

  void second(function<void()> printSecond)
  {
    firstJobDone.wait();
    printSecond();
    secondJobDone.post();
  }

  void third(function<void()> printThird)
  {
    secondJobDone.wait();
    printThird();
  }
};

void test()
{
  unordered_map<int, pair<void (Foo::*)(function<void()>), function<void()>>> m({
      {1, {&Foo::first, printFirst}},
      {2, {&Foo::second, printSecond}},
      {3, {&Foo::third, printThird}},
  });
  struct testCase
  {
    vector<int> input;
    string expected;
  };
  vector<testCase> test_cases = {
      {{1, 2, 3}, "firstsecondthird"},
      {{1, 3, 2}, "firstsecondthird"},
      {{2, 1, 3}, "firstsecondthird"},
      {{2, 3, 1}, "firstsecondthird"},
      {{3, 1, 2}, "firstsecondthird"},
      {{3, 2, 1}, "firstsecondthird"},
  };
  for (auto &&test_case : test_cases)
  {
    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
    Foo foo;
    vector<thread> threads;
    for (int i = 0; i < 3; ++i)
    {
      // We use the same object across multiple threads
      threads.emplace_back(m[test_case.input[i]].first, ref(foo), m[test_case.input[i]].second);
    }
    for (auto &&th : threads)
    {
      th.join();
    }
    auto got = buffer.str();
    if (got != test_case.expected)
    {
      printf("input: %s = %s\n",
             CPPUtility::oneDVectorStr<int>(test_case.input).c_str(),
             got.c_str());
      assert(false);
    }
    std::cout.rdbuf(old);
  }
}

int main()
{
  for (int i = 0; i < 10; ++i)
  {
    // Test repeatedly to detect any potential race condition
    test();
  }
}
