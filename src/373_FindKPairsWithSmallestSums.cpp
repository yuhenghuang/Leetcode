#include "utils3.hpp"

class Solution {
  public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
      int m = nums1.size(), n = nums2.size();

      bool seen[k * k];
      memset(seen, 0, sizeof(seen));

      vector<vector<int>> res;

      typedef pair<int, int> pii;
      priority_queue<pii, vector<pii>, greater<pii>> heap;
      heap.emplace(0, 0);

      while (res.size() < k && !heap.empty()) {
        volatile int index = heap.top().second;
        heap.pop();
        int i = index / k, j = index % k;

        res.push_back({nums1[i], nums2[j]});

        index += k;
        if (i < m - 1 && (index < k * k) && !seen[index]) {
          heap.emplace(nums1[i+1] + nums2[j], index);
          seen[index] = true;
        }

        index += 1 - k;
        if (j < n - 1 && (index < k * k) && !seen[index]) {
          heap.emplace(nums1[i] + nums2[j+1], index);
          seen[index] = true;
        }
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::kSmallestPairs);
  return 0;
}