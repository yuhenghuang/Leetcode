#include "utils3.hpp"
#include <unordered_set>

class Solution {
  public:
    // topological sort
    vector<int> findMinHeightTreesTS(int n, vector<vector<int>>& edges) {
      vector<int> indepth(n);
      vector<vector<int>> graph(n);
      for (const vector<int>& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
        ++indepth[edge[0]];
        ++indepth[edge[1]];
      }

      queue<int> q;
      for (int i=0; i<n; ++i)
        if (indepth[i]<2)
          q.push(i);

      int remaining = n;
      while (remaining>2) {
        int N = q.size();
        remaining -= N;
        while (N--) {
          const int& v = q.front();

          for (const int& w : graph[v]) 
            // avoid going back
            if (indepth[w]>1 && --indepth[w]==1) 
              q.push(w);
              
          q.pop();
        }
      }

      vector<int> res;
      while (!q.empty()) {
        res.push_back(q.front());
        q.pop();
      }

      return res;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
      vector<unordered_set<int>> graph(n);
      for (const vector<int>& edge : edges) {
        graph[edge[0]].insert(edge[1]);
        graph[edge[1]].insert(edge[0]);
      }

      vector<int> leaves;
      for (int i=0; i<n; ++i)
        if (graph[i].size()<2)
          leaves.push_back(i);

      int remaining = n;
      while (remaining>2) {
        remaining -= leaves.size();
        vector<int> temp;

        for (const int& leaf : leaves) {
          for (const int& neighbor : graph[leaf]) {
            graph[neighbor].erase(leaf);
            if (graph[neighbor].size()==1)
              temp.push_back(neighbor);
          }
        }

        leaves = std::move(temp);
      }

      return leaves;
    }


    vector<int> findMinHeightTreesTLE(int n, vector<vector<int>>& edges) {
      vector<vector<int>> graph(n);
      for (const vector<int>& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
      }

      queue<pair<int, int>> q;
      vector<int> depth(n, 0);
      int leaves = 0;
      for (int i=0; i<n; ++i)
        if (graph[i].size()<2) {
          ++leaves;
          ++depth[i];
          q.push({-1, i});
        }

      bool flag = false;
      while (!q.empty()) {
        int N = q.size();
        while (N--) {
          auto& p = q.front();
          int v = p.first, w = p.second;
          q.pop();
          for (const int& e : graph[w]) {
            if (e==v) continue;

            q.push({w, e});
            if (++depth[e]==leaves)
              flag = true;
          }
        }
        if (flag) break;
      }

      vector<int> res;
      for (int i=0; i<n; ++i)
        if (depth[i]==leaves)
          res.push_back(i);

      return res;
    }
};


int main() {
  UFUNCS(Solution::findMinHeightTrees);
  UFUNCS(Solution::findMinHeightTreesTS);
  UFUNCS(Solution::findMinHeightTreesTLE);
  return 0;
}