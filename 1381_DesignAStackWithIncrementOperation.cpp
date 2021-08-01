#include "utils3.hpp"

class CustomStack {
  private:
    size_t max_size;
    stack<int> s;
    vector<int> inc;

  public:
    CustomStack(int maxSize): max_size(maxSize), inc(maxSize) { }
    
    void push(int x) {
      if (s.size() < max_size)
        s.push(x);
    }
    
    int pop() {
      if (s.empty())
        return -1;

      int i = s.size() - 1;

      int res = inc[i];
      inc[i] = 0;
      if (i > 0)
        inc[i-1] += res;

      res += s.top();
      s.pop();
      return res;
    }
    
    void increment(int k, int val) {
      if (!s.empty()) 
        inc[min((int)s.size(), k) - 1] += val;
    }
};


int main() {
  UFUNCX(
    CTOR(int),
    &CustomStack::push,
    &CustomStack::pop,
    &CustomStack::increment
  );
  return 0;
}