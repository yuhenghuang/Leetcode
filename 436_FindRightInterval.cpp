#include <vector>
#include <climits>
#include <iostream>

using namespace std;

static int emm = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

struct BSTNode {
  BSTNode *left, *right;
  int val, idx;
  BSTNode(const int &v, const int &i): val(v), idx(i), left(nullptr), right(nullptr) { }
};

class Solution {
private:
    BSTNode* insertNode(BSTNode* node, const int &val,  const int &idx) {
      if (!node)
        return new BSTNode(val, idx);
      else if (node->val > val)
        node->left = insertNode(node->left, val, idx);
      else 
        node->right = insertNode(node->right, val, idx);

      return node;
    }

    int searchNode(BSTNode* node, const int &val) {
      if (!node) return -1;

      if (node->val == val)
        return node->idx;
      else if (node->val < val)
        return searchNode(node->right, val);
      else {
        int ret = searchNode(node->left, val);
        return ret==-1 ? node->idx : ret;
      }
    }
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
      int n = intervals.size();

      BSTNode *root = nullptr;
      for (int i=0; i<n; ++i)
        root = insertNode(root, intervals[i][0], i);

      // root = insertNode(root, INT_MAX, -1);

      vector<int> res(n);
      for (int i=0; i<n; ++i)
        res[i] = searchNode(root, intervals[i][1]);

      return res;
    }
};