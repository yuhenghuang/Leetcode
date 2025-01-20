/*
#include "utils.hpp"
#include <fstream>
#include <cmath>

using namespace std;
*/

#define _LL_NONTRIVIAL_SOLUTION_CTOR
#include <local_leetcode.hpp>

class Solution {
  private:
    vector<TreeNode*> nodes;

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
      TreeNode* p = nodes.emplace_back(new TreeNode(val));

      if (!y)
        root = p;
      else if (y->val > val)
        y->left = p;
      else
        y->right = p;
      return root;
    }

    TreeNode* insertIntoBSTdfs(TreeNode* root, int val) {
      if (!root)
        root = nodes.emplace_back(new TreeNode(val));
      else if (root->val > val)
        root->left = insertIntoBSTdfs(root->left, val);
      else if (root->val < val)
        root->right = insertIntoBSTdfs(root->right, val);

      return root;
    }

    ~Solution() {
      for (auto& ptr : nodes)
        delete ptr;
    }
};


int main() {
  /*
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
  */

  EXECS(Solution::insertIntoBST);
  EXECS(Solution::insertIntoBSTdfs);
  return 0;
}
