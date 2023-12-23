#include <local_leetcode.hpp>

class Solution {
  public:
    int minOperations(vector<int>& target, vector<int>& arr) {
      unordered_map<int, int> m;
      for (int i = 0; i < target.size(); ++i)
        m[target[i]] = i;

      vector<int> indices;
      for (int i : arr) {
        auto iter = m.find(i);
        if (iter != m.end())
          indices.push_back(iter->second);
      }

      int j = 0;
      for (int i = 0; i < indices.size(); ++i) {
        int t = indices[i];
        int k = lower_bound(indices.begin(), indices.begin() + j, t) - indices.begin();

        if (k < j)
          indices[k] = t;
        else
          indices[j++] = t;
      }

      return target.size() - j;
    }
};


int main() {
  EXECS(Solution::minOperations);
  return 0;
}