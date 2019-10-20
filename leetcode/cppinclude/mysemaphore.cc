#include "mysemaphore.h"


void
Semaphore::wait()
{
  std::unique_lock<std::mutex> lk(m);
  cv.wait(lk, [this] { return avail > 0; });
  avail--;
}

void
Semaphore::post()
{
  std::unique_lock<std::mutex> lk(m);
  avail++;
  cv.notify_one();
}

int
Semaphore::available() const {
  return avail;
}
