#define NARY_TREE_NODE
#define _LL_DELETE_RETURN_POINTER
#include <local_leetcode.hpp>


class Codec {
  public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
      if (!root)
        return nullptr;

      TreeNode* root_out = new TreeNode(root->val);

      queue<Node*> q;
      queue<TreeNode*> p;

      for (auto& child : root->children) 
        q.push(child);

      bool left = true;
      TreeNode* node = root_out;

      while (!q.empty()) {
        root = q.front();
        q.pop();

        if (root) {
          if (left)
            node->left = p.emplace(new TreeNode(root->val));
          else 
            node->right = p.emplace(new TreeNode(root->val));

          q.push(nullptr);

          for (auto& child : root->children) 
            q.push(child);
        }

        if (!left) {
          if (!p.empty()) {
            node = p.front();
            p.pop();
          }
          else
            break;
        }

        left = !left;
      }

      return root_out;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
      if (!root)
        return nullptr;

      Node* root_out = new Node(root->val);

      queue<TreeNode*> q;
      queue<Node*> p;

      q.push(root->left);
      q.push(root->right);

      Node* node = root_out;

      while (!q.empty()) {
        root = q.front();
        q.pop();

        if (root) {
          q.push(root->left);
          q.push(root->right);

          p.push( node->children.emplace_back(new Node(root->val)) );
        }
        else if (!p.empty()) {
          node = p.front();
          p.pop();
        }
        else
          break;
      }

      return root_out;
    }
};


class Solution {
  private:
    static Codec codec;

  public:
    Node* encodeDecode(Node* root_orig) {
      TreeNode* root_binary = codec.encode(root_orig);

      Node* root_out = codec.decode(root_binary);

      // release binary tree
      ll::destroy(root_binary);

      return root_out;
    }
};

Codec Solution::codec;


int main() {
  EXECS(Solution::encodeDecode);
  return 0;
}  