#include "DataStructure.h"
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

      vector<vector<int>> res;

      queue<TreeNode*> q;
      if (root) q.push(root);
      while (!q.empty()) {
        vector<int> temp;
        int N = q.size();
        while (N--) {
          temp.push_back(q.front()->val);
          if (q.front()->left) q.push(q.front()->left);
          if (q.front()->right) q.push(q.front()->right);
          q.pop();
        }
        res.push_back(temp);
      }

      reverse(res.begin(), res.end());
      return res;
    }
};