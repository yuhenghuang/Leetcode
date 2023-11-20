#include <local_leetcode.hpp>

class Solution {
  public:
    int bestClosingTime(string customers) {
      int total_customers = 0;
      for (char c : customers)
        if (c == 'Y')
          ++total_customers;

      int res = 0;
      int min_penalty = total_customers;

      int curr_customers = 0;
      for (int i = 0; i < customers.size(); ++i) {
        if (customers[i] == 'Y')
          ++curr_customers;

        int curr_penalty = i + 1 - curr_customers + total_customers - curr_customers;

        if (curr_penalty < min_penalty) {
          min_penalty = curr_penalty;
          res = i + 1;
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::bestClosingTime);
  return 0;
}