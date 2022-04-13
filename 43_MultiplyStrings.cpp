#include <local_leetcode.hpp>


vector<int> operator+(const vector<int>& x, const vector<int>& y) {
  vector<int> z;

  int rem = 0;
  auto i = x.begin();
  auto j = y.begin();

  // possible improvement: early stop here
  while (i != x.end() || j != y.end() || rem > 0) {
    int sum = (i == x.end() ? 0 : *i++) + (j == y.end() ? 0 : *j++) + rem;

    z.push_back(sum % 10);
    rem = sum / 10;
  }

  if (z.empty())
    z.push_back(0);

  return z;
}

class Solution {
  public:
    string multiply(string _num1, string _num2) {
      if (_num1 == "0" || _num2 == "0")
        return "0";

      // reverse num and transform to digits vector
      vector<int> num1, num2;

      transform(_num1.rbegin(), _num1.rend(), back_inserter(num1), [](char c) { return c - '0'; });
      transform(_num2.rbegin(), _num2.rend(), back_inserter(num2), [](char c) { return c - '0'; });

      // precompute num1 * i (0 ~ 9)
      vector<int> num1_n[10];
      for (int i = 1; i < 10; ++i)
        num1_n[i] = num1_n[i-1] + num1;

      vector<vector<int>> proc;

      // perform multiplication by digits of num2
      for (int i = 0; i < num2.size(); ++i) {
        vector<int>& num1_i = num1_n[num2[i]];
        // add i leading zeros
        vector<int>& rhs = proc.emplace_back(i, 0);
        
        copy(num1_i.begin(), num1_i.end(), back_inserter(rhs));
      }

      // cannot use std::plus<> because of declarations' order?...
      vector<int>&& out = reduce(
        proc.begin(),
        proc.end(),
        vector<int> {},
        [](const vector<int>& x, const vector<int>& y) { return x + y; }
      );

      string res;
      transform(out.rbegin(), out.rend(), back_inserter(res), [](int d) -> char { return '0' + d; });

      return res;
    }
};


int main() {
  EXECS(Solution::multiply);
  return 0;
}