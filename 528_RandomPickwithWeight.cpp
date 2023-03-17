#include <local_leetcode.hpp>
#include <random>

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


// alias algorithm for weighted sampling
class SolutionAlias {
  private:
    int n;
    vector<double> probs;
    vector<int> alias;

    uniform_real_distribution<double> dist;

    // use gen(rd()) to generate different results each time
    random_device rd;
    mt19937 gen;

  public:
    SolutionAlias(vector<int>& w): n(w.size()), probs(n), alias(n), dist(0, 1), gen(rd()) {
      double weights = reduce(w.begin(), w.end(), 0);

      vector<int> overfull, underfull;
      for (int i = 0; i < n; ++i) {
        double prob = (w[i] * n) / weights;

        probs[i] = prob;

        if (prob > 1.0)
          overfull.push_back(i);
        else if (prob < 1.0)
          underfull.push_back(i);
      }

      for (int u = 0, v = 0; v < (int) underfull.size(); ++u, ++v) {
        int i = overfull[u];
        int j = underfull[v];

        double prob = probs[i] += probs[j] - 1.0;
        alias[j] = i;

        // cannot use operator== because of precision
        if (fabs(prob - 1.0) < 1e-9)
          probs[i] = 1.0;
        else if (prob > 1.0)
          --u;
        else
          underfull[v--] = i;
      }
    }

    int pickIndex() {
      double x = dist(gen) * n;
      int i = x;
      return (x - i < probs[i]) ? i : alias[i];
    }
};


int main() {
  EXECX(
    CTOR(vector<int>&),
    &Solution::pickIndex
  );

  EXECX(
    CTOR(vector<int>&),
    &SolutionAlias::pickIndex
  );
}
