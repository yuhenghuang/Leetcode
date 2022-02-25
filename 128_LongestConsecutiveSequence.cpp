#include <local_leetcode.hpp>

class UnionFind {
  private:
    unordered_map<int, int> parent;

  public:
    UnionFind(const unordered_set<int>& s) {
      for (const int& num : s)
        parent[num] = num;
    }

    int find(int p) {
      int tmp = parent[p];
      if (tmp == p)
        return p;

      return parent[p] = find(tmp);
    }

    void join(int p) {
      auto iter = parent.find(p + 1);

      if (iter == parent.end())
        return;

      p = find(p);
      int q = find(iter->second);

      if (p != q) {
        if (p < q)
          parent[q] = p;
        else
          parent[p] = q;
      }
    }
};

class Solution {
  private:
    unordered_map<int, int> parent;

    int _find(int p) {
      auto iter = parent.find(p);
      if (iter->second != p) {
        iter->second = _find(p + 1);
      }

      return iter->second;
    }

    void _union(int p) {
      auto iter = parent.find(p + 1);
      if (iter != parent.end()) 
        parent[p] = _find(p + 1);
    }
 

  public:
    int longestConsecutiveUF(vector<int>& nums) {
      unordered_set<int> s(nums.begin(), nums.end());

      UnionFind uf(s);

      for (const int& num : s)
        uf.join(num);

      // parent, count
      unordered_map<int, int> m;
      for (const int& num : s)
        ++m[uf.find(num)];

      int res = 0;
      for (auto& p : m)
        if (p.second > res)
          res = p.second;

      return res;
    }

    int longestConsecutiveTLE(vector<int>& nums) {
      // failed because of unbalanced UF

      for (int num : nums) 
        parent[num] = num;

      for (int num : nums)
        _union(num);

      int res = 0;

      for (int num : nums)
        res = max(res, _find(num) - num + 1);

      return res;
    }

    int longestConsecutive(vector<int>& nums) {
      unordered_set<int> s(nums.begin(), nums.end());

      int res = 0;

      for (int num : s) {
        if (s.count(num - 1) == 0) {
          int temp = 1;
          while (s.count(++num) > 0)
            ++temp;

          res = max(res, temp);
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::longestConsecutive);
  EXECS(Solution::longestConsecutiveUF);
  EXECS(Solution::longestConsecutiveTLE);
  return 0;
}
