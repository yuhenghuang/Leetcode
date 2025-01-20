#include <local_leetcode.hpp>

class Solution {
  private:
    static const string phone[8];

  public:
    vector<string> letterCombinations(string digits) {
      if (digits.empty())
        return {};

      vector<string> res{""};

      for (char d : digits) {
        vector<string> res_nx;

        int i = d - '2';
        const int n = res.size();
        for (int j = 0; j < n; ++j)
          for (char c : phone[i]) 
            res_nx.push_back(res[j] + c);

        swap(res, res_nx);
      }

      return res;
    }
};

const string Solution::phone[8] {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};


int main() {
  EXECS(Solution::letterCombinations);
  return 0;
}