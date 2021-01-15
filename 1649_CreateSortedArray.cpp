#include "utils.hpp"

struct Node {
  Node* left;
  Node* right;
  int val, cnt, cuml;
  Node(int v): left(nullptr), right(nullptr), val(v), cnt(1), cuml(0) { }
};

class Solution {
  private:
    Node* insert(Node* root, int v) {
      if (!root)
        root = new Node(v);
      else if (root->val > v) {
        ++root->cuml;
        root->left = insert(root->left, v);
      }
      else if (root->val < v) {
        // ++root->cuml;
        root->right = insert(root->right, v);
      }
      else
        ++root->cnt;

      return root;
    }

    void find(Node* root, int val, int& cuml, int& cnt) {
      if (root->val < val) {
        cuml += root->cuml + root->cnt;
        find(root->right, val, cuml, cnt);
      }
      else if (root->val > val)
        find(root->left, val, cuml, cnt);
      else
        cnt = root->cnt;
    }


    void update(int* tree, int n, int i) {
      while (i <= n) {
        ++tree[i];
        i += -i & i;
      }
    }

    int query(int* tree, int i) {
      int ans = 0;
      while (i > 0) {
        ans += tree[i];
        i -= -i & i;
      }
      return ans;
    }

  public:
    int createSortedArray(vector<int>& instructions) {
      // Binary Index Tree!!
      // to be studied...

      int m = 0;
      for (int num : instructions)
        if (num > m)
          m = num;

      ++m;
      int* tree = new int[m];
      memset(tree, 0, m*sizeof(int));

      int n = instructions.size();
      static constexpr int mod = 1e9 + 7;
      int res=0;
      for (int i=0; i<n; ++i) {
        res += min(query(tree, instructions[i]-1), i - query(tree, instructions[i]));
        res %= mod;
        update(tree, m, instructions[i]);
      }

      return res;
    }

    int createSortedArrayToDo(vector<int>& instructions) {
      // to be debugged
      static constexpr int mod = 1e9 + 7;
      int n = instructions.size();
      int res=0;
      Node* root = nullptr;
      int cuml, cnt;
      for (int i=0; i<n; ++i) {
        root = insert(root, instructions[i]);
        cuml = 0;
        find(root, instructions[i], cuml, cnt);
        res += min(cuml, i+1-cuml-cnt);
        res %= mod;
      }

      return res;
    }
};


int main() {
  {
    UFUNC(Solution::createSortedArray);
  }
  return 0;
}