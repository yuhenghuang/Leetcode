#include "utils.hpp"


class Solution {
  private:
    bool isPalindrome(const string& s) {
      int i=0, j=s.size()-1;
      while (j>i) {
        if (s[i++]!=s[j--])
          return false;
      }
      return true;
    }

    void dfs(int idx, int n, const string& s, vector<vector<bool>>& memo, vector<string>& temp, vector<vector<string>>& res) {
      if (idx==n) 
        res.push_back(temp);

      for (int i=idx; i<n; ++i) 
        if (s[i]==s[idx] && (i-idx<3 || memo[idx+1][i-1])) {
          memo[idx][i] = true;
          temp.push_back(s.substr(idx, i-idx+1));
          dfs(i+1, n, s, memo, temp, res);
          temp.pop_back();
        }
    }
  public:
    vector<vector<string>> partition(string s) {
      int n = s.size();
      vector<vector<vector<string>>> memo(n+1);

      memo[0] = {{}};

      for (int i=0; i<n; ++i) 
        for (int j=0; j<=i; ++j)
          if (s[j]==s[i] && (i-j<3 || isPalindrome(s.substr(j+1, i-j-1)))) {
            string temp = s.substr(j, i-j+1);
            for (auto vec : memo[j]) {
              vec.push_back(temp);
              memo[i+1].push_back(std::move(vec));
            }
          }

      return memo[n];
    }

    vector<vector<string>> partitionDFS(string s) {
      int n = s.size();

      vector<vector<bool>> memo(n, vector<bool>(n));

      vector<vector<string>> res;
      vector<string> temp;

      dfs(0, n, s, memo, temp, res);

      return res;
    }
};


int main() {
  {
    UFUNC(Solution::partition);
  }
  {
    UFUNC(Solution::partitionDFS);
  }
  return 0;
}