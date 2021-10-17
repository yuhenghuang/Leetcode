#include "utils3.hpp"

class Solution {
  private:
    void add(TreeNode* root, const char* c) {
      if (*c == '\0')
        return;

      TreeNode*& child = *c == '0' ? root->left : root->right;
      if (!child)
        child = new TreeNode();

      add(child, ++c);
    }

    void find(TreeNode* root, int n, string& str, string& res) {
      if (!res.empty())
        return;

      if (!root) {
        if (str.size() <= n)
          res = str;
        return;
      }

      str.push_back('0');
      find(root->left, n, str, res);
      str.pop_back();

      str.push_back('1');
      find(root->right, n, str, res);
      str.pop_back();
    }

  public:
    string findDifferentBinaryString(vector<string>& nums) {
      int n = nums.size();

      TreeNode* root = new TreeNode();
      for (string& num : nums)
        add(root, num.c_str());

      string str;
      string res;
      find(root, n, str, res);

      res += string(n - res.size(), '0');

      utils3::destroy(root);

      return res;
    }
};


int main() {
  UFUNCS(Solution::findDifferentBinaryString);
  return 0;
}