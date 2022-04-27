#include <local_leetcode.hpp>

class Solution {
  private:
    vector<int> parent;

    int find(int p) {
      if (parent[p] == p)
        return p;
      return parent[p] = find(parent[p]);
    }

    void join(int p, int q) {
      p = find(p);
      q = find(q);

      if (p != q) {
        // choose smaller one as parent
        if (p < q)
          parent[q] = p;
        else
          parent[p] = q;
      }
    }

  public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
      int n = s.size();

      parent.resize(n);
      iota(parent.begin(), parent.end(), 0);

      for (auto& p : pairs)
        join(p[0], p[1]);

      // sub strings
      vector<string> sss(n);
      for (int i = 0; i < n; ++i) 
        sss[find(i)].push_back(s[i]);

      for (auto& ss : sss)
        sort(ss.begin(), ss.end());

      vector<const char*> ptrs(n);
      transform(sss.begin(), sss.end(), ptrs.begin(), mem_fn(&string::c_str));

      string res;
      res.reserve(n);

      for (int i = 0; i < n; ++i)
        res.push_back(*ptrs[parent[i]]++);

      return res;
    }
};


int main() {
  EXECS(Solution::smallestStringWithSwaps);
  return 0;
}