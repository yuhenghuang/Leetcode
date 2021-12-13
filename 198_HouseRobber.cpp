#include "utils3.hpp"

class Solution {
  public:
    int rob(vector<int>& nums) {
      int n = nums.size();
      if (n==0) return 0;

      for (int i=n-2; i>=0; --i)
        nums[i] = max(nums[i] + (i+2<n ? nums[i+2] : 0), nums[i+1]);
      return nums[0];
    }
};

/*
void parse_vec(vector<int> &vec) {
  ifstream f;

  // not necessary to handle exceptions by users
  // cpp is designed to handle exceptions in the destructor...
  
  try {
    f.open("Inputs/198_HouseRobber.txt");
    string line;
    while (getline(f, line)) {
      line = regex_replace(line, regex("[\\[\\] ]"), "");
      istringstream ss(line);
      string numstr;
      while (getline(ss, numstr, ',')) {
        vec.push_back(stoi(numstr));
      }
    }
  }
  catch (exception &e) {
    if (f.is_open())
      f.close();
  }
  if (f.is_open())
    f.close();
}
*/

int main() {
  UFUNCS(Solution::rob);
  return 0;
}
