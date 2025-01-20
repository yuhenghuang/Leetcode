#include <local_leetcode.hpp>

class Node {
  public:
    Node(): next(nullptr)  {}
    Node(TreeNode* n): node(n), next(nullptr) {}
    TreeNode* node;
    Node* next;
};

class BSTIterator {
  private:
    Node* head, * curr;
  public:
    BSTIterator(TreeNode* root) {
      stack<TreeNode*> s;
      head = new Node();
      curr = head;
      while (root || !s.empty()) {
        while (root) {
          s.push(root);
          root = root->left;
        }
        root = s.top(); s.pop();
        curr->next = new Node(root);
        curr = curr->next;
        root = root->right;
      }
      curr = head;
    }
    
    /** @return the next smallest number */
    int next() {
      curr = curr->next;
      return curr->node->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
      return curr->next!=nullptr;
    }

    ~BSTIterator() { ll::destroy(head); }
};


class BSTIter {
  private:
    stack<TreeNode*> s;

    void pushLeft(TreeNode* root) {
      while (root) {
        s.push(root);
        root = root->left;
      }
    }
  public:
    BSTIter(TreeNode* root) {
      pushLeft(root);
    }

    int next() {
      TreeNode* node = s.top();
      s.pop();
      pushLeft(node->right);
      return node->val;
    }

    bool hasNext() {
      return !s.empty();
    }
};


int main() {
  /*
  TreeNode* root = new TreeNode(7);
  root->left = new TreeNode(3);
  root->right = new TreeNode(15, new TreeNode(9), new TreeNode(20));
  BSTIterator iter(root);
  cout << iter.next() << endl;
  */

  EXECX(
    CTOR(TreeNode*),
    &BSTIterator::next,
    &BSTIterator::hasNext
  );

  EXECX(
    CTOR(TreeNode*),
    &BSTIter::next,
    &BSTIter::hasNext
  );
  return 0;
}