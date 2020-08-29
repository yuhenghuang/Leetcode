#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
      vector<string> res(n, "");

      for (int i=1; i<=n; ++i) 
        if (i%3 !=0 && i%5!=0)
          res[i-1].append(to_string(i));

      for (int i=2; i<n; i+=3)
        res[i].append("Fizz");

      for (int i=4; i<n; i+=5)
        res[i].append("Buzz");
      
      return res;
    }
};