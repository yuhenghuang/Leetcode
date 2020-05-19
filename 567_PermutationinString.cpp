#include <string>
#include <iostream>
using namespace std;

class Solution {
  public:
    bool checkInclusion(string s1, string s2) {
      int n1 = s1.length(), n2 = s2.length();
      if (n1 <= n2) {
        int ans[26] = {0}, cur[26] = {0};
        bool flag;
        for (int i=0; i<n2; ++i) {
          ++cur[s2[i]-'a'];
          if (i<n1) 
            ++ans[s1[i]-'a'];
          else 
            --cur[s2[i-n1]-'a'];

          if (i>n1-2) {
            flag = true;
            for (int j=0; j<26; ++j)
              if (ans[j]!=cur[j]) {
                flag = false;
                break;
              }
            if (flag) return true;
          }
        }
      }
      return false;
    }
};

int main() {
  int arr[26] = {0};
  cout << arr[25] << endl;
  return 0;
}