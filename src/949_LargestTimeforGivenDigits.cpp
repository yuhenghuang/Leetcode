#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
  private:
    vector<int> digits;
    string dfs(int idx, const int &prev) {
      int num;
      string ret="";
      for (int i=0; i<4; ++i) {
        if (digits[i]==-1) continue;
        num = digits[i];
        digits[i] = -1;

        switch (idx) {
          case 0: 
            if (num<3) 
              ret = dfs(idx+1, num);
            break;
          case 1:
            if ((prev==2 && num <4) || prev!=2) 
              ret = dfs(idx+1, num);
            break;
          case 2:
            if (num<6)
              ret = dfs(idx+1, num);
            break;
          case 3:
            return to_string(num);
          default: break;
        }

        if (ret.length()>0)
          return to_string(num) + ret;
        digits[i] = num;
      }
      return ret;
    }
  public:
    string largestTimeFromDigits(vector<int>& A) {
      sort(A.begin(), A.end(), greater<int>());
      digits = A;

      string res = dfs(0, 0);
      if (res.length()>0)
        res.insert(2, 1, ':');
      return res;
    }
};

int main() {
  Solution sol;
  // vector<int> A = {1,2,3,4};
  vector<int> A = {5,5,5,5};
  cout << sol.largestTimeFromDigits(A) << endl;
  return 0;
}
