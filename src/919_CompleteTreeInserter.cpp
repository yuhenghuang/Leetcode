#include "DataStructure.h"
#include <queue>
#include <iostream>
using namespace std;

class CBTInserter {
  private:
    TreeNode* r;
    queue<TreeNode*> q;
  public:
    CBTInserter(TreeNode* root) {
      if (root==nullptr) return;

      r = root;
      queue<TreeNode*> bfs;
      bfs.push(root);
      while (!bfs.empty()) {
        root = bfs.front(); bfs.pop();
        q.push(root);
        if (root->left!=nullptr) bfs.push(root->left);
        if (root->right!=nullptr) bfs.push(root->right);
      }
    }
    
    int insert(int v) {
      TreeNode* p = new TreeNode(v);
      if (r==nullptr) {
        r = p;
        q.push(r);
      }
      else {
        while (q.front()->left!=nullptr && q.front()->right!=nullptr)
          q.pop();

        if (q.front()->left==nullptr)
          q.front()->left = p;
        else
          q.front()->right = p;
        q.push(p);
      }
      return q.front()->val;
    }
    
    TreeNode* get_root() {
      return r;
    }
};

int main() {
  TreeNode t(1);
  CBTInserter sol(&t);
  sol.insert(2);
  TreeNode* root = sol.get_root();
  cout << root->val << endl;
}