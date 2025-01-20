#include <local_leetcode.hpp>

class Solution {
  public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
      typedef pair<int, int> ii_t;
      vector<ii_t> nums;
      transform(
        nums1.begin(), nums1.end(),
        nums2.begin(),
        back_inserter(nums),
        [] (int i, int j) -> ii_t { return {i, j}; }
      );

      // sort by nums2 in descending order
      sort(
        nums.begin(), nums.end(),
        [] (const ii_t& p, const ii_t& q) { return p.second > q.second; }
      );

      int i = 0; // global index of nums
      int64_t sum = 0; // sum of subsequence in nums1

      priority_queue<int, vector<int>, greater<int>> heap; // max heap of values in nums1

      for (; i < k; ++i) {
        int num1 = nums[i].first;
        heap.push(num1);
        sum += num1;
      }

      int64_t res = sum * nums[i-1].second;

      for (; i < (int) nums.size(); ++i) {
        auto& [num1, num2] = nums[i];
        if (num1 > heap.top()) {
          sum += num1 - heap.top();

          heap.pop();
          heap.push(num1);

          res = max(res, sum * num2);
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maxScore);
  return 0;
}