#include "utils.hpp"
#include <fstream>

using namespace std;

class Solution {
  private:
    TreeNode* divideAndCounqure(const int& l, const int& r, vector<int>& nums) {
      if (l>r) 
        return nullptr;
      
      int m = l + (r-l)/2;
      TreeNode* root = new TreeNode(nums[m]);
      root->left = divideAndCounqure(l, m-1, nums);
      root->right = divideAndCounqure(m+1, r, nums);

      return root;
    }
  public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return divideAndCounqure(0, nums.size()-1, nums);
    }
};

int main() {
  Solution sol;

  vector<int> nums;
  TreeNode* root;
  utils::parse_vector_1d<int> parser;

  ifstream f("Inputs/108_SortedArrayToBST.txt");
  string line;
  while (getline(f, line)) {
    nums = parser(line);
    root = sol.sortedArrayToBST(nums);
    utils::print_tree_horizontal(root);
  }
  
  return 0;
}
