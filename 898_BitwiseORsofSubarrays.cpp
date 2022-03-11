#include <local_leetcode.hpp>

class Solution {
  public:
    int subarrayBitwiseORs(vector<int>& arr) {
      // wrong answer
      vector<int> dp;
      dp.push_back(arr[0]);

      int res = 1;
      for (int i = 1; i < arr.size(); ++i) {
        int num = arr[i];
        int j = dp.size() - 1;
        int k = j;
        for (; j >= 0; --j) {
          if (((~dp[j]) & num) > 0) 
            dp[j] = num = num | dp[j];
          else
            break;
        }

        if (k > j) {
          res += k - j;
          dp.push_back(arr[i]);
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::subarrayBitwiseORs);
  return 0;
}