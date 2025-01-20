#include <map>
#include "utils3.hpp"

class RangeModule {
  private:
    typedef pair<int, int> pii;
    map<int, int> tree_map;

  public:
    RangeModule() {
      tree_map.emplace(0, 0);
      tree_map.emplace(INT_MAX, INT_MAX);
    }
    
    void addRange(int left, int right) {
      auto after = tree_map.upper_bound(left);
      auto before = prev(after);

      for (; after->second <= right; after = tree_map.erase(after));


      if (before->second >= left && after->first <= right) {
        before->second = after->second;
        tree_map.erase(after);
      }
      else if (before->second >= left) {
        if (before->second < right)
          before->second = right;
      }
      else if (after->first <= right) {
        tree_map.emplace(left, after->second);
        tree_map.erase(after);
      }
      else
        tree_map.emplace(left, right);

    }
    
    bool queryRange(int left, int right) {
      auto before = prev(tree_map.upper_bound(left));

      return before->second >= right;
    }
    
    void removeRange(int left, int right) {
      auto after = tree_map.upper_bound(left);
      auto before = prev(after);

      for(; after->second <= right; after = tree_map.erase(after));

      if (before->second > left) {
        if (before->second > right)
          tree_map.emplace(right, before->second);
        before->second = left;
      }

      if (after->first < right) {
        int tmp = after->second;
        tree_map.erase(after);
        tree_map.emplace(right, tmp);
      }

    }  
};


class SegmentTree {
  private:
    struct Node {
      Node* left;
      Node* right;

      // start, end of interval
      int s, e;
      bool flag;
      Node(int _s, int _e, bool _f = false):
        s(_s), e(_e), flag(_f),
        left(nullptr), right(nullptr) { }

      int getMid() { return s + (e-s) / 2;}

      Node* getLeft() {
        if (!left) 
          left = new Node(s, getMid(), flag);

        return left;
      }

      Node* getRight() {
        if (!right)
          right = new Node(getMid()+1, e, flag);

        return right;
      }
    };

    bool add(Node* node, int start, int end) {
      if (node->s > end || node->e < start)
        return false;
      else if (start <= node->s && node->e <= end) 
        return node->flag = true;
      

      if (!node->flag) {
        int m = node->getMid();
        return node->flag = 
          add(node->getLeft(), start, m) &&
          add(node->getRight(), m+1, end);
      }

      return true;
    }

    void remove(Node* node, int start, int end) {
      if (!node || node->s > end || node->e < start)
        return;

      node->flag = false;

      int m = node->getMid();
      remove(node->left, start, m);
      remove(node->right, m+1, end);
    }

    bool query(Node* node, int start, int end) {
      if (start > end)
        return true;
      else if (!node)
        return false;
      else if (node->s > end || node->e < start)
        return true;
      else if (start <= node->s && node->e <= end)
        return node->flag;
      
      int m = node->getMid();
      return query(node->left, start, m) &&
             query(node->right, m+1, end);
    }

    Node* root;

  public:
    SegmentTree() {
      root = new Node(0, INT_MAX);
    }

    void add(int start, int end) {
      add(root, start, end);
    }

    void remove(int start, int end) {
      remove(root, start, end);
    }

    bool query(int start, int end) {
      return query(root, start, end);
    }

    ~SegmentTree() { utils3::destroy(root); }
};


class RangeModuleST {
  private:
    SegmentTree st;

  public:
    RangeModuleST() { }
    
    void addRange(int left, int right) {
      return st.add(left, right-1);
    }
    
    bool queryRange(int left, int right) {
      return st.query(left, right-1);
    }
    
    void removeRange(int left, int right) {
      return st.remove(left, right-1);
    }
};

int main() {
  UFUNCX(
    CTOR(),
    &RangeModule::addRange,
    &RangeModule::queryRange,
    &RangeModule::removeRange
  );
  // wrong answer
  UFUNCX(
    CTOR(),
    &RangeModuleST::addRange,
    &RangeModuleST::queryRange,
    &RangeModuleST::removeRange
  );
  return 0;
}