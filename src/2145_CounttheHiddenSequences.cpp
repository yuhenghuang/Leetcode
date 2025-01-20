#include <local_leetcode.hpp>

class Solution {
  public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {

      long long arr_min = 0;
      long long arr_max = 0;

      long long prev = 0;
      long long curr;
      for (int i = 0; i < differences.size(); ++i) {
        curr = prev + differences[i];

        if (curr > arr_max)
          arr_max = curr;
        else if (curr < arr_min)
          arr_min = curr;

        prev = curr;
      }

      return max(0LL, (upper - lower) - (arr_max - arr_min) + 1);
    }
};


int main() {
  EXECS(Solution::numberOfArrays);
  return 0;
}