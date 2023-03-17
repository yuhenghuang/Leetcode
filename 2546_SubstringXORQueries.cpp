#include <local_leetcode.hpp>

class Solution {
  public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
      const int n = s.size();

      unordered_map<int, int> m[30]; // length - 1, (value, left index)
      {
        int i = find(s.begin(), s.end(), '0') - s.begin();
        if (i < n)
          m[0][0] = i;

        int j = find(s.begin(), s.end(), '1') - s.begin();
        if (j < n)
          m[0][1] = j;
      }
      for (int i = 1; i < min(30, n); ++i) {
        int j = 0;
        auto iter = s.rbegin();

        int value = 0;
        for (; j < i; ++j, (void) ++iter)
          value ^= (*iter - '0') << j;

        value <<= 1;
        for (; j < n; ++j, (void) ++iter) {
          value = ((*iter - '0') << i) | (value >> 1);

          if (*iter == '1')
            m[i][value] = n - j - 1;
        } 
      }

      vector<vector<int>> res;
      for (auto& q : queries) {
        int value = q[0] ^ q[1];
        // migrate to std::countl_zero after c++20
        int index = value > 0 ? numeric_limits<int>::digits - __builtin_clz(value) : 0; // length - 1

        auto iter = m[index].find(value);
        if (iter != m[index].end())
          res.push_back({iter->second, iter->second + index});
        else
          res.push_back({-1, -1});
      }

      return res;
    }
};


int main() {
  EXECS(Solution::substringXorQueries);
  return 0;
}