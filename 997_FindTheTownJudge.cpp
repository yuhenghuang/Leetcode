#include <vector>
using namespace std;

// wrong answer...

class UnionFind {
  private:
    int N;
  public:
    vector<int> vec;
    UnionFind(int N) {
      this->N = N;
      vec = vector<int>(N+1);
      for (int i=1; i<=N; ++i)
        vec[i] = i;
    }
    int Find(int p) {
      int i = p;
      while (vec[p]!=p) {
        p = vec[p];
      }
      vec[i] = p;
      return p;
    }
    void Add(vector<int>& pq) {
      int p = pq[0], q = pq[1];
      q = Find(q);
      vec[p] = q;
    }
    void Final() {
      for (int i=1; i<=N; ++i) 
        Find(i);
    }
    int findJudge() {
      int res = vec[1];
      for (int i=2; i<=N; ++i)
        if (vec[i]!=res)
          return -1;
      return res;
    }
};

class Solution {
  public:
    int findJudge(int N, vector<vector<int>>& trust) {
      UnionFind uf(N);
      for (vector<int>& pq : trust)
        uf.Add(pq);
      uf.Final();
      return uf.findJudge();
    }
};