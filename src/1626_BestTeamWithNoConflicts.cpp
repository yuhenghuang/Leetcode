#include <local_leetcode.hpp>

class Solution {
  public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
      // O(n^2)
      typedef pair<int, int> ii_t;

      int n = scores.size();

      vector<ii_t> players(n);
      for (int i = 0; i < n; ++i) {
        players[i].first = -ages[i];
        players[i].second = scores[i];
      }

      // sort by age DESC, score ASC
      sort(players.begin(), players.end());

      // score inf, total scores
      map<int, int> dp;
      dp[1e7] = 0;

      for (int start = 0; start < n;) { // start index of current age
        int end = start + 1; // end index of current age
        for (; end < n && players[end-1].first == players[end].first; ++end);

        int sum = 0;
        auto iter = dp.begin();

        for (int i = start; i < end; ++i) {
          if (i + 1 == end || players[i].second != players[i+1].second) {
            for (; iter->first < players[i].second; ++iter);

            int res = iter->second;
            
            auto k = iter;
            for (int j = i; j < end; ++j) {
              sum += players[j].second;

              // find the max sum of scores between players[j]'s score and players[j+1]'s
              int max_scores = 0;
              for (int score = (j+1 == end) ? 1e7 : players[j+1].second; k->first < score; ++k)
                if (k->second > max_scores)
                  max_scores = k->second;
 
              if (sum + max_scores > res)
                res = sum + max_scores;
            }

            dp[players[i].second] = res;

            sum = 0;
          }
          else
            sum += players[i].second;
        }

        start = end;
      }

      return accumulate(dp.begin(), dp.end(), 0, [](int i, const ii_t& j) { return max(i, j.second); }) ;
    }
};


int main() {
  EXECS(Solution::bestTeamScore);
  return 0;
}