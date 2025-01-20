#include <local_leetcode.hpp>

class TreeIterator {
  private:
    stack<TreeNode*> s;

    void pushLeft(TreeNode* root) {
      while (root) {
        s.push(root);
        root = root->left;
      }
    }

  public:
    TreeIterator() { }

    TreeIterator(TreeNode* root) {
      pushLeft(root);
    }

    bool hasNext() const { return !s.empty(); }

    int& operator*() {
      return s.top()->val;
    }

    TreeIterator& operator++() {
      TreeNode* root = s.top()->right;
      s.pop();

      pushLeft(root);

      return *this;
    }

    TreeIterator operator++(int) {
      TreeIterator tmp(*this);

      ++*this;

      return tmp;
    }

    bool operator==(TreeIterator& rhs) const {
      // short-circuit to evaluate compare to end faster.
      return (s.empty() && rhs.s.empty()) || (s.size() == rhs.s.size() && s.top() == rhs.s.top());
    }

    bool operator!=(TreeIterator& rhs) const {
      // short-circuit to evaluate compare to end faster.
      return !(*this == rhs);
    }

    void swap(TreeIterator& rhs)  {
      ::swap(s, rhs.s);
    }
};

class Solution {
  public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
      TreeIterator iter1(root1);
      TreeIterator iter2(root2);
      TreeIterator end;

      vector<int> res;
      while (iter1 != end && iter2 != end) {
        if (*iter1 < *iter2) {
          // res.push_back(*iter1);
          // ++iter1;
          res.push_back(*iter1++);
        }
        else {
          // res.push_back(*iter2);
          // ++iter2;
          res.push_back(*iter2++);
        }
      }

      if (iter1 == end)
        iter1.swap(iter2);

      while (iter1 != end) {
        // res.push_back(*iter1);
        // ++iter1;
        res.push_back(*iter1++);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::getAllElements);
  return 0;
}