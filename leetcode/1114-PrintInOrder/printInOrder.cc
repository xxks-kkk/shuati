#include "cpputility.h"
#include <functional>
#include <iostream>
#include <semaphore.h>
#include <sstream>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

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
protected:
  sem_t firstJobDone;
  sem_t secondJobDone;

public:
  Foo()
  {
    sem_init(&firstJobDone, 0, 0);
    sem_init(&secondJobDone, 0, 0);
  }

  void first(function<void()> printFirst)
  {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    sem_post(&firstJobDone);
  }

  void second(function<void()> printSecond)
  {
    sem_wait(&firstJobDone);
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    sem_post(&secondJobDone);
  }

  void third(function<void()> printThird)
  {
    sem_wait(&secondJobDone);
    // printThird() outputs "third". Do not change or remove this line.
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
  };
  for (auto &&test_case : test_cases)
  {
    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
    Foo foo;
    vector<thread> threads;
    for (int i = 0; i < 3; ++i)
    {
      threads.emplace_back(m[i+1].first, foo, m[i+1].second);
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
  for(int i = 0; i < 10; ++i) {
    // Test repeatedly to detect any potential race condition
    test();    
  }
}
