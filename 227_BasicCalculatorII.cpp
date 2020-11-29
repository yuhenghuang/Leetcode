#include "utils.hpp"


template <typename T>
stack<T> reverse_stack(stack<T>& orig) {
  stack<T> rev;
  
  while (!orig.empty()) {
    rev.push(orig.top());
    orig.pop();
  }

  return rev;
}

class Solution {
  private:
    void compute(stack<int>& nums, stack<char>& ops) {

      int lhs = nums.top();
      nums.pop();
      char op = ops.top();
      ops.pop();

      if (ops.empty() || op=='*' || op=='/' || ops.top()=='+' || ops.top()=='-') {
        switch (op) {
          case ('+'):
            nums.top() += lhs; break;
          case ('-'):
            nums.top() = lhs - nums.top(); break;
          case ('*'):
            nums.top() *= lhs; break;
          case ('/'):
            nums.top() = lhs / nums.top(); break;
          default: break;
        }
      }
      else {
        compute(nums, ops);
        nums.push(lhs);
        ops.push(op);
      }
    }

  public:
    int calculate(string s) {
      stack<int> nums;
      stack<char> ops;
      istringstream oss(s);

      int n;
      char c;
      while (oss >> n) {
        nums.push(n);
        if (oss >> c)
          ops.push(c);
      }

      nums = reverse_stack(nums);
      ops = reverse_stack(ops);

      while (!ops.empty())
        compute(nums, ops);

      return nums.top();
    }
};


int main() {
  UFUNC(Solution::calculate);
  return 0;
}