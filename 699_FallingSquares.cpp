#include <local_leetcode.hpp>

class Solution {
  private:
    // segment tree node
    struct Node;

    int query(Node* root, int s, int e);

    void update(Node* root, int s, int e, int h);

  public:
    vector<int> fallingSquaresWrong(vector<vector<int>>& positions);

    vector<int> fallingSquares(vector<vector<int>>& positions) {
      vector<int> res;
      res.reserve(positions.size());

      return res;
    }
};


struct Solution::Node {
  int l;
  int r;
  int height;

  Node* left;
  Node* right;

  Node(int _l, int _r, int _h = 0): 
    l(_l), r(_r), height(_h), left(nullptr), right(nullptr)
  { }

  int getMid() const { return l + (r-l) / 2; }

  Node* getLeft() {
    if (nullptr == left)
      left = new Node(l, getMid(), height);

    return left;
  }

  Node* getRight() {
    if (nullptr == right)
      right = new Node(getMid() + 1, r, height);

    return right;
  }
};

int 
Solution::query(Node* root, int s, int e) {
  // non-overlapped
  if (e < root->l || root->r < s)
    return 0;
  // root's range inside of [s, e]
  else if (s <= root->l && root->r <= e)
    return root->height;

  return max(
    root->height,
    max(query(root->getLeft(), s, e), query(root->getRight(), s, e))
  );
}

void 
Solution::update(Node* root, int s, int e, int h) {
  if (e < root->l || s > root->r)
    return;
  else if (s <= root->l && root->r <= e) {
    root->height = h;
    return;
  }

  update(root->getLeft(), s, e, h);
  update(root->getRight(), s, e, h);
}


vector<int> 
Solution::fallingSquaresWrong(vector<vector<int>>& positions) {
  // Wrond answer... don't know why

  vector<int> res;
  res.reserve(positions.size());

  Node* root = new Node(1, 1e9);

  int height = 0;
  for (auto& p : positions) {
    int h = query(root, p[0], p[0] + p[1] - 1) + p[1];

    update(root, p[0], p[0] + p[1] - 1, h);

    if (h > height)
      height = h;

    res.push_back(height);
  }

  ll::destroy(root);

  return res;
}


int main() {
  EXECS(Solution::fallingSquaresWrong);
  return 0;
}