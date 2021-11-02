#include <map>
#include "utils3.hpp"

class Solution {
  private:
    typedef pair<
      vector<pair<int, int>>::iterator, 
      vector<pair<int, int>>::iterator
    > iter_type;

    struct Comp {
      bool operator()(const iter_type& x, const iter_type& y) const {
        return x.first->first > y.first->first;
      }
    };

    vector<pair<int, int>> merge(vector<vector<pair<int, int>>>& visited) {
      // merge k sorted arrays in nlog(k) complexity

      priority_queue<iter_type, vector<iter_type>, Comp> heap;

      for (auto& v : visited)
        if (!v.empty())
          heap.emplace(v.begin(), v.end());

      vector<pair<int, int>> res;
      while (!heap.empty()) {
        auto p = heap.top();
        heap.pop();

        if (res.empty() || res.back().second + 1 < p.first->first)
          res.emplace_back(p.first->first, p.first->second);
        else
          // merge intervals if possible
          res.back().second = p.first->second;

        if (++p.first != p.second)
          heap.push(std::move(p));
      }

      return res;
    }

    vector<pair<int, int>> dfs(int v, vector<vector<int>>& tree, vector<int>& nums, vector<int>& res) {
      vector<vector<pair<int, int>>> visited;
      visited.push_back(vector<pair<int, int>> {{nums[v], nums[v]}});

      for (int w : tree[v])
        visited.push_back(dfs(w, tree, nums, res));

      // visited values are saved as sorted intervals
      // start and end are both inclusive
      vector<pair<int, int>> values = merge(visited);

      auto p = values.front();
      res[v] = p.first == 1 ? p.second + 1 : 1;

      return values;
    }

    void dfs(int v, vector<vector<int>>& tree, map<int, int>& m, vector<int>& nums, vector<int>& res) {
      for (int w : tree[v])
        dfs(w, tree, m, nums, res);

      int val = nums[v];

      // lower_bound will also do
      auto r = m.upper_bound(nums[v]);
      auto l = prev(r);

      if (l->second + 1 == val && val + 1 == r->first) {
        l->second = r->second;
        m.erase(r);
      }
      else if (l->second + 1 == val)
        l->second = val;
      else if (val + 1 == r->first) {
        m.emplace(val, r->second);
        m.erase(r);
      }
      else
        m[val] = val;


      res[v] = m.begin()->second + 1;
    }

  public:
    vector<int> smallestMissingValueSubtreeWrong(vector<int>& parents, vector<int>& nums) {
      // wrong answer, cannot use one single map to store all visited intervals...

      int n = parents.size();

      vector<vector<int>> tree(n);
      for (int i = 1; i < n; ++i) 
        tree[parents[i]].push_back(i);

      // save searched intervals
      map<int, int> m;
      m.emplace(0, 0);

      // right most
      m.emplace(INT_MAX, INT_MAX);

      vector<int> res(n);
      dfs(0, tree, m, nums, res);

      return res;
    }

    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
      // slow but works...
      // O(n2) generally, and even slower because of copy (in construct new intervals from results from children)
      // but fast for particular cases (when lots of visited intervals merging)

      int n = parents.size();

      vector<vector<int>> tree(n);
      for (int i = 1; i < n; ++i) 
        tree[parents[i]].push_back(i);

      vector<int> res(n);
      dfs(0, tree, nums, res);

      return res;
    }
};


int main() {
  UFUNCS(Solution::smallestMissingValueSubtree);
  return 0;
}