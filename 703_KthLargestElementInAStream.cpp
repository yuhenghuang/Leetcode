#include <local_leetcode.hpp>

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

      Node(int _val): left(nullptr), right(nullptr), val(_val), count(1), large(0) { }
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

    ~KthLargest() { ll::destroy(root); };
};


class KthLargestPQ {
  private:
    int k;
    priority_queue<int, vector<int>, greater<int>> heap; // min heap

  public:
    KthLargestPQ(int k, vector<int>& nums): k(k) {
      for (int num : nums)
        add(num);
    }
    
    int add(int val) {
      if (heap.size() < k)
        heap.push(val);
      else if (val > heap.top()) {
        heap.pop();
        heap.push(val);
      }

      return heap.top();
    }
};


int main() {
  EXECX(
    CTOR(int, vector<int>&),
    &KthLargest::add
  );

  EXECX(
    CTOR(int, vector<int>&),
    &KthLargestPQ::add
  );
  return 0;
}