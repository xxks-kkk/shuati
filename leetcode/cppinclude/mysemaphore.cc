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
  std::lock_guard<std::mutex> lk(m);
  avail++;
  cv.notify_one();
}

size_t
Semaphore::available() const {
  return avail;
}
