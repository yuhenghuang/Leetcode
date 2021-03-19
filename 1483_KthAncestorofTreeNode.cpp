#include "DataStructure.h"
#include <vector>
#include <iostream>

using namespace std;

class TreeAncestor {
  private:
    vector<vector<int>> spmat;
  public:
    TreeAncestor(int n, vector<int>& parent) {
      // height of the sparse matrix
      int h = 1;
      while ((1 << h) < n)
        ++h;

      // please bear the 'C' order in mind
      // better to have long row than column
      spmat.assign(h, vector<int>(n, -1));
      
      spmat[0] = parent;

      for (int j=1; j<h; ++j)
        for (int i=0; i<n; ++i) {
          int prev = spmat[j-1][i];
          spmat[j][i] = prev < 0 ? prev : spmat[j-1][prev];
        }
    }

    
    int getKthAncestor(int node, int k) {
      if (node < 0)
        return -1;

      int i=0;
      while ((1 << i) < k)
        ++i;

      if ((1 << i)==k)
        return spmat[i][node];
      else
        return getKthAncestor(spmat[i-1][node], k - (1 << (i-1)));
    }
};

int main() {
  vector<int> vec = {-1,0,0,1,2,0,1,3,6,1};
  TreeAncestor obj(10, vec);
  cout << obj.getKthAncestor(1,1) << endl;
  return 0;
}