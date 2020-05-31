#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
  public:
    int minJumps(vector<int>& arr) {
      if (arr.size()==1) return 0;
      unordered_map<int, vector<int>> graph;
      for (int i=0; i<arr.size(); ++i)
        graph[arr[i]].push_back(i);
    
      vector<bool> seen(arr.size(), false);
      seen[0] = true;
      queue<int> q;
      q.push(0);
      int res=1;
      while (!q.empty()) {
        int N = q.size();
        while (N--) {
          int v = q.front(); q.pop();
          if (v>0 && !seen[v-1]) {
            seen[v-1];
            q.push(v-1);
          }
          if (v==arr.size()-2)
            return res;
          else if (!seen[v+1]) {
            seen[v+1];
            q.push(v+1);
          }

          for (int& w : graph[arr[v]]) {
            if (seen[w]) continue;
            if(w==arr.size()-1) return res;
            seen[w] = true;
            q.push(w);
          }
          graph[arr[v]] = vector<int>(0);
        }
        ++res;
      }
      return res;
    }
};

int main() {
  Solution sol;
  vector<int> args = {7,6,9,6,9,6,9,7};
  cout << sol.minJumps(args) << endl;
  return 0;
}