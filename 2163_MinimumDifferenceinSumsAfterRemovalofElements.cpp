#include <local_leetcode.hpp>

class Solution {
  private:
    template <class Iterator, template <class> class Comp>
    vector<long long> prefix_extreme_sum(Iterator begin, 
                                         int n,
                                         Comp<int> comp
                                         ) 
    {
      static_assert(
        std::is_base_of<
          std::forward_iterator_tag,
          typename std::iterator_traits<Iterator>::iterator_category
        >::value,
        "forward iterator expected"
      );

      priority_queue<int, vector<int>, Comp<int>> heap;

      vector<long long> out(n + 1);

      for (int i = 0; i < n; ++i, ++begin) {
        out[0] += *begin;
        heap.push(*begin);
      }

      for (int i = 0; i < n; ++i, ++begin) {
        if (comp(*begin, heap.top())) {
          out[i+1] = out[i] + *begin - heap.top();

          heap.pop();
          heap.push(*begin);
        }
        else
          out[i+1] = out[i];
      }

      return out;
    }

  public:
    long long minimumDifferenceTemplate(vector<int>& nums) {
      const int n = nums.size() / 3;

      vector<long long> prefix = prefix_extreme_sum(nums.begin(), n, less<int>());
      vector<long long> suffix = prefix_extreme_sum(nums.rbegin(), n, greater<int>());

      long long res = LONG_LONG_MAX;
      for (int i = 0; i <= n; ++i)
        res = min(res, prefix[i] - suffix[n - i]);

      return res;
    }


    long long minimumDifference(vector<int>& nums) {
      const int n = nums.size() / 3;

      vector<long long> dp(n + 1);

      priority_queue<int> max_heap;
      for (int i = 0; i < n; ++i) {
        dp[0] += nums[i];
        max_heap.push(nums[i]);
      }

      for (int i = 0; i < n; ++i) {
        if (nums[i+n] < max_heap.top()) {
          dp[i+1] = dp[i] + nums[i+n] - max_heap.top();

          max_heap.pop();
          max_heap.push(nums[i+n]);
        }
        else
          dp[i+1] = dp[i];
      }

      long long sum = 0;
      priority_queue<int, vector<int>, greater<>> min_heap;
      for (int i = 0; i < n; ++i) {
        const int& num = nums[i + (n << 1)];

        sum += num;
        min_heap.push(num);
      }

      long long res = dp[n] - sum;

      for (int i = n - 1; i >= 0; --i) {
        if (nums[i+n] > min_heap.top()) {
          sum += nums[i+n] - min_heap.top();

          min_heap.pop();
          min_heap.push(nums[i+n]);
        }

        res = min(res, dp[i] - sum);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::minimumDifference);
  EXECS(Solution::minimumDifferenceTemplate);
  return 0;
}