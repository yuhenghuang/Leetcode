#include "utils3.hpp"

class UnionFind {
  private:
    vector<int> parent;
  
  public:
    UnionFind(int n): parent(n, -1) { }

    int find(int p) {
      if (parent[p] < 0)
        return p;

      return parent[p] = find(parent[p]);
    }

    void unite(int p, int q) {
      p = find(p);
      q = find(q);

      if (p < q)
        parent[q] = p;
      else if (p > q)
        parent[p] = q;
    }
};

class Solution {
  private:
    typedef vector<string>::iterator iter_t;
    typedef pair<iter_t, iter_t> pair_t;

    bool is_same_user(vector<string>& x, vector<string>& y) {
      if (x.front() == y.front()) {
        int i = 1, j = 1;
        while (i < x.size() && j < y.size()) {
          int comp = strcmp(x[i].c_str(), y[j].c_str());
          if (comp < 0)
            ++i;
          else if (comp > 0)
            ++j;
          else
            return true;
        }
      }
      
      return false;
    }

  public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
      int n = accounts.size();

      // sorting makes comparison easier
      // O(m * n) -> O(m + n)
      for (auto& a : accounts)
        sort(a.begin() + 1, a.end());

      UnionFind uf(n);
      for (int i = 1; i < n; ++i)
        for (int j = 0; j < i; ++j)
          if (uf.find(i) != uf.find(j) && is_same_user(accounts[i], accounts[j]))
            uf.unite(i, j);

      vector<vector<int>> indicies(n);
      for (int i = 0; i < n; ++i)
        indicies[uf.find(i)].push_back(i);

      priority_queue<pair_t, vector<pair_t>, function<bool (pair_t&, pair_t&)>> heap(
        [](pair_t& p, pair_t& q) {
          return *p.first > *q.first;
        }
      );

      vector<vector<string>> res;

      for (auto& is : indicies) {
        if (is.empty())
          continue;

        vector<string>& acc = res.emplace_back();

        // name
        acc.push_back(accounts[is.front()].front());

        for (int i : is) 
          heap.emplace(accounts[i].begin()+1, accounts[i].end());

        while (!heap.empty()) {
          pair_t p = heap.top();
          heap.pop();

          if (*p.first != acc.back())
            acc.push_back(*p.first);
            
          if (++p.first != p.second)
            heap.push(std::move(p));
        }
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::accountsMerge);
  return 0;
}