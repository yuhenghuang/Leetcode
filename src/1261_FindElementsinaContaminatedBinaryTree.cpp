#include <local_leetcode.hpp>

class FindElements {
  private:
    vector<bool> memo;
  public:
    FindElements(TreeNode* root) {
      memo = vector<bool>(1e6+1, false);
      dfs(root, 0);
    }

    void dfs(TreeNode* node, int idx) {
      if (!node || idx>1e6) return;
      else memo[idx] = true;
      dfs(node->left, idx*2+1);
      dfs(node->right, idx*2+2);
    }
    
    bool find(int target) {
      return memo[target];
    }
};


class FindElementsNew {
  private:
    unordered_set<int> s;

    void dfs(TreeNode* node, int i) {
      if (not node or i > 1e6) 
        return;
      else 
        s.insert(i);

      dfs(node->left, i * 2 + 1);
      dfs(node->right, i * 2 + 2);
    }

  public:
    FindElementsNew(TreeNode* root) {
      dfs(root, 0);
    }
    
    bool find(int target) {
      return s.count(target);
    }
};


int main() {
  EXECX(
    CTOR(TreeNode*),
    &FindElements::find
  );

  EXECX(
    CTOR(TreeNode*),
    &FindElementsNew::find
  );
  return 0;
}
