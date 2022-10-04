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

      if (p != q)
        parent[q] = p;
    }

  public:
    bool equationsPossible(vector<string>& equations) {
      memset(parent, -1, sizeof(parent));

      for (auto& eq : equations)
        if (eq[1] == '=') 
          join(eq[0] - 'a', eq[3] - 'a');

      for (auto& eq : equations)
        if (eq[1] == '!' && find(eq[0] - 'a') == find(eq[3] - 'a'))
          return false;

      return true;
    }
};


int main() {
  EXECS(Solution::equationsPossible);
  return 0;
}
