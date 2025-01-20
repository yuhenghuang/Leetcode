#include "utils.hpp"
#include <fstream>
#include <cmath>


using namespace std;

class Solution {
  public:
    vector<int> majorityElement(vector<int>& nums) {
      int n = nums.size();

      int *num1=nullptr, *num2=nullptr;
      int count1=0, count2=0;
      for (int& num : nums) {
        if (num1 && *num1==num) 
          ++count1;
        else if (num2 && *num2==num)
          ++count2;
        else if (count1==0) {
          num1 = &num;
          ++count1;
        }
        else if (count2==0) {
          num2 = &num;
          ++count2;
        }
        else {
          --count1;
          --count2;
        }
      }

      count1 = count2 = 0;

      for (int& num : nums) {
        if (num1 && *num1==num) ++count1;
        if (num2 && *num2==num) ++count2;
      }

      vector<int> res;
      if (count1>n/3) res.push_back(*num1);
      if (count2>n/3) res.push_back(*num2);

      return res;
    }
};

int main() {
  Solution sol;

  fstream f("Inputs/229_MajorityElementII.txt");
  utils::parse_vector_1d<int> parser;
  vector<int> nums, res;
  string line;

  while (getline(f, line)) {
    nums = parser(line);
    res = sol.majorityElement(nums);
    utils::print_vector_1d(res);
  }

  return 0;
}
