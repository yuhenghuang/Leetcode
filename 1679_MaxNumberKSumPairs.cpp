#include "utils.hpp"

class Solution {
  public:
    int maxOperations(vector<int>& nums, int k) {
      map<int, int> m;
      for (int num : nums)
        ++m[num];

      int res = 0;
      for (auto iter : m) {
        if (iter.first * 2 > k)
          break;
        else if (iter.first * 2 == k)
          res += iter.second / 2;
        else {
          auto conj = m.find(k-iter.first);
          if (conj!=m.end()) 
            res += min(iter.second, conj->second);
        }
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::maxOperations);
  return 0;
}