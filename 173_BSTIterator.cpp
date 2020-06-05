#include "DataStructure.h"
#include <stack>
#include <iostream>
using namespace std;

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
};

int main() {
  TreeNode* root = new TreeNode(7);
  root->left = new TreeNode(3);
  root->right = new TreeNode(15, new TreeNode(9), new TreeNode(20));
  BSTIterator iter(root);
  cout << iter.next() << endl;
  return 0;
}