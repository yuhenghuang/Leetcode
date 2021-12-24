#include <local_leetcode.hpp>

class Solution {
  private:
    int maxIncreasingSubseq(vector<int>& arr, int s, int k) {
      vector<int> sub;
      for (int i = s; i < arr.size(); i += k) {
        auto iter = upper_bound(sub.begin(), sub.end(), arr[i]);

        if (iter == sub.end())
          sub.push_back(arr[i]);
        else
          *iter = arr[i];
      }

      return sub.size();
    }

  public:
    int kIncreasing(vector<int>& arr, int k) {
      int res = arr.size();
      for (int i = 0; i < k; ++i)
        res -= maxIncreasingSubseq(arr, i, k);

      return res;
    }
};


int main() {
  EXECS(Solution::kIncreasing);
  return 0;
}