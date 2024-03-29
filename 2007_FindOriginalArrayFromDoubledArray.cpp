#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> findOriginalArray(vector<int>& changed) {
      // sort + nested loop
      // O(nlogn + n)

      int n = changed.size();

      if ((n & 1) != 0)
        return {};

      sort(changed.begin(), changed.end());
      
      // doubled array indices
      vector<bool> memo(n);

      vector<int> res;

      int j = 0;
      for (int i = 0; i < n; ++i)
        if (!memo[i]) {
          j = max(j + 1, i + 1);

          // try to find next doubled number, i.e. changed[j] == changed[i] * 2
          while (j < n && changed[j] < (changed[i] << 1))
            ++j;

          // doubled number not found, break
          if (j == n || changed[j] > (changed[i] << 1))
            break;
          
          memo[j] = true;
          res.push_back(changed[i]);
        }

      if (res.size() * 2 < n)
        return {};

      return res;
    }
};


int main() {
  EXECS(Solution::findOriginalArray);
  return 0;
}
