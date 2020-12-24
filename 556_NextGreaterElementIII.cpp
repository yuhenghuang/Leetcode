#include "utils.hpp"

class Solution {
  private:
    void next_perm(string::iterator first, string::iterator last) {
      string::iterator i = last-1;
      while (i!=first && *i <= *(i-1))
        --i;

      if (i==first) {
        reverse(first, last);
        return;
      }

      string::iterator j = i;
      --i;

      while (j!=last && *i<*j)
        ++j;

      swap(*i, *(j-1));
      reverse(i+1, last);
    }

  public:
    int nextGreaterElement(int n) {
      string s = to_string(n);
      // next_permutation(s.begin(), s.end());
      next_perm(s.begin(), s.end());
      long res = stol(s);
      return (res > INT_MAX || res <= n) ? -1 : res;
    }
};


int main() {
  UFUNC(Solution::nextGreaterElement);
  return 0;
}