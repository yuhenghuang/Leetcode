/*
#include <string>
#include <iostream>
#include <vector>
using namespace std;
static vector<int> nums = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return vector<int>{};
}();
*/

#include <local_leetcode.hpp>

class Solution {
  public:
    int firstUniqChar(string s) {
      int arr[26] = {0};
      for (char c : s)
        ++arr[c-'a'];
      for (int i=0; i<s.size(); ++i)
        if (arr[s[i]-'a']==1)
          return i;
      return -1;
    }

    int firstUniqCharNew(string s) {
      int count[26];
      int index[26];

      memset(count, 0, sizeof(count));
      memset(index, -1, sizeof(index));

      for (int i = 0; i < (int) s.size(); ++i) {
        int j = s[i] - 'a';

        ++count[j];
        if (index[j] < 0)
          index[j] = i;
      }

      int res = INT_MAX;

      for (int i = 0; i < 26; ++i)
        if (count[i] == 1 && index[i] >= 0 && index[i] < res)
          res = index[i];
          
      return res == INT_MAX ? -1 : res;
    }
};

int main() {
  /*
  Solution sol;
  string s;
  while (true) {
    cin >> s;
    cout << sol.firstUniqChar(s) << endl;
  }
  */

  EXECS(Solution::firstUniqChar);
  EXECS(Solution::firstUniqCharNew);

  return 0;
}