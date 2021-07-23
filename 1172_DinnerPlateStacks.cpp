#include <set>
#include "utils3.hpp"

class DinnerPlates {
  private:
    size_t capacity;

    vector<stack<int>> stacks;

    // indicies of non-empty stacks to pop
    priority_queue<int, vector<int>> non_empty;
    // indicies of non-full stacks to push
    priority_queue<int, vector<int>, greater<int>> non_full;

  public:
    DinnerPlates(int _cap): capacity(_cap) { }
    
    void push(int val) {
      if (non_full.empty()) {
        non_empty.push(stacks.size());

        if (capacity != 1)
          non_full.push(stacks.size());

        stacks.emplace_back().push(val);
      }
      else {
        stack<int>& s = stacks[non_full.top()];

        if (s.size() == 0)
          non_empty.push(non_full.top());

        s.push(val);

        if (s.size() == capacity)
          non_full.pop();
      }
    }
    
    int pop() {
      while (!non_empty.empty()) {
        int index = non_empty.top();
        stack<int>& s = stacks[index];
        if (s.size() == 0)
          non_empty.pop();
        else {
          int tmp = s.top();

          if (s.size() == capacity)
            non_full.push(index);

          s.pop();

          return tmp;
        }
      }

      return -1;
    }
    
    int popAtStack(int index) {
      if (index >= stacks.size() || stacks[index].empty())
        return -1;

      stack<int>& s = stacks[index];

      if (s.size() == capacity)
        non_full.push(index);

      int tmp = s.top();
      s.pop();

      return tmp;
    }
};


int main() {
  UFUNCX(
    CTOR(int),
    &DinnerPlates::push,
    &DinnerPlates::pop,
    &DinnerPlates::popAtStack
  );
  return 0;
}