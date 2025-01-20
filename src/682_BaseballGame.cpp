#include <local_leetcode.hpp>

class Solution {
  public:
    int calPoints(vector<string>& ops) {
      int i = -1;
      vector<int> scores;
      for (auto& e : ops) {
        char op = e[0];

        switch (op) {
          case '+':
            scores.push_back(scores[i] + scores[i-1]);
            ++i;
            break;
          case 'D':
            scores.push_back(scores[i++] * 2);
            break;
          case 'C':
            scores.pop_back();
            --i;
            break;
          default:
            scores.push_back(stoi(e));
            ++i;
        }
      }

      return reduce(scores.begin(), scores.end());
    }
};


int main() {
  EXECS(Solution::calPoints);
  return 0;
}