#include "utils2.hpp"

class Solution {
  private:
    void word2Arr(string& str, int arr[26]) {
      memset(arr, 0, 26 * sizeof(int));
      for (char c : str)
        ++arr[c-'a'];
    }
  
    bool compareArrs(int x[26], int y[26]) {
      for (int i=0; i<26; ++i)
        if (x[i] < y[i])
          return false;
      
      return true;
    }
  
  public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
      int count[26] = {0};
      int tmp[26];
      for (string& s : B) {
        word2Arr(s, tmp);
        for (int i=0; i<26; ++i)
          if (tmp[i] > count[i])
            count[i] = tmp[i];
      }
      
      vector<string> res;
      for (string& s : A) {
        word2Arr(s, tmp);
        if (compareArrs(tmp, count))
          res.push_back(s);
      }
      
      return res;
    }
};


int main() {
  UFUNC(Solution::wordSubsets);
  return 0;
}