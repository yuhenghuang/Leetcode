#include <string>
using namespace std;

class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
      int arr[26] = {0};
      for (char c : magazine)
        ++arr[c-'a'];
      for (char c : ransomNote)
        if (--arr[c-'a']<0)
          return false;
      return true;
    }
};