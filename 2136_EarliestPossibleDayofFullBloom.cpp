#include <local_leetcode.hpp>

class Solution {
  public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
      int n = plantTime.size();
      vector<int> indicies(n);
      iota(indicies.begin(), indicies.end(), 0);

      sort(
        indicies.begin(),
        indicies.end(),
        [&plantTime, &growTime](const int& i, const int& j) -> bool {
          return growTime[i] == growTime[j] ? plantTime[i] > plantTime[j] : growTime[i] < growTime[j];
        }
      );

      int t = reduce(plantTime.begin(), plantTime.end(), 0);
      int res = t;
      for (const int& i : indicies) {
        res = max(res, t + growTime[i]);
        t -= plantTime[i];
      }

      return res;
    }
};


int main() {
  EXECS(Solution::earliestFullBloom);
  return 0;
}