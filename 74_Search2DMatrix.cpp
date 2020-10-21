#include "utils.hpp"

using namespace std;

class Solution {
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m = matrix.size(), n = m==0 ? 0 : matrix[0].size();

      int l=0, r=m*n;
      while (l<r) {
        int mid = l + (r-l) / 2;
        int i = mid % m, j = mid / m;
        if (matrix[i][j]>target)
          r = mid;
        else if (matrix[i][j]<target)
          l = mid+1;
        else
          return true;
        
      }

      return false;
    }
};


int main() {
  Solution sol;

  vector<vector<int>> matrix;
  int target;
  vector<string> args;

  utils::parse_vector_2d<int> parser;

  readlines("Inputs/74_Search2DMatrix.txt") {
    args = utils::string_split(line);

    matrix = parser(args[0]);
    target = stoi(args[1]);

    cout << boolalpha << sol.searchMatrix(matrix, target) << endl;
  }

  return 0;
}