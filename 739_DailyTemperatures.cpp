#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      int n = temperatures.size();

      vector<int> res(n);
      stack<pair<int, int>> s;

      for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && temperatures[i] >= s.top().first)
          s.pop();

        if (!s.empty()) 
          res[i] = s.top().second - i;

        s.emplace(temperatures[i], i);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::dailyTemperatures);
  return 0;
}