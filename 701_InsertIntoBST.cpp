#include "utils.hpp"
#include <fstream>
#include <cmath>

using namespace std;

class Solution {
  public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
      TreeNode* x = root;
      TreeNode* y = nullptr;
      while (x) {
        y = x;
        if (x->val > val)
          x = x->left;
        else
          x = x->right;
      }
      TreeNode* p = new TreeNode(val);

      if (!y)
        root = p;
      else if (y->val > val)
        y->left = p;
      else
        y->right = p;
      return root;
    }
};

int main() {
  Solution sol;
  vector<string> args;
  TreeNode* root;
  int val;

  ifstream f("Inputs/701_InsertIntoBST.txt");
  string line;
  while (getline(f, line)) {
    args = utils::string_split(line);
    root = utils::parse_tree(args[0]);
    val = stoi(args[1]);
    sol.insertIntoBST(root, val);
    utils::print_tree_horizontal(root);
  }

  return 0;
}
