#include "utils.hpp"

using namespace std;

const static int emm = [](){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class Codec {
  private:
    int val;

    void next_val(istringstream& ss) {
      string s;
      if (getline(ss, s, ','))
        val = stoi(s);
      else
        val = -1;
    }

    TreeNode* dfs_dese(istringstream& ss, const int& rbound) {
      if (val<0)
        return nullptr;

      TreeNode *root = new TreeNode(val);
      next_val(ss);

      if (val < root->val) 
        root->left = dfs_dese(ss, root->val);

      if (val < rbound)
        root->right = dfs_dese(ss, rbound);

      return root;
    }

    void dfs_ser(TreeNode* root, string& s) {
      if (root==nullptr)
        return;

      if (s.size()>0)
        s.push_back(',');
      s.append(to_string(root->val));

      dfs_ser(root->left, s);
      dfs_ser(root->right, s);
    }


  public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      string data;

      dfs_ser(root, data);
      return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      val = -1;
      istringstream ss(data);
      next_val(ss);

      return dfs_dese(ss, 10001);
    }
};


int main() {
  Codec coder;

  TreeNode *root;

  ifstream f("Inputs/449_SerializeDeserializeBST.txt");
  string line;
  while (getline(f, line)) {
    root = utils::parse_tree(line);
    string tree = coder.serialize(root);
    TreeNode *node = coder.deserialize(tree);

    utils::print_tree_horizontal(node);
  }

  return 0;
}