#include <vector>
#include <iostream>
using namespace std;

class Node {
  private:
    Node* left, * right;
  public:
    pair<int, int> val;
    int l, r;
    Node(int st, int ed): l(st), r(ed) {
      left = nullptr;
      right = nullptr;
      val = pair<int, int>(0, 1);
    }

    int getMid() {
      return l + (r-l) / 2;
    }

    Node* getLeft() {
      if (!left) left = new Node(l, getMid());
      return left;
    }

    Node* getRight() {
      if (!right) right = new Node(getMid()+1, r);
      return right;
    }

};

class Solution {
  private:
    pair<int, int> merge(pair<int, int> v1, pair<int, int> v2) {
      if (v1.first==v2.first) {
        if (v1.first==0) 
          return pair<int, int>(0, 1);
        else
          return pair<int, int>(v1.first, v1.second + v2.second);
      }
      else
        return v1.first > v2.first ? v1 : v2;
    }

    void insert(Node* node, int& key, pair<int, int>& val) {
      if (node->l == node->r) {
        node->val = merge(val, node->val);
        return;
      }
      else if (key > node->getMid())
        insert(node->getRight(), key, val);
      else
        insert(node->getLeft(), key, val);
      node->val = merge(node->getLeft()->val, node->getRight()->val);
    }

    pair<int, int> query(Node* node, int& key) {
      if (node->l >= key) return pair<int, int>(0, 1);
      else if (node->r < key) return node->val;
      return merge(query(node->getLeft(), key), query(node->getRight(), key));
    }
  public:
    int findNumberOfLIS(vector<int>& nums) {
      if (nums.size()==0) return 0;
      int _min=nums[0], _max=nums[0];
      for (int& num : nums) {
        _min = min(_min, num);
        _max = max(_max, num);
      }
      Node* root = new Node(_min, _max);
      for (int& num : nums) {
        pair<int, int> val = query(root, num);
        pair<int, int> p(val.first+1, val.second);
        insert(root, num, p);
      }
      return root->val.second;
    }
};

int main() {
  vector<int> nums = {2,2,2,2,2};
  Solution sol;
  cout << sol.findNumberOfLIS(nums) << endl;
  return 0;
}