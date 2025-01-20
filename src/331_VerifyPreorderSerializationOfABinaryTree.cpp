#include "utils3.hpp"

class Solution {
  public:
    bool isValidSerialization(string preorder) {
      // true -> left leaf activated
      // as if root is the right leaf of a parent node
      stack<bool> s;
      s.push(true);

      istringstream iss(preorder);
      string val;
      while (getline(iss, val, ',')) {
        if (s.empty())
          return false;

        if (s.top())
          s.pop();
        else
          s.top() = true;

        if (val != "#")
          s.push(false);
      }

      return s.empty();
    }
};


int main() {
  UFUNCS(Solution::isValidSerialization);
  return 0;
}