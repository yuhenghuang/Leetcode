#include <local_leetcode.hpp>

class Solution {
  public:
    int maxOperations(vector<int>& nums, int k) {
      map<int, int> m;
      for (int num : nums)
        ++m[num];

      int res = 0;
      for (auto& [num, freq] : m) {
        // early stop
        if (num * 2 > k)
          break;
        else if (num * 2 == k)
          res += freq / 2;
        else {
          auto conj = m.find(k - num);
          if (conj != m.end()) 
            res += min(freq, conj->second);
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maxOperations);
  return 0;
}