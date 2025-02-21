#include <local_leetcode.hpp>

class Solution {
  private:
    static int prefix[];
    static bool helper;

    static bool dfs(int num, int target) {
      if (num == target)
        return true;

      for (int m = 10; m <= num; m *= 10) {
        int left = num / m;
        int right = num % m;

        // early stop
        if (left > target)
          continue;

        if (dfs(right, target - left))
          return true;
      }

      return false;
    }

    static bool init() {      
      prefix[0] = 0;
      for (int i = 1; i <= 1000; ++i)
        prefix[i] = prefix[i-1] + (dfs(i * i, i) ? (i * i) : 0);
      
      return true;
    }

  public:
    int punishmentNumber(int n) {
      return prefix[n];
    }
};

int Solution::prefix[1001];
bool Solution::helper = Solution::init();

int main() {
  EXECS(Solution::punishmentNumber);
  return 0;
}