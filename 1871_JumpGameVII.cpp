#include "utils3.hpp"

class Solution {
  private:
    bool valid(vector<int>& prefix, int i, int j) {
      if (i < 0)
        return true;

      // contains 0 in [i, j]
      return j - i + 1 > prefix[j+1] - prefix[i];
    }

  public:
    bool canReachTLE(string s, int minJump, int maxJump) {
      if (s.back() == '1')
        return false;

      int n = s.size();
      vector<bool> seen(n);

      queue<int> q;
      q.push(0);

      while (!q.empty()) {
        int i = q.front();
        q.pop();
        
        for (int j = i + minJump; j <= min(i + maxJump, n - 1); ++j)
          if (!seen[j]) {
            if (j == n - 1)
              return true;

            seen[j] = true;

            if (s[j] == '0')
              q.push(j);
          }
      }

      return false;
    }

    bool canReach(string s, int minJump, int maxJump) {
      if (s.back() == '1')
        return false;

      int n = s.size();

      vector<int> prefix(n + 1);
      for (int i = 0; i < n; ++i)
        prefix[i+1] = prefix[i] + (s[i] - '0');

      // reachable interval
      int l = minJump;
      int r = maxJump;

      while (r < n - 1) {
        int ll = INT_MAX;
        int rr;

        // loop over current interval
        for (int i = l; i <= min(r, n-1); ++i)
          // s[i] is '0' and i is reachable by verifying whether 0 exists in [i - maxJump, i - minJump]
          // this validator will fail on left or right bounds 
          // where i - maxJump is less than last interval's left bound or i - minJump is larger than interval's right bound
          // but those cases won't happen because [i, i + maxJump - minJump] and [j - maxJump + minJump, j] are always valid
          // check how the [i, j] is updated!
          if (s[i] == '0' && valid(prefix, i - maxJump, i - minJump)) {
            if (ll == INT_MAX)
              ll = i + minJump;
            
            rr = i + maxJump;
          }

        // early stop
        if (ll == INT_MAX)
          return false;

        l = max(r+1, ll);
        r = rr;
      }

      return l < n && valid(prefix, n-1-maxJump, n-1-minJump);
    }
};


int main() {
  UFUNCS(Solution::canReach);
  UFUNCS(Solution::canReachTLE);
  return 0;
}