#include "utils2.hpp"

// any large number that does not cause overflow
static constexpr int mod = (1 << 22) - 9;

class Solution {
  private:
    // compute the module of exponential multiplier
    // $r^k % mod$
    int computeMultiplier(int r, int k) {
      int res = r;
      while (--k)
        res = (res * r) % mod;

      return res;
    }

    // compare subarrays of length k of two arrays end at i and j respectively
    bool compareSubarray(int i, int j, int k, vector<int>& nums1, vector<int>& nums2) {
      while (k--) 
        if (nums1[i--] != nums2[j--])
          return false;

      return true;
    }

  public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
      int n1 = nums1.size(), n2 = nums2.size();

      int res = 0;

      // pair of hash value and index of end of subarray
      unordered_multimap<int, int> m;

      // left and right bound of binary search
      int l = 1, r = min(n1, n2);
      while (l <= r) {
        int k = l + (r - l) / 2;

        int multiplier = computeMultiplier(1 << 7, k);
        int hashVal = 0;

        m.clear();
        // compute hash values of subarrays by rolling hashing
        for(int i = 0; i < n1; ++i) {
          hashVal = ((hashVal << 7) + nums1[i]) % mod;

          if (i >= k - 1) {
            if (i >= k)
              hashVal = (hashVal + mod - ((nums1[i-k] * multiplier) % mod)) % mod;

            // subarray of length k ends at i
            m.emplace(hashVal, i);
          }
        } 


        hashVal = 0;
        bool flag = false;
        for (int i = 0; i < n2; ++i) {
          hashVal = ((hashVal << 7) + nums2[i]) % mod;

          if (i >= k - 1) {
            if (i >= k)
              hashVal = (hashVal + mod - ((nums2[i-k] * multiplier) % mod)) % mod;

            // use multimap and for loop to avoid the same hash values of different subarray
            for (auto [bg, ed] = m.equal_range(hashVal); bg != ed; ++bg)
              if (compareSubarray(bg->second, i, k, nums1, nums2)) {
                flag = true;
                break;
              }

            // if found, update result
            if (flag) {
              res = max(res, k);
              break;
            }
          }
        }
        
        // update left or right bound of binary search
        if (flag)
          l = k + 1;
        else
          r = k - 1;
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::findLength);
  return 0;
}