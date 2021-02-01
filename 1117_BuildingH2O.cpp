#include <functional>
#include <mutex>
#include <condition_variable>

using namespace std;

class H2O {
  private:
    int h, o;

    mutex m;
    condition_variable cv_h, cv_o;

  public:
    H2O(): h(0), o(0) { }

    void hydrogen(function<void()> releaseHydrogen) {

      unique_lock<mutex> lock(m);
      cv_h.wait(lock, [this](){ return h<2; });
        
      // releaseHydrogen() outputs "H". Do not change or remove this line.
      releaseHydrogen();

      if (++h==2 && o==1) {
        h = 0; o = 0;
      }

      cv_h.notify_one();
      cv_o.notify_one();
    }

    void oxygen(function<void()> releaseOxygen) {

      unique_lock<mutex> lock(m);
      cv_o.wait(lock, [this](){ return o<1; });

      // releaseOxygen() outputs "O". Do not change or remove this line.
      releaseOxygen();

      if (++o==1 && h==2) {
        o = 0; h = 0;
      }

      cv_h.notify_one();
      cv_h.notify_one();
    }
};