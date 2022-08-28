#define _LL_NONTRIVIAL_SOLUTION_CTOR
#include <local_leetcode.hpp>


class Digits {
  private:
    uint8_t count[10];

  public:
    Digits(int n): count{0} {
      string&& s = to_string(n);
      for (char c : s)
        ++count[c - '0'];
    }

    struct Hash {
      size_t operator()(const Digits& d) const {
        size_t val = 0;

        for (int i = 0; i < 10; ++i)
          val = (val << 5) + d.count[i];

        return val;
      }
    };

    bool operator!=(const Digits& rhs) const {
      for (int i = 0; i < 10; ++i)
        if (count[i] != rhs.count[i])
          return true;

      return false;
    }

    bool operator==(const Digits& rhs) const { return !(*this != rhs); }
};


class Solution {
  private:
    static unordered_set<Digits, Digits::Hash> pow2;

    static unordered_set<Digits, Digits::Hash> init() {
      unordered_set<Digits, Digits::Hash> out;

      for (int i = 0; i < 31; ++i)
        out.emplace(1 << i);

      return out;
    }

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
    Solution() { }

    bool reorderedPowerOf2(int N) {
      for (int s=0; s<31; ++s)
        m.insert(compress(1 << s));

      auto p = compress(N);

      auto [st, ed] = m.equal_range(p.first);
      for (;st != ed; ++st) 
        if (compare(st->second, p.second))
          return true;

      return false;
    }

    bool reorderedPowerOf2New(int n) {
      return pow2.find(Digits(n)) != pow2.end();
    }
};


unordered_set<Digits, Digits::Hash> Solution::pow2 = Solution::init();


int main() {
  EXECS(Solution::reorderedPowerOf2);
  EXECS(Solution::reorderedPowerOf2New);
  return 0;
}