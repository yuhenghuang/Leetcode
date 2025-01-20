#include <local_leetcode.hpp>

class SegmentTree {
  private:
    int n;
    vector<int> st;

    void add(int qi, int ss, int se, int si) {
      if (qi < ss || qi > se)
        return;
      else
        ++st[si];

      if (ss != se) {
        int sm = ss + (se - ss) / 2;

        add(qi, ss, sm, si*2 + 1);
        add(qi, sm+1, se, si*2 + 2);
      }
    }

    int query(int qs, int qe, int ss, int se, int si) {
      if (qs > se || qe < ss)
        return 0;
      else if (qs <= ss && se <= qe)
        return st[si];

      int sm = ss + (se - ss) / 2;

      return query(qs, qe, ss, sm, si*2 + 1) + query(qs, qe, sm + 1, se, si*2 + 2);
    }

  public:
    SegmentTree(int _n): n(_n) {
      int i = 1;
      while ((1 << i) < n)
        ++i;

      st.resize((1 << (i + 1)) - 1);
    }

    // reset segment tree
    void reset() { st.assign(st.size(), 0); }

    // add index i by 1
    void add(int i) { add(i, 0, n-1, 0); }

    // query the sum (# of elements) in [i, j]
    int query(int i, int j) {
      // corner cases
      if (i > j)
        return 0;

      return query(i, j, 0, n-1, 0);
    }
};


class Solution {
  private:

    // increment index j - 1
    void add(vector<int>& bit, int j) {

      for (; j < bit.size(); j += j & (-j))
        ++bit[j];
    }

    // sum over [0, j)
    int query(vector<int>& bit, int j) {
      int res = 0;

      for (; j > 0; j -= j & (-j))
        res += bit[j];

      return res;
    }

  public:
    // binary index tree version
    long long goodTripletsBIT(vector<int>& nums1, vector<int>& nums2) {
      const int n = nums1.size();

      vector<int> index2(n);
      for (int i = 0; i < n; ++i)
        index2[nums2[i]] = i;

      // num of common numbers before index i in num1
      vector<int> dp(n);

      // binary index tree
      vector<int> bit(n + 1);

      for (int i = 0; i < n; ++i) {
        int j = index2[nums1[i]];

        dp[i] = query(bit, j);
        add(bit, j + 1);
      }

      bit.assign(n+1, 0);

      long long res = 0;

      for (int i = n - 1; i >= 0; --i) {
        int j = index2[nums1[i]];

        res += static_cast<long long>(dp[i]) * (n - i - 1 - query(bit, j + 1));
        add(bit, j + 1);
      }

      return res;
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
      const int n = nums1.size();

      vector<int> index2(n);
      for (int i = 0; i < n; ++i)
        index2[nums2[i]] = i;

      // num of common numbers before index i in num1
      vector<int> dp(n);

      SegmentTree st(n);
      for (int i = 0; i < n; ++i) {
        int j = index2[nums1[i]];

        dp[i] = st.query(0, j - 1);
        st.add(j);
      }

      st.reset();

      long long res = 0;

      for (int i = n - 1; i >= 0; --i) {
        int j = index2[nums1[i]];

        res += static_cast<long long>(st.query(j + 1, n - 1)) * dp[i];
        st.add(j);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::goodTriplets);
  EXECS(Solution::goodTripletsBIT);
  return 0;
}