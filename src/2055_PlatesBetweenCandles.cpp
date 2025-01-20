#include "utils3.hpp"

class Solution {
  public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
      int n = s.size();

      vector<int> prefix(n + 1);
      vector<int> left(n);
      for (int i = 0; i < n; ++i) {
        if (s[i] == '*') {
          prefix[i+1] = prefix[i] + 1;
          left[i] = 1 + (i > 0 ? left[i-1] : 0);
        }
        else
          prefix[i+1] = prefix[i];
      }

      vector<int> right(n);
      right[n-1] = s[n-1] == '*';
      for (int i = n-2; i >= 0; --i)
        if (s[i] == '*')
          right[i] = 1 + right[i+1];

      vector<int> res;
      res.reserve(queries.size());

      for (auto& q : queries)
        res.push_back(max(
          prefix[q[1]+1] - prefix[q[0]] - left[q[1]] - right[q[0]],
          0
        ));

      return res;
    }
};


int main() {
  UFUNCS(Solution::platesBetweenCandles);
  return 0;
}