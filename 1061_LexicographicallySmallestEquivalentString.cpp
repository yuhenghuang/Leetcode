#include <local_leetcode.hpp>

class Solution {
  private:
    int parent[26];

    int find(int p) {
      if (parent[p] == -1)
        return p;

      return parent[p] = find(parent[p]);
    }

    void join(int p, int q) {
      p = find(p);
      q = find(q);

      if (p != q) {
        if (p < q)
          parent[q] = p;
        else
          parent[p] = q;
      }
    }

  public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
      memset(parent, -1, sizeof(parent));

      for (int i = 0; i < (int) s1.size(); ++i)
        join(s1[i] - 'a', s2[i] - 'a');

      string res;
      for (char c : baseStr)
        res.push_back(find(c - 'a') + 'a');

      return res;
    }
};


int main() {
  EXECS(Solution::smallestEquivalentString);
  return 0;
}