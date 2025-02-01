#include <local_leetcode.hpp>

/*
class UnionFind {
  private:
    vector<int> parent;
    vector<int> rank;

  public:
    UnionFind(int n): parent(n, -1), rank(n) { }

    int find(int p) {
      if (parent[p] == -1)
        return p;

      return parent[p] = find(parent[p]);
    }

    void join(int p, int q) {
      p = find(p);
      q = find(q);
      
      if (p != q) {
        if (rank[p] < rank[q])
          parent[p] = q;
        else {
          parent[q] = p;

          if (parent[p] == parent[q])
            ++rank[p];
        }
      }
    }
};
*/

class Solution {
  public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
      const int n = nums.size();

      vector<int> indices(n);

      iota(indices.begin(), indices.end(), 0);
      sort(
        indices.begin(), indices.end(),
        [&nums] (int i, int j) { return nums[i] < nums[j]; }
      );

      vector<vector<int>> groups(1);
      groups.back().push_back(indices[0]);

      for (int k = 1; k < n; ++k) {
        int i = indices[k-1];
        int j = indices[k];

        // add j to current group
        if (nums[j] - nums[i] <= limit)
          groups.back().push_back(j);
        // create a new group
        else 
          groups.emplace_back().push_back(j);
      }

      for (auto& g : groups)
        sort(g.begin(), g.end());

      vector<int> res(n);

      auto iter = indices.begin();
      for (const auto& g : groups)
        for (int i : g)
          res[i] = nums[*iter++];

      return res;
    }
};


int main() {
  EXECS(Solution::lexicographicallySmallestArray);
  return 0;
}