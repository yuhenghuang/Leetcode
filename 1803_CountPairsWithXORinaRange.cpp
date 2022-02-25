#include <local_leetcode.hpp>

class Trie {
  private:
    struct Node {
      int16_t count;
      Node* left;
      Node* right;

      Node(): count(0), left(nullptr), right(nullptr) { }

      // lazy evaluation
      Node*& getLeft() {
        if (!left)
          left = new Node();

        return left;
      }

      Node*& getRight() {
        if (!right)
          right = new Node();

        return right;
      }
    };

    Node* root;
    const int low;
    const int high;

    void addImpl(Node* node, int val, int level) {
      ++node->count;

      if (level == -1)
        return;

      addImpl(
        ((val >> level) & 1) ? node->getLeft() : node->getRight(),
        val,
        level - 1
      );
    }

    int queryImpl(Node* node, int val, int level, bool lb, bool ub) {
      int mask = 1 << level--;

      // left bounded afterwards
      lb |= (val & mask) > (low & mask);
      // right bounded afterwards
      ub |= (val & mask) < (high & mask);

      // early stop if bounded
      if (lb and ub)
        return node->count;
      else if ((lb or (val & mask) >= (low & mask)) and (ub or (val & mask) <= (high & mask))) {
        if (level == -1)
          return node->count;
        else
          return 
            (node->left ? queryImpl(node->left, val ^ (1 << level), level, lb, ub) : 0) +
            (node->right ? queryImpl(node->right, val, level, lb, ub) : 0);
      }
      else
        return 0;
    }

  public:
    Trie(int _low, int _high):
      root(new Node()), low(_low), high(_high)
    { }

    void add(int val) { addImpl(root, val, 15); }

    int query(int val) { return queryImpl(root, val, 16, false, false); }

    ~Trie() { ll::destroy(root); }
};

class Solution {
  public:
    int countPairs(vector<int>& nums, int low, int high) {
      Trie trie(low, high);

      int res = 0;
      for (const int& num : nums) {
        res += trie.query(num);
        trie.add(num);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::countPairs);
  return 0;
}