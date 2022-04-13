#include <local_leetcode.hpp>

class Solution {
  private:
    long long binary_search(vector<int>& flowers, vector<long long>& prefix, int target, long long newFlowers, int i, int j) {
      // if current garden already has more flowers than target
      if (i > j || flowers[j-1] >= target)
        return 0;

      while (i < j) {
        int m = i + (j - i) / 2;

        if ((prefix[m] + newFlowers) / m > flowers[m])
          i = m + 1;
        else
          j = m;
      }

      return (prefix[i] + newFlowers) / i;
    }

  public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, long long full, long long partial) {
      // wrong

      int n = flowers.size();

      sort(flowers.begin(), flowers.end());

      vector<long long> prefix(n + 1);
      for (int i = 0; i < n; ++i)
        prefix[i+1] = prefix[i] + flowers[i];

      // incomplete gardens only
      long long res = min(target - 1LL, binary_search(flowers, prefix, target, newFlowers, 1, n)) * partial;

      for (int i = n - 1; i >= 0; --i) {
        newFlowers -= max(0, target - flowers[i]);

        // early stop if no new flowers available
        if (newFlowers < 0)
          break;

        res = max(res, (n - i) * full + min(target - 1LL, binary_search(flowers, prefix, target, newFlowers, 1, i)) * partial);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maximumBeauty);
  return 0;
}