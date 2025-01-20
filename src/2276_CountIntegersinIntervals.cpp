#include <local_leetcode.hpp>

class CountIntervals {
  private:
    struct Node {
      int l, r;
      int count; // if the range is all covered
      Node* left;
      Node* right;

      Node(int _l, int _r): 
        l(_l), r(_r), count(0), 
        left(nullptr), right(nullptr) 
      { }

      int getMid() { return l + (r - l) / 2; }

      // create left and right children lazily
      Node*& getLeft() {
        if (!left)
          left = new Node(l, getMid());

        return left;
      }

      Node*& getRight() {
        if (!right)
          right = new Node(getMid()+1, r);

        return right;
      }
    };

    Node* root;

    int update(Node* node, int s, int e) {
      if (node->count == node->r - node->l + 1) {
        // do nothing
      }
      // node in [s, e]
      else if (s <= node->l && node->r <= e)
        node->count = node->r - node->l + 1;
      // part of node in [s, e]
      else if (s <= node->r && e >= node->l) 
        node->count = update(node->getLeft(), s, e) + update(node->getRight(), s, e);

      return node->count;
    }

  public:
    CountIntervals(): root(new Node(1, 1e9)) { }
    
    void add(int left, int right) { update(root, left, right); }
    
    int count() { return root->count; }

    ~CountIntervals() { ll::destroy(root); }
};


int main() {
  EXECX(
    CTOR(),
    &CountIntervals::add,
    &CountIntervals::count
  );
  return 0;
}