#include "utils3.hpp"

class Solution {
  private:
    struct Comparator {
      bool operator()(const vector<int>& x, const int& y) const { return x[0] < y; }
      bool operator()(const int& x, const vector<int>& y) const { return x < y[0]; }
    };

    int binary_search(const vector<vector<int>>& fruits, int pos, bool lbound = true) {
      typedef vector<vector<int>>::const_iterator iter_t;

      iter_t (*fn)(iter_t, iter_t, const int&, Comparator);
      // ternary operator doesn't work with implicit deduction
      if (lbound)
        fn = lower_bound;
      else
        fn = upper_bound;

      return fn(fruits.cbegin(), fruits.cend(), pos, Comparator()) - fruits.cbegin();
    }

    // sum over [start, end]
    int subarray_sum(int s, int e, const vector<vector<int>>& fruits, const vector<int>& prefix) {
      return prefix[binary_search(fruits, e, false)] - prefix[binary_search(fruits, s)];
    }

  public:
    int maxTotalFruits(vector<vector<int>>& fruits, const int startPos, const int k) {
      int n = fruits.size();

      vector<int> prefix(n+1);
      for (int i = 0; i < n; ++i)
        prefix[i+1] = prefix[i] + fruits[i][1];

      // go to either direction without changing direciont during the course
      int res = max(
        subarray_sum(startPos - k, startPos, fruits, prefix),
        subarray_sum(startPos, startPos + k, fruits, prefix)
      );

      for (auto& f : fruits) 
        if (f[0] < startPos - k / 2)
          continue;
        else if (f[0] <= startPos + k / 2) {
          // first go to f[0] and turn back
          // never optimal to turn twice
          // one end of the subarray is f[0]
          // the other is 2 * f[0] - startPos +(-) k

          int temp = f[0] < startPos ? \
            subarray_sum(f[0],  2 * f[0] - startPos + k, fruits, prefix) : \
            subarray_sum(2 * f[0] - startPos - k, f[0], fruits, prefix);

          if (temp > res)
            res = temp;
        }
        else
          break;

      return res;
    }
};


int main() {
  UFUNCS(Solution::maxTotalFruits);
  return 0;
}