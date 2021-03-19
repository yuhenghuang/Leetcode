#include <unordered_set>
#include "utils2.hpp"

class Solution {
  private:
    enum COLOR {WHITE, BLACK, GREY};

    bool possible;
    int idx;

    void topologicalSort(int v, const vector<unordered_set<int>>& graph, vector<COLOR>& clr, vector<int>& order) {
      if (!possible) return;

      clr[v] = GREY;
      for (int w : graph[v]) {
        if (clr[w] == WHITE)
          topologicalSort(w, graph, clr, order);
        else if (clr[w] == GREY) {
          possible = false;
          return;
        }
      }

      clr[v] = BLACK;
      order[v] = --idx;
    }

  public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
      int groupId = n;
      for (int i=0; i<n; ++i)
        if (group[i] < 0)
          group[i] = --groupId;

      vector<unordered_set<int>> groupGraph(n), itemGraph(n);

      for (int i=0; i<n; ++i) {
        for (int before : beforeItems[i]) {
          itemGraph[before].insert(i);

          if (group[before] != group[i])
            groupGraph[group[before]].insert(group[i]);
        }
      }

      vector<COLOR> groupColor(n, WHITE), itemColor(n, WHITE);
      vector<int> groupOrder(n), itemOrder(n);

      possible = true;
      idx = n;
      for (int i=0; i<n; ++i)
        if (groupColor[i] == WHITE)
          topologicalSort(i, groupGraph, groupColor, groupOrder);

      if (!possible) 
        return {};

      idx = n;
      for (int i=0; i<n; ++i)
        if (itemColor[i] == WHITE)
          topologicalSort(i, itemGraph, itemColor, itemOrder);

      if (!possible) 
        return {};

      vector<int> res(n);
      for (int i=0; i<n; ++i)
        res[i] = i;

      sort(res.begin(), res.end(),
        [&groupOrder, &itemOrder, &group](const int& i, const int& j) -> bool {
          if (groupOrder[group[i]] == groupOrder[group[j]])
            return itemOrder[i] < itemOrder[j];
          else
            return groupOrder[group[i]] < groupOrder[group[j]];
        }
      );

      return res;
    }
};


int main() {
  UFUNC(Solution::sortItems);
  return 0;
}