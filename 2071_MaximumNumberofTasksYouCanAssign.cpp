#include "utils3.hpp"

class Solution {
  public:
    int maxTaskAssignWrong(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
      sort(tasks.begin(), tasks.end());
      sort(workers.begin(), workers.end());

      int m = tasks.size();
      int n = workers.size();

      int res = 0;

      int i = 0, j = 0;
      while (i < m && j < n) {
        if (tasks[i] <= workers[j]) {
          ++i;
          ++j;
          ++res;
        }
        else {
          // if there is more workers left than tasks
          // and remaining pills and the task becomes assignable after taking the pill
          if (m - i < n - j && pills > 0 && tasks[i] <= workers[j] + strength) {
            ++i;
            ++res;
            --pills;
          }

          ++j;
        }
      }

      return res;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
      sort(tasks.begin(), tasks.end());
      sort(workers.begin(), workers.end());

      int n = workers.size();

      int l = 0, r = min((int)tasks.size(), n);
      while (l < r) {
        int m = l + (r - l) / 2 + (r - l) % 2;

        int p = pills;
        queue<int> q;

        int i = 0, j = n - m;

        while (j < n || !q.empty()) {
          // weight
          int w;
          // worker without a pill or not
          bool flag;

          if (q.empty() || (j < n && workers[j] < q.front())) {
            w = workers[j++];
            flag = true;
          }
          else {
            w = q.front();
            q.pop();
            flag = false;
          }

          if (tasks[i] <= w) 
            ++i;
          else if (p > 0 && flag) {
            --p;
            q.push(w + strength);
          }
          else
            break;
        }

        if (i < m)
          r = m - 1;
        else
          l = m;
      }

      return l;
    }
};


int main() {
  UFUNCS(Solution::maxTaskAssignWrong);
  UFUNCS(Solution::maxTaskAssign);
  return 0;
}