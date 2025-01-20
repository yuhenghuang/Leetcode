#include "utils.hpp"
#include <stack>

using namespace std;

class Solution {
  private:
    int res, distance;

    void dfs1(TreeNode* root, stack<TreeNode*>& s) {
      if (!root) return;

      if (root->left==nullptr && root->right==nullptr) {
        dfs2(root, s, distance-1);
      }
      else {
        s.push(root);
        dfs1(root->left, s);
        dfs1(root->right, s);
        s.pop();
      }
    }

    void dfs2(TreeNode* prev, stack<TreeNode*>& s, const int& dist) {
      if (dist<0 || s.empty()) return;

      TreeNode* node = s.top();
      dfs3(node->right==prev ? node->left : node->right, dist-1);

      s.pop();
      dfs2(node, s, dist-1);
      s.push(node);
    }

    void dfs3(TreeNode* node, const int& dist) {
      if (dist<0 || node==nullptr) return;

      if (node->left==nullptr && node->right==nullptr) {
        ++res;
      }
      else {
        dfs3(node->left, dist-1);
        dfs3(node->right, dist-1);
      }
    }

  public:
    int countPairs(TreeNode* root, int distance) {
      res = 0;
      this->distance = distance;
      stack<TreeNode*> s;
      dfs1(root, s);

      return res/2;
    }
};

int main() {
  Solution sol;

  vector<string> args;
  TreeNode* root;
  int dist;

  ifstream f("Inputs/1530_NumofGoodLeafNodesPairs.txt");
  string line;
  while (getline(f, line)) {
    args = utils::string_split(line);
    root = utils::parse_tree(args[0]);
    dist = stoi(args[1]);

    cout << sol.countPairs(root, dist) << endl;
  }

  return 0;
}