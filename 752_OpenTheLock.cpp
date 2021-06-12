#include "utils2.hpp"

class Solution {
  private:
    enum LOCKS {TOTRY, DEADENDS, TRIED};

  public:
    int openLockBidirectional(vector<string>& deadends, string target) {
      if (target == "0000")
        return 0;

      constexpr size_t maxN = 10000;

      vector<LOCKS> s1(maxN), s2(maxN);

      for (const string& s : deadends) {
        int code = stoi(s);
        s1[code] = DEADENDS;
        s2[code] = DEADENDS;
      }

      queue<int> q1, q2;

      int t = stoi(target);

      if (s1[0] == TOTRY) {
        q1.push(0);
        s1[0] = TRIED;
      }

      if (s2[t] == TOTRY) {
        q2.push(t);
        s2[t] = TRIED;
      }

      int res = 1;
      while (!q1.empty() && !q2.empty()) {
        int n = q1.size();
        while (n--) {
          int v = q1.front();
          q1.pop();

          // adjust 4 digits in 2 directions
          int temp = v;
          for (int mod : {1000, 100, 10, 1}) {
            int d = temp / mod;
            temp %= mod;

            v -= d * mod;
            for (int sign : {1, -1}) {
              int w = v + ((d + sign + 10) % 10) * mod;
              if (s1[w] != TOTRY)
                continue;
              else if (s2[w] == TRIED)
                return res;
              else {
                s1[w] = TRIED;
                q1.push(w);
              }
            }

            v += d * mod;
          }

        }

        ++res;

        // always search from the smaller queue
        if (q1.size() < q2.size()) {
          swap(q1, q2);
          swap(s1, s2);
        }
      }

      return -1;
    }

    int openLock(vector<string>& deadends, string target) {
      // record seen codes and deadends by a boolean array
      bool seen[10000] = {0};
      for (const string& s : deadends)
        seen[stoi(s)] = true;

      // queue for BFS
      queue<int> q;

      // handle corner cases
      // "0000" in deadends
      if (!seen[0]) {
        seen[0] = true;
        q.push(0);
      }

      // "0000" is target
      int t = stoi(target);
      if (t == 0)
        return 0;

      int res = 1;
      while (!q.empty()) {
        int n = q.size();
        while (n--) {
          int v = q.front();
          q.pop();

          // adjust 4 digits in 2 directions
          int temp = v;
          for (int mod : {1000, 100, 10, 1}) {
            int d = temp / mod;
            temp %= mod;

            v -= d * mod;
            for (int sign : {1, -1}) {
              int w = v + ((d + sign + 10) % 10) * mod;
              if (!seen[w]) {
                if (w == t)
                  return res;

                seen[w] = true;
                q.push(w);
              }
            }

            v += d * mod;
          }

        }

        ++res;
      }

      return -1;
    }
};


int main() {
  {
    UFUNC(Solution::openLock);
  }
  {
    UFUNC(Solution::openLockBidirectional);
  }
  return 0;
}