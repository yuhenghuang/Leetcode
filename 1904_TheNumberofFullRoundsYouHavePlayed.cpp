#include <local_leetcode.hpp>

class Solution {
  private:
    typedef pair<int, int> pii_t;

    pii_t parse(const string& t) {
      pii_t out;
      sscanf(t.c_str(), "%d:%d", &out.first, &out.second);

      return out;
    }

    int rounds(pii_t start, pii_t end) {
      if (start.first < end.first)
        return (end.first - start.first - 1) * 4 + 4 - start.second / 15 - (start.second % 15 ? 1 : 0) + end.second / 15;
      else
        return max(end.second / 15 - start.second / 15 - (start.second % 15 ? 1 : 0), 0);
    }

  public:
    int numberOfRounds(string loginTime, string logoutTime) {
      pii_t start = parse(loginTime);
      pii_t end = parse(logoutTime);

      if (start < end) 
        return rounds(start,  end);
      else 
        return rounds(start, {24, 0}) + rounds({0, 0}, end);
    }
};


int main() {
  EXECS(Solution::numberOfRounds);
  return 0;
}