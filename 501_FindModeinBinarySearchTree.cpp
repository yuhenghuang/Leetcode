#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> findMode(TreeNode* root) {
      int max_freq = 0;

      int val = -1;
      int freq = 0;

      vector<int> res;

      while (root) {
        if (root->left) {
          TreeNode* node = root->left;
          while (node->right && node->right != root)
            node = node->right;

          if (node->right)
            node->right = nullptr;
          else {
            node->right = root;
            root = root->left;
            continue;
          }
        }

        if (root->val == val)
          ++freq;
        else { // larger value found in the tree

          // summarize the result of current value
          if (freq >= max_freq) {
            // update max frequency and clear current results
            if (freq > max_freq) {
              max_freq = freq;
              res.clear();
            }

            res.push_back(val);
          }

          // update current value and frequency
          val = root->val;
          freq = 1;
        }

        root = root->right;
      }

      // summarize the result last value
      if (freq >= max_freq) {
        // update max frequency and clear current results
        if (freq > max_freq) {
          max_freq = freq;
          res.clear();
        }

        res.push_back(val);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::findMode);
  return 0;
}