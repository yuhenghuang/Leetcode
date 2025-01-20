#include <map>
#include "utils3.hpp"

struct Node {
  Node* left;
  Node* right;
  int ss, se;
  int count;

  Node(int _ss, int _se): ss(_ss), se(_se), count(0), left(nullptr), right(nullptr) { }

  int getMid() {
    return ss + (se - ss) / 2;
  }

  Node* getLeft() {
    if (!left)
      left = new Node(ss, getMid());

    return left;
  }

  Node* getRight() {
    if (!right)
      right = new Node(getMid() + 1, se);

    return right;
  }
};

class Solution {
  private:
    void addRange(Node* root, int qs, int qe) {
      if (root->se < qs || root->ss > qe)
        return;
      else if (qs <= root->ss && root->se <= qe) {
        ++root->count;
        return;
      }

      addRange(root->getLeft(), qs, qe);
      addRange(root->getRight(), qs, qe);
    }

    void removeRange(Node* root, int qs, int qe) {
      if (!root || root->se < qs || root->ss > qe)
        return;
      else if (qs <= root->ss && root->se <= qe) {
        --root->count;
        return;
      }

      removeRange(root->left, qs, qe);
      removeRange(root->right, qs, qe);
    }

    int getLength(Node* root) {
      if (!root)
        return 0;
      else if (root->count > 0)
        return root->se - root->ss + 1;
      else
        return getLength(root->left) + getLength(root->right);
    }

    struct ranges {
      vector<pair<int, int>> add, rm;
    };

  public:
    int rectangleArea(vector<vector<int>>& rectangles) {
      map<int, ranges> m;

      for (auto& rect : rectangles) {
        m[rect[0]].add.emplace_back(rect[1], rect[3] - 1);
        m[rect[2]].rm.emplace_back(rect[1], rect[3] - 1);
      }

      Node* root = new Node(0, INT_MAX);

      constexpr long mod = 1e9 + 7;
      long res = 0;

      long h = 0;
      int x = 0;
      for (auto& iter : m) {
        res = (res + (iter.first - x) * h) % mod;

        // add and remove must share the same range set
        // does not work for arbitrary ranges
        for (auto& p : iter.second.add)
          addRange(root, p.first, p.second);

        for (auto& p : iter.second.rm)
          removeRange(root, p.first, p.second);

        x = iter.first;
        h = getLength(root);
      }

      utils3::destroy(root);

      return res;
    }
};


int main() {
  UFUNCS(Solution::rectangleArea);
  return 0;
}