#include "utils2.hpp"

class Solution {
  public:
    string simplifyPath(string path) {
      path = regex_replace(path, regex("/+"), "/");
      path = regex_replace(path, regex("^/|/$"), "");
      istringstream iss(path);
      string dir;
      vector<string> s;
      while (getline(iss, dir, '/')) {
        if (".." == dir) {
          if (!s.empty())
            s.pop_back();
        }
        else if ("." != dir)
          s.push_back(std::move(dir));
      }

      string res;
      for (int i=0; i<s.size(); ++i) {
        res.push_back('/');
        res.append(s[i]);
      }

      return res.size() ? res : "/";
    }
};


int main() {
  UFUNC(Solution::simplifyPath);
  return 0;
}