#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

struct UnionFind {
  vector<int> prev;
  UnionFind(int n) {
    prev.resize(n);
    for (int i=0; i<n; ++i)
      prev[i] = i;
  }

  void find(int &num) {
    int temp = num;
    while (prev[num]!=num)
      num = prev[num];
    prev[temp] = num;
  }

  void unite(int a, int b) {
    find(a);
    find(b);
    prev[a] = b;
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
    int largestComponentSize(vector<int>& A) {
      int n = A.size();
      UnionFind uf(n);
      vector<bool> seen(n, false);
      for (int i=1; i<n; ++i)
        for (int j=0; j<i; ++j)
          if (connected(A[i], A[j]))
            uf.unite(i, j);

      int temp;
      for (int i=0; i<n; ++i) {
        temp = i;
        uf.find(temp);
      }

      unordered_map<int, int> m;
      for (int &num : uf.prev)
        ++m[num];

      int res=0;
      for (auto iter=m.begin(); iter!=m.end(); ++iter)
        res = max(res, iter->second);
      return res;
    }
};

int main() {
  Solution sol;
  vector<int> A = {2,3,6,7,4,12,21,39};
  cout << sol.largestComponentSize(A) << endl;
  return 0;
}