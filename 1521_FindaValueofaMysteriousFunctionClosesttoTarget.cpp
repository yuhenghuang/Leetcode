#include <local_leetcode.hpp>

class SegmentTree {
  private:
    int n;
    vector<int> st;

  int getMid(int s, int e) {
    return s + (e - s) / 2;
  }

  int constructImpl(vector<int>& arr, int ss, int se, int si) {
    if (ss == se) 
      return st[si] = arr[ss];

    int sm = getMid(ss, se);
    return st[si] = constructImpl(arr, ss, sm, si*2 + 1) & constructImpl(arr, sm+1, se, si*2 + 2);
  }

  int queryImpl(int qs, int qe, int ss, int se, int si) {
    if (qs > se || qe < ss)
      return -1; // all bits being 1
    else if (qs <= ss && se <= qe)
      return st[si];

    int sm = getMid(ss, se);

    return queryImpl(qs, qe, ss, sm, si*2 + 1) & queryImpl(qs, qe, sm+1, se, si*2 + 2);
  }

  public:
    SegmentTree(vector<int>& arr): n(arr.size()) {
      int i = 1;
      while (i < n)
        i <<= 1;

      i <<= 1;

      st.resize(i - 1);

      constructImpl(arr, 0, n-1, 0);
    }

    int query(int s, int e) {
      return queryImpl(s, e, 0, n-1, 0);
    }
};

class Solution {
  public:
    int closestToTarget(vector<int>& arr, int target) {
      // TLE???? WTF
      // O(n(logn)^2)

      int n = arr.size();

      SegmentTree st(arr);

      int res = INT_MAX;
      for (int i = 0; i < n; ++i) {
        int l = i, r = n - 1;

        while (l < r) {
          // ceiling((r + l) / 2)
          int m = l + (r - l) / 2 + ((r - l) & 1);

          if (st.query(i, m) < target)
            r = m - 1;
          else
            l = m;
        }

        int temp = st.query(i, r);
        
        if (temp >= target) {
          res = min(res, temp - target);

          if (r < n - 1)
            res = min(res, target - (temp & arr[r+1]));
        }
        else
          res = min(res, target - temp);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::closestToTarget);
  return 0;
}