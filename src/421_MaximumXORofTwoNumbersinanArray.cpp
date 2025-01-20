#include <local_leetcode.hpp>

struct Node {
  Node* left;
  Node* right;
  Node(): left(nullptr), right(nullptr) { }
}
;

class Solution {
  private:
    void addNode(Node* root, const int &num, int&& layer) {
      if (layer<0) return;

      if ((num >> layer) & 1) {
        if (!root->right)
          root->right = new Node();
        addNode(root->right, num, layer-1);
      }
      else {
        if (!root->left)
          root->left = new Node();
        addNode(root->left, num, layer-1);
      }
    }

    void findMax(Node* root, const int &num, int&& layer, int &res) {
      if (!root->left && !root->right) 
        return;
      else if (!root->left) {
        res += (((num >> layer) & 1) ^ 1) << layer;
        findMax(root->right, num, layer-1, res);
      }
      else if (!root->right) {
        res += (((num >> layer) & 1) ^ 0) << layer;
        findMax(root->left, num, layer-1, res);
      }
      else {
        res += (1 << layer);
        if ((num >> layer) & 1)
          findMax(root->left, num, layer-1, res);
        else
          findMax(root->right, num, layer-1, res);
      }
    }
  public:
    int findMaximumXOR(vector<int>& nums) {
      int res=0;

      Node* root = new Node();
      int temp;
      for (const int& num : nums) {
        temp = 0;
        findMax(root, num, 31, temp);
        res = max(res, temp);
        addNode(root, num, 31);
      }

      ll::destroy(root);
      return res;
    }
};



int main() {
  /*
  Solution sol;
  vector<int> nums;

  ifstream f("Inputs/412_MaximumXOR.txt");
  string line;
  while (getline(f, line)) {
    line = regex_replace(line, regex("[\\[\\]\\s]+"), "");

    string num;
    istringstream ss(line);
    nums.clear();
    while (getline(ss, num, ',')) 
      nums.push_back(stoi(num));

    cout << sol.findMaximumXOR(nums) << endl;
  }
  */

  EXECS(Solution::findMaximumXOR);

  return 0;
}
