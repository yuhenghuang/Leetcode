#include <local_leetcode.hpp>

class Solution {
  public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
      vector<int> people[500]; // group size - 1, person id

      const int n = groupSizes.size();
      for (int i = 0; i < n; ++i)
        people[groupSizes[i] - 1].push_back(i);

      vector<vector<int>> res;

      for (int i = 0; i < n; ++i) {
        vector<int>& p = people[i];
        vector<int>* group;
        for (int j = 0; j < p.size(); ++j) {
          if (j % (i + 1) == 0)
            group = &res.emplace_back();

          group->push_back(p[j]);
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::groupThePeople);
  return 0;
}