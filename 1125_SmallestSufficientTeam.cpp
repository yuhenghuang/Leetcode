#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
      const int n = req_skills.size(); // 1 ~ 16
      const int m = people.size(); // 1 ~ 60

      unordered_map<string, uint16_t> skill_ids;
      for (int i = 0; i < n; ++i)
        skill_ids[req_skills[i]] = 1U << i;

      vector<uint16_t> ppl(m);
      for (int i = 0; i < m; ++i)
        for (const string& s : people[i])
          ppl[i] |= skill_ids[s];

      uint64_t dp[1 << 16]; // bits of skills, bits of people
      memset(dp, 0, sizeof(uint64_t) * (1 << n));

      queue<uint16_t> q;
      q.push(0);

      while (!q.empty()) {
        uint16_t u = q.front();
        q.pop();

        for (int i = 0; i < m; ++i) {
          uint16_t v = u | ppl[i];

          // target found
          if (v == static_cast<uint16_t>((1 << n) - 1)) {
            vector<int> res;

            uint64_t temp = dp[u];
            for (int j = 0; j < m; ++j)
              if ((temp >> j) & 1)
                res.push_back(j);

            res.push_back(i);
            
            return res;
          }

          // new skills found and the new combination
          if (v > u && dp[v] == 0) {
            dp[v] = dp[u] | (1ULL << i);
            q.push(v);
          }
        }
      }

      return {};
    }
};


int main() {
  EXECS(Solution::smallestSufficientTeam);
  return 0;
}