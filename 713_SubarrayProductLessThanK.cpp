#include "utils.hpp"

using namespace std;

class Solution {
  public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
      int n=nums.size(), res=0;

      int l=0, prod=1;
      for (int i=0; i<n; ++i) {
        prod *= nums[i];

        while (l<=i && prod>=k) 
          prod /= nums[l++];

        res += i-l+1;
      }

      return res;
    }
};

int main() {
  Solution sol;

  vector<string> args;
  utils::parse_vector_1d<int> parser;
  vector<int> nums;
  int k;

  ifstream f("Inputs/713_SubarrayProductLessThanK.txt");
  string line;
  while (getline(f, line)) {
    args = utils::string_split(line);
    nums = parser(args[0]);
    k = stoi(args[1]);

    cout << sol.numSubarrayProductLessThanK(nums, k) << endl;
  }

  return 0;
}