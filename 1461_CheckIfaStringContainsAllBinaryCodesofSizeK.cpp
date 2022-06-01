#include <local_leetcode.hpp>

class Solution {
  public:
    bool hasAllCodes(string s, int k) {
      unordered_set<int> hashSet;
      
      const int mask = (1 << k) - 1;
      
      int n = s.size();
      int tmp = 0;
      for (int i=0; i<n; ++i) {
        tmp <<= 1;
        tmp &= mask;
        tmp ^= s[i] - '0';
        
        if (i >= k - 1)
          hashSet.insert(tmp);
      }
      
      return hashSet.size() == (1 << k);
    }
};


int main() {
  EXECS(Solution::hasAllCodes);
  return 0;
}