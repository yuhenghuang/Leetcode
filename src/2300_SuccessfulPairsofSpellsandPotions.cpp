#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
      int n = spells.size();

      vector<int> indices(n);
      iota(indices.begin(), indices.end(), 0);

      sort(
        indices.begin(), indices.end(),
        [&spells] (int i, int j) { return spells[i] < spells[j]; }
      );

      sort(potions.begin(), potions.end(), greater<>());

      vector<int> res(n);

      int j = 0;
      for (int i : indices) {
        int64_t spell = spells[i];
        for (; j < (int) potions.size() && spell * potions[j] >= success; ++j);

        res[i] = j;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::successfulPairs);
  return 0;
}