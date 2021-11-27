#include "utils3.hpp"

class Solution {
  public:
    bool sumGame(string num) {
      int n = num.size() / 2;

      int sum_l = 0;
      int quest_l = 0;
      int i = 0;
      for (; i < n; ++i)
        if (num[i] == '?')
          ++quest_l;
        else
          sum_l += num[i] - '0';

      int sum_r = 0;
      int quest_r = 0;
      for (; i < n * 2; ++i)
        if (num[i] == '?')
          ++quest_r;
        else
          sum_r += num[i] - '0';

      if (sum_l == sum_r && quest_l == quest_r)
        return false;
      else if ((sum_l - sum_r) * (quest_l - quest_r) >= 0)
        return true;

      int quest = abs(quest_l - quest_r);

      if (quest % 2 == 1)
        return true;

      int sum = abs(sum_l - sum_r);
      return quest / 2 *  9 != sum;
    }
};


int main() {
  UFUNCS(Solution::sumGame);
  return 0;
}