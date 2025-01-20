#include "utils3.hpp"

struct UnionFind {
  vector<int> parent;
  UnionFind(int n): parent(n, -1) { }

  int find(int p) {
    if (parent[p] < 0)
      return p;
    
    return parent[p] = find(parent[p]);
  }

  void join(int p, int q) {
    p = find(p);
    q = find(q);
  
    if (p != q) {
      if (p > q)
        swap(p, q);

      parent[q] = p;
    }
  }
};

class Solution {
private:
  bool connected(int a, int b) {
    if (a==1 || b==1)
      return false;
    else if (a==b || (a%2==0 && b%2==0))
      return true;
    else {
      if (a%2==0)
        return connected(b, a/2);
      else if (b%2==0)
        return connected(a, b/2);
      else {
        if (a<b)
          swap(a, b);
        return connected((a-b)/2, b);
      }
    }
  }
public:
    int largestComponentSize(vector<int>& nums) {
      return -1;
    }

    int largestComponentSizeTLE(vector<int>& nums) {
      int n = nums.size();
      UnionFind uf(n);

      for (int i=1; i<n; ++i)
        for (int j=0; j<i; ++j)
          if (connected(nums[i], nums[j]))
            uf.join(i, j);

      unordered_map<int, int> m;
      for (int i=0; i<n; ++i)
        ++m[uf.find(i)];

      int res=0;
      for (auto iter=m.begin(); iter!=m.end(); ++iter)
        res = max(res, iter->second);
      return res;
    }
};

int main() {
  UFUNCS(Solution::largestComponentSize);
  UFUNCS(Solution::largestComponentSizeTLE);
  return 0;
}