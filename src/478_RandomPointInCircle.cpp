#include <vector>
#include <random>
#include <cmath>

using namespace std;

class Solution {
  private:
    double xC, yC, r;
  
    uniform_real_distribution<double> unif;
    default_random_engine re;
  
  public:
    Solution(double radius, double x_center, double y_center)
      : r(radius), xC(x_center), yC(y_center) { }
    
    vector<double> randPoint() {
      double theta = unif(re) * 2 * M_PI;
      double dist = sqrt(unif(re));
      double x = cos(theta) * dist, y = sin(theta) * dist;
      return {xC + r*x, yC + r*y};
    }
};