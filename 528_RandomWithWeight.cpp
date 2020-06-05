#include <vector>
#include <random>
using namespace std;

class Solution {
private:
  int N;
  vector<int> acc;
  uniform_int_distribution<int> dist;
  default_random_engine gen;
public:
  Solution(vector<int>& w) {
    N = w.size();
    acc = vector<int>(N+1, 0);
    for (int i=0; i<N; ++i)
      acc[i+1] = acc[i] + w[i];
    dist = uniform_int_distribution<int>(1, acc[N]);
  }
    
  int pickIndex() {
    int target = dist(gen);
    int l=1, r=N;
    while (l<r) {
      int m = l + (r-l)/2;
      if (acc[m]<target)
        l = m+1;
      else
        r = m;
    }
    return l-1;
  }
};