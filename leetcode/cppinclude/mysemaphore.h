#ifndef MYSEMAPHORE_H
#define MYSEMAPHORE_H

#include "shared_headers.h"

class Semaphore {
private:
  int avail;
  std::mutex m;
  std::condition_variable cv;

public:
  /** Default constructor. Default semaphore is a binary semaphore **/  
  explicit Semaphore(int avail_ = 1) : avail(avail_) {}
  void wait();
  void post();
  int available() const;
};

#endif //MYSEMAPHORE_H
