#include <vector>
#include <cmath>
#include <iostream>
#include <iterator>
using namespace std;

class Solution {
  public:
    vector<int> distributeCandies(int candies, int num_people) {
      int k;
      if (num_people*(num_people+1)/2>candies) {
        k = -1;
      }
      else {
        double y = static_cast<double>(candies), n = static_cast<double>(num_people);
        double b = 2+ 1/n, c = 1 + 1/n - y / (0.5 * n * n);
        k = static_cast<int>((sqrt(b*b-4*c)-b)/2);
      }
      vector<int> res(num_people, num_people * k*(k+1)/2);
      int rem = candies - num_people*num_people * k*(k+1)/2 - num_people*(num_people+1)/2 * (k+1);
      for (int i=0; i<num_people; ++i) {
        res[i] += (i+1) * (k+1);
      }
      int temp;
      for (int i=0; i<num_people; ++i) {
        if (rem<0)
          break;
        temp = num_people*(k+1) + i+1;
        res[i] += min(rem, temp);
        rem -= temp;
      }
      return res;
    }
};

int main() {
  Solution sol;
  vector<int> res= sol.distributeCandies(10, 3);
  copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
  return 0;
}