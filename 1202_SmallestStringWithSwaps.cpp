#include <local_leetcode.hpp>

class Solution {
  private:
    vector<int> parent;

    int find(int p) {
      if (parent[p] == -1)
        return p;
      return parent[p] = find(parent[p]);
    }

    void join(int p, int q) {
      p = find(p);
      q = find(q);

      if (p != q) {
        // choose smaller one as parent
        // or use rank to determine the optimal parent
        if (p < q)
          parent[q] = p;
        else
          parent[p] = q;
      }
    }

  public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
      const int n = s.size();

      parent.assign(n, -1);

      for (auto& p : pairs)
        join(p[0], p[1]);

      // sub sequences
      vector<string> sss(n);
      for (int i = 0; i < n; ++i) 
        sss[find(i)].push_back(s[i]);

      // sort sub sequences
      for (auto& ss : sss)
        sort(ss.begin(), ss.end());

      vector<const char*> ptrs(n);
      transform(sss.begin(), sss.end(), ptrs.begin(), mem_fn(&string::c_str));

      string res;
      res.reserve(n);

      for (int i = 0; i < n; ++i)
        res.push_back(*ptrs[find(i)]++);

      return res;
    }
};


int main() {
  EXECS(Solution::smallestStringWithSwaps);
  return 0;
}