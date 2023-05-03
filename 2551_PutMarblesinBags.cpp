#include <local_leetcode.hpp>

class Solution {
  private:
    template <class Comp>
    int64_t kExtremeSum(const vector<int>& pairs, int k, Comp comp) {
      if (k == 0)
        return 0;

      int64_t sum = 0;

      // Comp = less -> max heap
      priority_queue<int, vector<int>, Comp> heap;

      int i = 0;
      for (; i < k; ++i) {
        sum += pairs[i];
        heap.push(pairs[i]);
      }

      for (; i < (int) pairs.size(); ++i)
        if (comp(pairs[i], heap.top())) {
          sum += pairs[i] - heap.top();
          heap.pop();
          heap.push(pairs[i]);
        }

      return sum;
    }

  public:
    long long putMarbles(vector<int>& weights, int k) {
      int n = (int) weights.size() - 1;
      --k;

      vector<int> pairs(n);

      for (int i = 0; i < n; ++i)
        pairs[i] = weights[i] + weights[i+1];

      if (n > 2 * k)
        return kExtremeSum(pairs, k, greater<int>()) - kExtremeSum(pairs, k, less<int>());
      else {
        sort(pairs.begin(), pairs.end());

        int64_t res = 0;
        for (int i = 0; i < n - k; ++i)
          res += pairs[n-1 - i] - pairs[i];

        return res;
      }
    }
};


int main() {
  EXECS(Solution::putMarbles);
  return 0;
}