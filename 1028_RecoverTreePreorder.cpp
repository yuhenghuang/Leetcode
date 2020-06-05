#include "DataStructure.h"
#include <vector>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

static int emm = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

class Solution {
  private:
    int idx, N;
    int nextInt(string& s) {
      int p = idx;
      while (idx<N && s[idx]!='-')
        ++idx;
      return stoi(s.substr(p, idx-p));
    }
    int nextDepth(string& s) {
      int p = idx;
      while (idx<N && s[idx]=='-')
        ++idx;
      return idx-p;
    }
  public:
    TreeNode* recoverFromPreorder(string S) {
      idx = 0;
      N = S.size();
      int val = nextInt(S), depth;
      TreeNode* root = new TreeNode(val);
      // vector<TreeNode*> memo(1000);
      // memo[0] = root;
      stack<TreeNode*> s;
      s.push(root);
      while (idx<N) {
        depth = nextDepth(S);
        val = nextInt(S);
        // memo[depth] = new TreeNode(val);
        // if (memo[depth-1]->left)
        //   memo[depth-1]->right = memo[depth];
        // else
        //   memo[depth-1]->left = memo[depth];
        TreeNode* node = new TreeNode(val);
        while (s.size()>depth)
          s.pop();
        if (s.top()->left)
          s.top()->right = node;
        else
          s.top()->left = node;
        s.push(node);
      }
      return root;
    }
};