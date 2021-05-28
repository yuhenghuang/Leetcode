#include "utils2.hpp"

class Solution {
  public:
    int maxProduct(vector<string>& words) {
      unordered_map<int, int> m;
      for (const string& w : words) {
        int temp = 0;
        for (char c : w) 
          temp |= (1 << (c - 'a'));

        m[temp] = max(m[temp], (int) w.size());
      }

      int res = 0;
      for (auto& p : m) 
        for (auto& q : m)
          if ((p.first & q.first) == 0)
            res = max(res, p.second * q.second);

      return res;
    }
};


int main() {
  UFUNC(Solution::maxProduct);
  return 0;
}