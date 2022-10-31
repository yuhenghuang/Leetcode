#include <local_leetcode.hpp>


class SegmentTree {
  private:
    struct Node {
      int l; // left bound
      int r; // right bound

      int val; // max # of event in the interval
      int lazy; // the shared increments of the whole interval (all values in [l, r] is larger than lazy)

      Node* left;
      Node* right;

      Node(int _l, int _r): l(_l), r(_r), val(0), lazy(0), left(nullptr), right(nullptr) { }

      int getMid() {
        return l + (r - l) / 2;
      }

      Node*& getLeft() {
        if (left == nullptr)
          left = new Node(l, getMid());

        return left;
      }

      Node*& getRight() {
        if (right == nullptr)
          right = new Node(getMid() + 1, r);

        return right;
      }
    };


    Node* root; // root of segment tree

  void update(Node* root, int l, int r) {
      if (root->r < l || root->l > r)
        return;
      if (l <= root->l && root->r <= r) {
        ++root->val;
        ++root->lazy;
      }
      else {
        update(root->getLeft(), l, r);
        update(root->getRight(), l, r);
        root->val = root->lazy + max(root->left->val, root->right->val);
      }
    }

  public:
    SegmentTree(): root(new Node(0, 1e9)) { }

    ~SegmentTree() { ll::destroy(root); }

    int update(int l, int r) {
      update(root, l, r);
      return root->val;
    }
};


class MyCalendarThree {
  private:
    SegmentTree st;

  public:
    MyCalendarThree() {}
    
    int book(int start, int end) {
      return st.update(start, end - 1);
    }
};


int main() {
  EXECX(
    CTOR(),
    &MyCalendarThree::book
  );
  return 0;
}
