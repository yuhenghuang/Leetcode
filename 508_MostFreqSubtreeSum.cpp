#include "DataStructure.h"
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
  private:
    unordered_map<int, int> dict;
  public:
    bool comp(int& i, int& j) const {
      return dict.find(i)->second > dict.find(j)->second;
    }
    bool operator() (const int& i, const int& j) const {
      return dict.find(i)->second > dict.find(j)->second;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
      dfs(root);
      vector<int> sums;
      for (auto iter=dict.begin(); iter!=dict.end(); ++iter)
        sums.push_back(iter->first);
      sort(sums.begin(), sums.end(), *this);
      vector<int> res;
      int i=0;
      while (i<sums.size() && sums[i]==sums[0])
        res.push_back(sums[i]);
      return res;
    }
    int dfs(TreeNode* node) {
      if (!node) return 0;
      int res = node->val + dfs(node->left) + dfs(node->right);
      dict[res]++;
      return res;
    }
};