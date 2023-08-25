#include <local_leetcode.hpp>

class Solution {
  private:
    static vector<vector<TreeNode*>> res;
    static bool helper;


    static bool init() {
      res[0].push_back(new TreeNode());

      for (int i = 1; i <= 9; ++i)
        for (int j = 0, k = i - 1; j < i; ++j, --k)
          for (int p = 0; p < res[j].size(); ++p)
            for (int q = 0; q < res[k].size(); ++q) {
              res[i].push_back(new TreeNode(0, res[j][p], res[k][q]));

              // if (j != k || p != q)
              //   res[i].push_back(new TreeNode(0, res[k][q], res[j][p]));
            }

      return false;
    }

  public:
    vector<TreeNode*> allPossibleFBT(int n) {
      if (n & 1)
        return res[n / 2];
      return {};
    }
};

vector<vector<TreeNode*>> Solution::res(10);
bool Solution::helper = Solution::init();


int main() {
  EXECS(Solution::allPossibleFBT);
  return 0;
}