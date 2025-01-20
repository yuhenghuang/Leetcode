#include "utils.hpp"

class Solution {
  private:
    void get_next(int i, int k, int v, vector<int>& next, const vector<int>& courses) {
      if (k==0) {
        next.push_back(v);
        return;
      }

      for (int j=i; j<courses.size(); ++j)
        get_next(j+1, k-1, v | (1<<courses[j]), next, courses);
    }

  public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
      const int target = (1<<n) - 1;

      bool seen[1<<n];
      memset(seen, 0, (1<<n));

      int prerequisite[n];
      memset(prerequisite, 0, n*sizeof(int));

      for (const auto& e : dependencies) 
        prerequisite[e[1]-1] |= 1 << (e[0]-1);

      queue<int> q;
      q.push(0);
      seen[0] = true;

      int res=1;
      vector<int> courses;
      courses.reserve(n);
      while (!q.empty()) {
        int s = q.size();
        while (s--) {
          int v = q.front(); q.pop();
          for (int i=0; i<n; ++i)
            if (((v>>i) & 1) == 0 && (prerequisite[i] & v) == prerequisite[i])
              courses.push_back(i);

          vector<int> next;

          // find all combinations of size k if there're more than k courses
          if (courses.size()>k) 
            get_next(0, k, v, next, courses);
          else {
            for (int w : courses)
              v |= 1 << w;
            next.push_back(v);
          }

          for (int w : next) {
            if (w==target) return res;
            if (seen[w]) continue;
            seen[w] = true;
            q.push(w);
          }

          courses.clear();
        }
        ++res;
      }

      return 0;
    }
    int minNumberOfSemestersWrong(int n, vector<vector<int>>& dependencies, int k) {

      // wrong answer...

      int indegree[n+1], outdegree[n+1];
      // bool seen[n+1];
      memset(indegree, 0, (n+1)*sizeof(int));
      memset(outdegree, 0, (n+1)*sizeof(int));
      // memset(seen, 0, n+1);

      vector<vector<int>> graph(n+1);
      for (const auto& edge : dependencies) {
        graph[edge[0]].push_back(edge[1]);
        ++indegree[edge[1]];
        ++outdegree[edge[0]];
      }


      priority_queue<pair<int, int>> heap;
      for (int i=1; i<=n; ++i)
        if (indegree[i]==0) {
          heap.push({outdegree[i], i});
          // seen[i] = true;
        }

      int res=0;
      queue<pair<int, int>> q;
      while (!heap.empty()) {
        int s = min(k, static_cast<int>(heap.size()));
        while (s--) {
          int v = heap.top().second; heap.pop();
          for (int w : graph[v]) 
            if (--indegree[w]==0) {
              q.push({outdegree[w], w});
            }
        }

        while (!q.empty()) {
          heap.push(q.front());
          q.pop();
        }
        ++res;
      }

      return res;
    }
};


int main() {
  UFUNC(Solution::minNumberOfSemesters);
  return 0;
}