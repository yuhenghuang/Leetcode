#include <local_leetcode.hpp>

class Solution {
  public:
    int rand10() {
      int num;
      do {
        num = rand7() + (rand7() - 1) * 7;
      } while (num > 40);
      return (num-1) % 10 + 1;
    }

    vector<int> call(int n) {
      vector<int> res;
      for (int i = 0; i < n; ++i)
        res.push_back(rand10());

      return res;
    }
};


int main() {
  EXECS(Solution::call);
  return 0;
}