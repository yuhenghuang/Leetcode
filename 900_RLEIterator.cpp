#include "utils3.hpp"

class RLEIterator {
  private:
    int rem;
    size_t i;
    const vector<int>& encoding;

    int nextImpl(int n) {
      while (i < encoding.size() && encoding[i] == 0)
        i += 2;

      if (i == encoding.size())
        return -1;

      if (n <= encoding[i]) {
        rem = n;
        return encoding[i + 1];
      }
      else {
        n -= encoding[i];
        i += 2;
        return nextImpl(n);
      }
    }

  public:
    RLEIterator(vector<int>& _e): i(0), rem(0), encoding(_e) { }
    
    int next(int n) {
      return nextImpl(n + rem);
    }
};


int main() {
  UFUNCX(
    CTOR(vector<int>&),
    &RLEIterator::next
  );
  return 0;
}