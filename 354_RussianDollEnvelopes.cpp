#include <set>
#include "utils2.hpp"


class Solution {
  private:
    int binarySearch(vector<int>& arr, vector<int>& cnt, int target) {
      if (arr[0] >= target)
        return 0;

      int l=0, r=arr.size()-1;
      while (l < r) {
        int m = l + (r-l+1) / 2;

        if (arr[m] >= target)
          r = m-1;
        else
          l = m;
      }

      return cnt[l];
    }


    bool strictSmaller(vector<int>& x, vector<int>& y) const {
      return x[0] < y[0] && x[1] < y[1];
    }

  public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
      sort(
        envelopes.begin(), 
        envelopes.end(),
        [](const vector<int>& x, const vector<int>& y) -> bool {
          return x[0] == y[0] ? x[1] > y[1] : x[0] < y[0]; 
        }
      );

      set<int> s;
      for (int i=0; i<envelopes.size(); ++i) {
        auto iter = s.lower_bound(envelopes[i][1]);
        if (iter != s.end())
          s.erase(iter);
        s.insert(envelopes[i][1]);
      }

      return s.size();
    }

    int maxEnvelopesSlow(vector<vector<int>>& envelopes) {
      sort(
        envelopes.begin(), 
        envelopes.end(),
        [](const vector<int>& x, const vector<int>& y) -> bool {
          return x[0] == y[0] ? x[1] < y[1] : x[0] < y[0]; 
        }
      );

      int n = envelopes.size();
      vector<int> dp(n, 1);
      int res = 1;
      for (int i=0; i<n; ++i)
        for (int j=0; j<i; ++j) 
          if (strictSmaller(envelopes[j], envelopes[i])) {
            dp[i] = max(dp[i], dp[j] + 1);
            res = max(res, dp[i]);
          }
      
      
      return res;
    }


    int maxEnvelopesTLE(vector<vector<int>>& envelopes) {
      map<int, vector<int>> m;
      for (vector<int>& e : envelopes)
        m[e[0]].push_back(e[1]);

      map<int, vector<int>> dp;
      for (auto& p : m) {
        sort(p.second.begin(), p.second.end());
        dp[p.first].assign(p.second.size(), 1);
      }

      int res = 1;

      auto i = m.begin(); ++i;
      auto j = dp.begin(); ++j;
      while (i != m.end()) {
        vector<int>& temp = j->second;

        for (int k=0; k<temp.size(); ++k) {
          int curr = 0;
          for (auto p=m.begin(), q=dp.begin(); p!=i; ++p, ++q) 
            curr = max(curr, binarySearch(p->second, q->second, i->second[k]));

          temp[k] += curr;
        }

        res = max(res, temp.back());

        ++i;
        ++j;
      }

      return res;
    }


    int maxEnvelopesWrong(vector<vector<int>>& envelopes) {
      map<int, vector<int>> m;
      for (vector<int>& e : envelopes)
        m[e[0]].push_back(e[1]);

      for (auto& p : m)
        sort(p.second.begin(), p.second.end());

      int res = 1;

      auto i = m.begin();
      auto j = m.begin(); ++j;

      vector<int> prev, next;
      prev.assign(i->second.size(), 1);
      while (j != m.end()) {
        next.assign(j->second.size(), 1);

        for (int k=0; k<next.size(); ++k)
          next[k] += binarySearch(i->second, prev, j->second[k]);

        res = max(res, next.back());

        ++i;
        ++j;
        prev = std::move(next);
      }

      return res;
    }
};


int main() {
  {
    UFUNC(Solution::maxEnvelopes);
  }
  {
    UFUNC(Solution::maxEnvelopesSlow);
  }
  {
    UFUNC(Solution::maxEnvelopesTLE);
  }
  return 0;
}