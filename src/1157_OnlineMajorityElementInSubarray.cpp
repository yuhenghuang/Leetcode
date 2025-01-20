#include "utils3.hpp"

// hint for faster solution!!!
// record indices of specified number and count occurrences via binary search
// slow ( O((logn)^2) ) but well-formed?
// utilise the condition (max freq of num > half) fairly well
class MajorityChecker {
  private:
    int n;

    const vector<int>& arr;
    // count of value
    vector<unordered_map<int, int>> st_count;
    // pair of value and max frequency
    vector<pair<int, int>> st_maxfreq;

    int getMid(int s, int e) { return s + (e-s) / 2; }

    const unordered_map<int,int>& constructUtil(int ss, int se, int si) {
      unordered_map<int, int>& m = st_count[si];
      if (ss == se) 
        m[arr[ss]] = 1;
      else {
        int sm = getMid(ss, se);
        m = constructUtil(ss, sm, si*2 + 1);
        for (auto& p : constructUtil(sm + 1, se, si*2 + 2))
          m[p.first] += p.second;
      }

      pair<int, int>& f = st_maxfreq[si];
      for (auto& p : m)
        if (p.second > f.second)
          f = p;

      return m;
    }

    // count the frequency of value
    int queryCount(int qs, int qe, int val, int ss, int se, int si) {
      if (qe < ss || qs > se)
        return 0;
      else if (qs <= ss && se <= qe) {
        unordered_map<int, int>& m = st_count[si];
        auto iter = m.find(val);
        return iter == m.end() ? 0 : iter->second;
      }

      int sm = getMid(ss, se);
      return queryCount(qs, qe, val, ss, sm, si*2 + 1) + 
             queryCount(qs, qe, val, sm + 1, se, si*2 + 2);
    }

    // find the pair of value and max frequency
    pair<int, int> queryUtil(int qs, int qe, int ss, int se, int si) {
      if (qe < ss || qs > se)
        return {0, 0};
      else if (qs <= ss && se <= qe)
        return st_maxfreq[si];

      int sm = getMid(ss, se);
      pair<int, int> p1 = queryUtil(qs, qe, ss, sm, si*2 + 1);
      pair<int, int> p2 = queryUtil(qs, qe, sm + 1, se, si*2 + 2);

      if (p1.first == p2.first)
        return {p1.first, p1.second + p2.second};

      p1.second = queryCount(qs, qe, p1.first, ss, se, si);
      p2.second = queryCount(qs, qe, p2.first, ss, se, si);

      return p1.second >= p2.second ? p1 : p2;
    }

  public:
    MajorityChecker(vector<int>& _arr): arr(_arr) {
      n = arr.size();

      int i = 1;
      while ((1 << i) < n)
        ++i;

      int size = (1 << (i+1)) - 1;
      st_count.resize(size);
      st_maxfreq.resize(size);

      constructUtil(0, n - 1, 0);
    }
    
    int query(int left, int right, int threshold) {
      pair<int, int> p = queryUtil(left, right, 0, n - 1, 0);
      return p.second < threshold ? -1 : p.first;
    }
};


int main() {
  UFUNCX(
    CTOR(vector<int>&),
    &MajorityChecker::query
  );
  return 0;
}