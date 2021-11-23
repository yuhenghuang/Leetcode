#include "utils3.hpp"

class KthLargest {
  private:
    struct Node {
      Node* left;
      Node* right;
      int val;
      // count of current values
      int count;
      // count of nodes less than val
      int large;

      Node(int _val): val(_val), count(1), large(0), left(nullptr), right(nullptr) { }
    };

    int k;
    Node* root;

    Node* append(Node* root, int val) {
      if (!root)
        return new Node(val);

      if (val < root->val) 
        root->left = append(root->left, val);
      else if (val > root->val) {
        ++root->large;
        root->right = append(root->right, val);
      }
      else
        ++root->count;

      return root;
    }

    int query(Node* root, int k) {
      if (root->large >= k)
        return query(root->right, k);
      else if (root->large + root->count < k)
        return query(root->left, k - root->large - root->count);
      else
        return root->val;
    }

  public:
    KthLargest(int _k, vector<int>& nums): k(_k) {
      root = new Node(INT_MIN);

      for (int num : nums)
        append(root, num);
    }
    
    int add(int val) {
      append(root, val);

      return query(root, k);
    }

    ~KthLargest() { utils3::destroy(root); };
};


int main() {
  UFUNCX(
    CTOR(int, vector<int>&),
    &KthLargest::add
  );
  return 0;
}