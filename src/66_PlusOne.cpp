#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> plusOne(vector<int>& digits) {
      vector<int> res;
      int rem = 1;
      for (int i=digits.size()-1; i>=0; --i) {
        int temp = rem + digits[i];
        if (temp==10) 
          temp = 0;
        else 
          rem = 0;
        res.push_back(temp);
      }
      if (rem==1)
        res.push_back(rem);
      reverse(res.begin(), res.end());
      return res;
    }
};