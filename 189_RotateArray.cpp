#include "utils.hpp"

using namespace std;

class Solution {
  private:
    void rotate(vector<int>& nums, int i, int j, int k) {
      if (k<1 || i>=j) return;

      if (j-i>k) {
        swap(nums, i, j, k);
        rotate(nums, i+k, j, k);
      }
      else {
        swap(nums, i, i+k, j-i);
        rotate(nums, i, j, k-j+i);
      }
    }


    void swap(vector<int>& nums, int i, int j, int k) {
      for (int l=0; l<k; ++l)
        ::swap(nums[i+l], nums[j+l]);
    }
  public:
    void rotate(vector<int>& nums, int k) {
      int n=nums.size();
      k = k % n;
      rotate(nums, 0, n-k, k);
    }
};


int main() {
  Solution sol;

  vector<int> nums;
  int k;
  vector<string> args;

  utils::parse_vector_1d<int> parser;

  readlines("Inputs/189_RotateArray.txt") {
    args = utils::string_split(line);

    nums = parser(args[0]);
    k = stoi(args[1]);

    sol.rotate(nums, k);

    utils::print_vector_1d(nums);
  }

  return 0;
}