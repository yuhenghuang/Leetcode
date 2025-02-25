/*
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
*/

#define _LL_DELETE_RETURN_POINTER
#include <local_leetcode.hpp>

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

    
    TreeNode* recoverFromPreorderNew(string traversal) {
      auto next_int = [](const char* &c_ptr) {
        int res = 0;
        for (;*c_ptr != '\0' and *c_ptr != '-'; ++c_ptr)
          res = res * 10 + (*c_ptr - '0');
        return res;
      };

      auto next_depth = [](const char* &c_ptr) {
        size_t depth = 0;
        for (;*c_ptr == '-'; ++c_ptr)
          ++depth;
        return depth;
      };

      const char* c_ptr = traversal.c_str();

      TreeNode* root = new TreeNode(next_int(c_ptr));

      stack<TreeNode*> s;
      s.push(root);
      while (*c_ptr != '\0') {
        size_t depth = next_depth(c_ptr);

        TreeNode* node = new TreeNode(next_int(c_ptr));

        for (; s.size() > depth; s.pop());

        if (s.top()->left)
          s.top()->right = node;
        else
          s.top()->left = node;
        
        s.push(node);
      }

      return root;
    }
};


int main() {
  EXECS(Solution::recoverFromPreorder);
  EXECS(Solution::recoverFromPreorderNew);
  return 0;
}