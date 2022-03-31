#include <local_leetcode.hpp>

class Solution {
  public:
    int search(vector<int>& nums, int target) {
      int l=0, r=nums.size(), m;
      while (l<r) {
        m = l + (r-l)/2;
        if (nums[m]<target)
          l = m+1;
        else
          r = m;
      }

      return (l<nums.size() && nums[l]==target) ? l : -1;
    }

    int searchNew(vector<int>& nums, int target) {
      int l = 0, r = static_cast<int>(nums.size()) - 1;

      while (l <= r) {
        int m = l + (r - l) / 2;

        if (nums[m] < target)
          l = m + 1;
        else if (nums[m] > target)
          r = m - 1;
        else
          return m;
      }

      return -1;
    }
};


int main() {
  /*
  Solution sol;

  vector<string> args;
  vector<int> nums;
  int target;
  utils::parse_vector_1d<int> parser;

  ifstream f("Inputs/704_BinarySearch.txt");
  string line;
  while (getline(f, line)) {
    args = utils::string_split(line);
    nums = parser(args[0]);
    target = stoi(args[1]);

    cout << sol.search(nums, target) << endl;
  }
  */

  EXECS(Solution::search);
  EXECS(Solution::searchNew);

  return 0;
}
