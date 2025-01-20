#include <unordered_set>
using namespace std;

class Solution {
  public:
    int numJewelsInStones(string J, string S) {
      unordered_set<char> set;
      for (char c : J)
        set.insert(c);

      int res=0;
      for (char c : S) {
        auto iter = set.find(c);
        if (iter!=set.end())
          res++;
      }
      return res;
    }
};