#include "DataStructure.h"
#include <deque>
#include <iostream>
using namespace std;

static int emm = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

class Solution {
  public:
    int widthOfBinaryTree(TreeNode* root) {
      deque<pair<TreeNode*, int>> dq;
      if (root) dq.push_back(make_pair(root, 0));

      int res=0;
      while (!dq.empty()) {
        res = max(res, dq.back().second - dq.front().second);
        int N = dq.size(), base = dq.front().second;
        while (N--) {
          auto p = dq.front();
          if (p.first->left) dq.push_back(make_pair(p.first->left, (p.second-base)*2));
          if (p.first->right) dq.push_back(make_pair(p.first->right, (p.second-base)*2+1));
          dq.pop_front();
        }
      }
      return res+1;
    }
};