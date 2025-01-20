#include "DataStructure.h"
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
      queue<pair<TreeNode*, int>> q;
      if (!root) return root;
      q.push(make_pair(root, 0));

      int depth=-1, size, idx;
      TreeNode* node;
      vector<int> temp;
      while (!q.empty()) {
        size = q.size();
        temp.clear();
        while (size--) {
          auto p = q.front();
          node = p.first;
          idx = p.second;
          temp.push_back(idx);
          q.pop();
          if (node->left) q.push(make_pair(node->left, 2*idx));
          if (node->right) q.push(make_pair(node->right, 2*idx+1));
        }
        depth++;
      }

      int l = temp.front(), r = temp.back(), shift=0;
      while (depth>0) {
        int mid = shift + 1 << (--depth);
        if (r < mid)
          root = root->left;
        else if (l >= mid) {
          root = root->right;
          shift += 1 << depth;
        }
        else
          break;
      }
      return root;
    }
};