#include "utils.hpp"
#include <climits>

using namespace std;

class Solution {
  public:
    int firstMissingPositive(vector<int>& nums) {
      int n = nums.size();
      for (int i=0; i<n; ++i) {
        if (nums[i]==INT_MIN) continue;
        int idx = nums[i]-1;
        while (nums[i]!=i+1 && (idx>=0 && idx<n && nums[idx]!=idx+1)) {
          swap(nums[i], nums[idx]);
          idx = nums[i] - 1;
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
