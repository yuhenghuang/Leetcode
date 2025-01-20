#include <local_leetcode.hpp>

class Solution {
  private:
    static int bits[10001];
    static bool __helper;

    static bool init() {
      bits[0] = 0;
      for (int i = 1; i <= 10000; ++i)
        bits[i] = (i & 1) + bits[i >> 1];

      return true;
    }

  public:
    vector<int> sortByBits(vector<int>& arr) {
      sort(
        arr.begin(), arr.end(),
        [] (int x, int y) {
          return bits[x] == bits[y] ? x < y : bits[x] < bits[y]; 
        }
      );

      return arr;
    }
};

int Solution::bits[];
bool Solution::__helper = Solution::init();


int main() {
  EXECS(Solution::sortByBits);
  return 0;
}