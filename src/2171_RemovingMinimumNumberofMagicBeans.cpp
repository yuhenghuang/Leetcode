#include <local_leetcode.hpp>

class Solution {
  public:
    long long minimumRemoval(vector<int>& beans) {
      sort(beans.begin(), beans.end());

      int n = beans.size();

      long long sum = 0;
      for (int i = 0; i < n; ++i)
        sum += beans[i];

      long long res = sum;
      for (int i = 0; i < n; ++i) 
        res = min(res, sum - (long long) (n - i) * beans[i]);

      return res;
    }
};


int main() {
  EXECS(Solution::minimumRemoval);
  return 0;
}