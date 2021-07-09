#include <set>
#include "utils2.hpp"


class Solution {
  public:
    int minSetSize(vector<int>& arr) {
      int n = arr.size();
      int target = n / 2;

      unordered_map<int, int> m;
      for (int num : arr)
        ++m[num];

      vector<int> cnt;
      cnt.reserve(m.size());

      for (auto& p : m)
        cnt.push_back(p.second);

      sort(cnt.begin(), cnt.end(), greater<int>());

      int res = 0;
      auto iter = cnt.begin();
      while (n > target) {
        n -= *iter++;
        ++res;
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::minSetSize);
  return 0;
}