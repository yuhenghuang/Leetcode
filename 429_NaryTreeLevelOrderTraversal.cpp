#include <vector>
#include <queue>
using namespace std;

#include "DataStructure.h"

class Solution {
  public:
    vector<vector<int>> levelOrder(Node* root) {
      queue<Node*> q;
      vector<vector<int>> res;
      if (root!=nullptr) q.push(root);
      int N;
      while (!q.empty()) {
        N = q.size();
        vector<int> temp;
        while (N-->0) {
          root = q.front();
          q.pop();
          temp.push_back(root->val);
          for (auto child : root->children)
            q.push(child);
        }
        res.push_back(temp);
      }
      return res;
    }
};