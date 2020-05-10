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
};

int main() {
  Solution sol;
  string s;
  while (true) {
    cin >> s;
    cout << sol.firstUniqChar(s) << endl;
  }
  return 0;
}