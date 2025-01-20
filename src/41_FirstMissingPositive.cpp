#include "utils.hpp"

using namespace std;

class Solution {
  public:
    int firstMissingPositive(vector<int>& nums) {
      int n = nums.size();
      for (int i=0; i<n; ++i) {
        int num = nums[i];
        while (num!=i+1 && (num>0 && num<=n && nums[num-1]!=num)) {
          swap(nums[i], nums[num-1]);
          num = nums[i];
        }
      }

      for (int i=0; i<n; ++i)
        if (nums[i]!=i+1)
          return i+1;
      
      return n+1;
    }
};

int main() {
  Solution sol;

  vector<int> nums;
  utils::parse_vector_1d<int> parser;

  ifstream f("Inputs/41_FirstMissingPositive.txt");
  string line;
  while (getline(f, line)) {
    nums = parser(line);
    cout << sol.firstMissingPositive(nums) << endl;
  }

  return 0;
}
