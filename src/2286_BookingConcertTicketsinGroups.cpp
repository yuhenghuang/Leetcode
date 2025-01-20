#include <local_leetcode.hpp>

// sum binary index tree
class BinaryIndexTree {
  private:
    vector<int64_t> vec;

  public:
    BinaryIndexTree(int n, int m): vec(n+1) {
      for (int i = 0; i < n; ++i)
        update(i, m);
    }

    void update(int i, int64_t diff) {
      // 0-base -> 1-base
      for (++i; i < vec.size(); i += i & (-i))
        vec[i] += diff;
    }

    int64_t query(int i) {
      if (i < 0)
        return 0;

      int64_t res = 0;

      for (++i; i > 0; i -= i & (-i))
        res += vec[i];

      return res;
    }
};

// max segment tree
class SegmentTree {
  private:
    int n;
    vector<int> st;

    int getMid(int s, int e) {
      return s + (e - s) / 2;
    }

    int updateUtil(int qi, int ss, int se, int val, int si) {
      if (ss <= qi && qi <= se) {
        if (ss != se) {
          int mid = getMid(ss, se);

          return st[si] = max(
            updateUtil(qi, ss, mid, val, si * 2 + 1),
            updateUtil(qi, mid + 1, se, val, si * 2 + 2)
          );
        }
        else
          return st[si] = val;
      }
      else
        return st[si];
    }

    int queryUtil(int qs, int qe, int ss, int se, int si) {
      if (ss > qe || se < qs)
        return 0;
      else if (qs <= ss && se <= qe)
        return st[si];
      
      int mid = getMid(ss, se);
      return max(
        queryUtil(qs, qe, ss, mid, si * 2 + 1),
        queryUtil(qs, qe, mid + 1, se, si * 2 + 2)
      );
    }

  public:
    SegmentTree(int n, int m): n(n) {
      int i = 1;
      while ((1 << i) < n)
        ++i;

      st.assign((1 << ++i) - 1, m);
    }

    void update(int i, int val) {
      updateUtil(i, 0, n - 1, val, 0);
    }
    
    int maxRange(int left, int right) {
      return queryUtil(left, right, 0, n - 1, 0);
    }
};


class BookMyShow {
  private:
    BinaryIndexTree bit;
    SegmentTree st;
    vector<int> seats; // # of remaining seats
    int i, m; // current row index (before which all seats are booked) , # of total seats in a row

  public:
    BookMyShow(int n, int m): bit(n, m), st(n, m), seats(n, m), i(0), m(m) { }
    
    vector<int> gather(int k, int maxRow) {
      int l = i, r = maxRow;

      while (l <= r) {
        int m = l + (r - l) / 2;

        if (st.maxRange(i, m) < k)
          l = m + 1;
        else
          r = m - 1;
      }

      if (l <= maxRow) {
        int c = m - seats[l];
        st.update(l, seats[l] -= k);
        bit.update(l, -k);

        return {l, c};
      }
      else
        return {};
    }
    
    bool scatter(int k, int maxRow) {
      int l = i, r = maxRow;

      int64_t t = k + bit.query(i - 1);
      while (l <= r) {
        int m = l + (r - l) / 2;

        if (bit.query(m) < t)
          l = m + 1;
        else
          r = m - 1;
      }

      if (l <= maxRow) {
        i = l;
        k = t - bit.query(l - 1);

        st.update(l, seats[l] -= k);
        bit.update(l, -k);

        return true;
      }
      else
        return false;
    }
};


int main() {
  EXECX(
    CTOR(int, int),
    &BookMyShow::gather,
    &BookMyShow::scatter
  );
  return 0;
}