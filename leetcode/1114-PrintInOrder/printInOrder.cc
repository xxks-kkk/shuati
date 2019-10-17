#include "cpputility.h"
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <semaphore.h>
#include <sstream>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

using namespace std;

mutex some_mutex;

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

class Semaphore {
	size_t avail;
	std::mutex m;
	std::condition_variable cv;
public:
	/** Default constructor. Default semaphore is a binary semaphore **/
	explicit Semaphore(size_t avail_ = 1) : avail(avail_) { }

	void acquire() {
		std::unique_lock<std::mutex> lk(m);
		cv.wait(lk, [this] { return avail > 0; });
		avail--;
		lk.unlock();
	}

	void release() {
		m.lock();
		avail++;
		m.unlock();
		cv.notify_one();
	}

	size_t available() const {
		return avail;
	}
};

Semaphore a(0);
Semaphore b(0);

class Foo {
public:
    Foo() {}

    void first(function<void()> printFirst) {
        printFirst();
        a.release();
    }

    void second(function<void()> printSecond) {
        a.acquire();
        printSecond();
        b.release();
    }

    void third(function<void()> printThird) {
        b.acquire();
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
      threads.emplace_back(m[test_case.input[i]].first, foo, m[test_case.input[i]].second);
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
