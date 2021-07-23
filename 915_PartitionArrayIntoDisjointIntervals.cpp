#include "utils3.hpp"


class SegmentTree {
  private:
    int n;

    const vector<int>& nums;
    vector<int> st;

    int getMid(int s, int e) {
      return s + (e-s) / 2;
    }

    int constructUtil(int ss, int se, int si) {
      if (ss == se)
        return st[si] = nums[ss];
      else {
        int sm = getMid(ss, se);
        return st[si] = min(
          constructUtil(ss, sm, si*2 + 1),
          constructUtil(sm+1, se, si*2 + 2)
        );
      }
    }

    int queryUtil(int qs, int qe, int ss, int se, int si) {
      if (qs <= ss && se <= qe)
        return st[si];
      else if (qs > se || qe < ss)
        return INT_MAX;

      int sm = getMid(ss, se);
      return min(
        queryUtil(qs, qe, ss, sm, si*2 + 1),
        queryUtil(qs, qe, sm+1, se, si*2 + 2)
      );
    }

  public:
    SegmentTree(vector<int>& _nums): n(_nums.size()), nums(_nums) {
      int i = 1;
      while ((1 << i) < n)
        ++i;

      st.resize((1 << (i + 1)) - 1);

      constructUtil(0, n-1, 0);
    }

    int query(int i) {
      return queryUtil(i, n-1, 0, n-1, 0);
    }
};


class Solution {
  public:
    int partitionDisjoint(vector<int>& nums) {
      SegmentTree st(nums);

      int m = INT_MIN;
      for (int i = 1; i < nums.size(); ++i) {
        m = max(nums[i - 1], m);

        if (m <= st.query(i))
          return i;
      }

      return -1;
    }

    int partitionDisjointOn(vector<int>& nums) {
      int n = nums.size();
      vector<int> dp(n);
      int m = INT_MAX;
      for (int i = n-1; i >= 0; --i) {
        if (nums[i] < m) m = nums[i];

        dp[i] = m;
      }

      m = INT_MIN;
      for (int i = 1; i < n; ++i) {
        m = max(nums[i-1], m);

        if (m <= dp[i]) return i;
      }

      return -1;
    }
};


int main() {
  UFUNCS(Solution::partitionDisjoint);
  UFUNCS(Solution::partitionDisjointOn);
  return 0;
}