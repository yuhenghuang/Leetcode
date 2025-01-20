#include <local_leetcode.hpp>

class Solution {
  public:
    double average(vector<int>& salary) {
      int sum = reduce(salary.begin(), salary.end());

      auto p = minmax_element(salary.begin(), salary.end());

      sum -= *p.first + *p.second;

      return sum / (static_cast<double>(salary.size()) - 2.0);
    }
};


int main() {
  EXECS(Solution::average);
  return 0;
}