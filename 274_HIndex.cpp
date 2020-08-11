#include <vector>
#include <iostream>
using namespace std;

struct Node {
  Node *left, *right;
  int val, cnt;
  Node(): val(-1), cnt(0) {}
  Node(int &v): val(v), cnt(1), left(nullptr), right(nullptr) {}
};

class Solution {
  private:
    int res, n;
  public:
    int hIndex(vector<int>& citations) {
      Node *root = nullptr;
      n = citations.size();
      for (int i=0; i<n; ++i)
        root = bst(root, citations[i]);

      res = 0;
      dfs(root, 0);
      return res;
    }

    Node* bst(Node *root, int &value) {
      if (!root)
        return new Node(value);

      if (root->val<value) {
        ++root->cnt;
        root->right = bst(root->right, value);
      }
      else if (root->val>value)
        root->left = bst(root->left, value);
      else
        ++root->cnt;
      return root;
    }

    void dfs(Node* node, int count) {
      if (!node) return;
      res = max(res, min(node->val, node->cnt+count));
      dfs(node->left, node->cnt+count);
      dfs(node->right, count);
    }
};

int main() {
  vector<int> nums = {4, 1, 2};
  Solution sol;
  cout << sol.hIndex(nums) << endl;
  return 0;
}