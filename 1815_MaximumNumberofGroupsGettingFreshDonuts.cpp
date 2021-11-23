#include "utils3.hpp"

static constexpr long mask = (1 << 6) - 1;

class Solution {
  private:
    int freqcount(long hash, int freq) {
      return (hash >> (freq * 6)) & mask;
    }

  public:
    int maxHappyGroupsWrong(int batchSize, vector<int>& groups) {
      int n = groups.size();

      vector<stack<int>> dp(batchSize);
      vector<stack<int>> dp_next(batchSize);

      for (int i = 0; i < n; ++i) 
        groups[i] %= batchSize;

      int res = 0;
      int used = 0;
      dp[0].push(0);

      // in each loop, the num. of groups in combination increments by 1
      while (used + 1 < (1 << n)) {
        // new combinations found
        bool flag = false;

        for (int i = 0 ; i < batchSize; ++i) {
          stack<int>& s = dp[i];
          while (!s.empty()) {
            int bits = s.top();
            s.pop();

            // if ((used & bits) > 0)
            //   break;

            for (int j = 0; j < n; ++j)
              if ((used & bits) == 0 && (bits & (1 << j)) == 0 && (used & (1 << j)) == 0) {
                int k = (i + groups[j]) % batchSize;
                if (k == 0) {
                  ++res;
                  used |= (1 << j) | bits;
                  // break;
                }
                else {
                  flag = true;
                  dp_next[k].push((1 << j) | bits);
                }
              }
          }
        }

        if (!flag)
          break;

        swap(dp, dp_next);
      }

      if (used + 1 < (1 << n))
        ++res;

      return res;
    }

    int maxHappyGroups(int batchSize, vector<int>& groups) {
      int n = groups.size();

      vector<int> count(batchSize);
      for (int i = 0; i < n; ++i) 
        ++count[groups[i] %= batchSize];

      map<long, vector<int>> dp;
      dp.emplace(0, vector<int> (batchSize, -1));

      // 0 groups and 0 remainders
      dp[0][0] = 0;

      for (auto iter = dp.begin(); iter != dp.end(); ++iter) {
        for (int i = 0; i < batchSize; ++i)
          if (iter->second[i] >= 0) {
            for (int j = 0; j < batchSize; ++j)
              if (freqcount(iter->first, j) < count[j]) {
                long next = iter->first + (1L << (j * 6));
                vector<int>& remainders = dp[next];

                if (remainders.empty())
                  remainders.resize(batchSize, -1);

                int k = (i + j) % batchSize;
                remainders[k] = max(remainders[k], iter->second[i] + (k == 0 ? 1 : 0));
              }
          }
      }

      vector<int>& remainders = prev(dp.end())->second;
      int res = remainders.front();
      for (int i = 1; i < batchSize; ++i)
        if (remainders[i] + 1 > res)
          res = remainders[i] + 1;

      return res;
    }
};


int main() {
  UFUNCS(Solution::maxHappyGroupsWrong);
  UFUNCS(Solution::maxHappyGroups);
  return 0;
}