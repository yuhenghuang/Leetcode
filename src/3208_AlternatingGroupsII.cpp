#include <local_leetcode.hpp>

class Solution {
  public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
      const int n = colors.size();
      
      int res = 0;

      for (int i = 0, j = 1; i < n; i = j++) {
        // alternating colors and length shorter than a circle
        while (colors[(j - 1) % n] != colors[j % n] and j - i < n)
          ++j;

        res += max(0, min(j - i - k + 1, n - i));

        // alternating color circle found
        if (j - i == n and colors[(j - 1) % n] != colors[j % n]) [[ unlikely ]]
          res = n;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::numberOfAlternatingGroups);
  return 0;
}