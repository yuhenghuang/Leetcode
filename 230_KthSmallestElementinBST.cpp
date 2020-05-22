#include "DataStructure.h"
#include <iostream>
#include <stack>
using namespace std;

static int arr = [](){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();

class Solution {
  public:
    int kthSmallest(TreeNode* root, int k) {
      stack<TreeNode*> s;
      while (!s.empty() || root) {
        while (root) {
          s.push(root);
          root = root->left;
        }

        do {
          --k;
          if (k==0)
            return s.top()->val;
          root = s.top();
          s.pop();
        } while (!s.empty() && !root->right);

        root = root->right;
      }
      return -1;
    }
};