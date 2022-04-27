#include <local_leetcode.hpp>

class Solution {
  private:
    vector<int> sortUniques(const vector<int>& nums) {
      set<int> s(nums.begin(), nums.end());

      vector<int> out(s.begin(), s.end());

      return out;
    }

    void update(vector<int>& bit, int i) {
      for (; i < bit.size(); i += i & (-i))
        ++bit[i];
    }

    int query(const vector<int>& bit, int i) {
      int res = 0;
      for (; i > 0; i -= i & (-i))
        res += bit[i];

      return res;
    }

  public:
    int reversePairs(vector<int>& nums) {
      vector<int>&& sorted = sortUniques(nums);

      int n = sorted.size();

      // binary index tree
      vector<int> bit(n + 1);

      int res = 0;
      for (int i = 0; i < nums.size(); ++i) {
        const int& num = nums[i];

        // handle overflow
        if (num < -(1 << 30))
          res += i;
        else if (num < (1 << 30)) {
          // sorted[j] > num * 2l
          // int j = upper_bound(sorted.begin(), sorted.end(), num * 2) - sorted.begin();

          // actually j - 1 + 1
          res += i - \
            query(
              bit,
              upper_bound(sorted.begin(), sorted.end(), num * 2) - sorted.begin()
            );
        }

        update(
          bit,
          lower_bound(sorted.begin(), sorted.end(), num) - sorted.begin() + 1
        );
      }

      return res;
    }
};


int main() {
  EXECS(Solution::reversePairs);
  return 0;
}