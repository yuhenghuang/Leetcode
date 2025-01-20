#include "utils3.hpp"

class UnionFind {
  private:
    vector<int> parent;
    vector<int> rank;

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

      if (p != q)
        parent[q] = p;
    }

    void reset() {
      parent.assign(parent.size(), -1);
    }
};

class Solution {
  public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
      // TLE, need further improvement
      bool known[n];
      memset(known, 0, sizeof(known));

      known[0] = true;
      known[firstPerson] = true;

      sort(
        meetings.begin(), 
        meetings.end(),
        [](auto& i, auto& j) -> bool {
          return i[2] < j[2];
        }
      );

      UnionFind uf(n);

      int i = 0;
      int j = i;
      while (i < meetings.size()) {
        while (j < meetings.size() && meetings[j][2] == meetings[i][2])
          ++j;

        uf.reset();
        for (int k = i;k < j; ++k)
          uf.unite(meetings[k][0], meetings[k][1]);


        for (int k = i;k < j; ++k) {
          int p = meetings[k][0];
          int q = meetings[k][1];

          if (known[p] || known[q])
            known[uf.find(p)] = true;
        }

        for (; i < j; ++i) {
          int p = meetings[i][0];
          int q = meetings[i][1];
          if (known[uf.find(p)])
            known[p] = known[q] = true;
        }
      }

      vector<int> res;
      for (int i = 0; i < n; ++i)
        if (known[i])
          res.push_back(i);

      return res;
    }

    vector<int> findAllPeopleWrong(int n, vector<vector<int>>& meetings, int firstPerson) {
      // wrong answer
      typedef vector<vector<int>>::iterator iter_t;

      bool known[n];
      memset(known, 0, sizeof(known));

      known[0] = true;
      known[firstPerson] = true;

      sort(
        meetings.begin(), 
        meetings.end(),
        [](auto& i, auto& j) -> bool {
          return i[2] < j[2];
        }
      );

      iter_t i = meetings.begin();
      iter_t j = i;

      while (i != meetings.end()) {
        while (j != meetings.end() && (*j)[2] == (*i)[2])
          ++j;

        sort(
          i, j,
          [&known](auto& i, auto& j) -> bool {
            return (known[i[0]] || known[i[1]]) && (!known[j[0]] && !known[j[1]]);
          }
        );

        for(; i != j; ++i) {
          if (known[(*i)[0]])
            known[(*i)[1]] = true;
          else if (known[(*i)[1]])
            known[(*i)[0]] = true;
        }
      }

      vector<int> res;
      for (int i = 0; i < n; ++i)
        if (known[i])
          res.push_back(i);

      return res;
    }
};


int main() {
  UFUNCS(Solution::findAllPeople);
  UFUNCS(Solution::findAllPeopleWrong);
  return 0;
}