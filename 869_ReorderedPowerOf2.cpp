#include "utils2.hpp"

class Solution {
  private:
    unordered_multimap<int, vector<int>> m;

    pair<int, vector<int>> compress(int i) {
      string s = to_string(i);
      pair<int, vector<int>> p;

      p.first = s.size();
      p.second.resize(10);

      for (char c : s)
        ++p.second[c-'0'];

      return p;
    }

    bool compare(const vector<int>& x, const vector<int>& y) {
      if (x.size() == y.size()) {
        for (int i=0; i<x.size(); ++i)
          if (x[i] != y[i])
            return false;

        return true;
      }
      return false;
    }

  public:
    Solution() {
      for (int s=0; s<31; ++s)
        m.insert(compress(1 << s));
    }

    bool reorderedPowerOf2(int N) {
      auto p = compress(N);

      auto [st, ed] = m.equal_range(p.first);
      for (;st != ed; ++st) 
        if (compare(st->second, p.second))
          return true;

      return false;
    }
};


int main() {
  UFUNC(Solution::reorderedPowerOf2);
  return 0;
}