#include <sstream>
#include <local_leetcode.hpp>

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

    string simplifyPathO1(string path) {
      int n = path.size();

      vector<string_view> dirs;
      for (int i = 0; i < n; ++i)
        if (path[i] != '/') {
          int j = i + 1;
          for (; j < n && path[j] != '/'; ++j);

          string_view sv(path.c_str() + i, j - i);

          if (".." == sv) {
            if (!dirs.empty())
              dirs.pop_back();
          }
          else if ("." != sv)
            dirs.push_back(sv);

          i = j;
        }

      string res;
      for (int i = 0; i < (int) dirs.size(); ++i) {
        res.push_back('/');
        res.append(dirs[i]);
      }

      return res.empty() ? "/" : res;
    }
};


int main() {
  EXECS(Solution::simplifyPath);
  EXECS(Solution::simplifyPathO1);
  return 0;
}