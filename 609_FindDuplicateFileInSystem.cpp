#include "utils2.hpp"

class Solution {
  public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
      int uid = 0;
      vector<vector<string>> temp;
      unordered_map<string, int> str2idx;
      for (const string& p : paths) {
        size_t i = p.find_first_of(' ', 0);
        if (i == string::npos)
          continue;

        string dir = p.substr(0, i);
        while (i < p.size()) {
          size_t j = p.find_first_of('(', i);
          size_t k = p.find_first_of(')', i);
          string file_name = p.substr(i + 1, j - i - 1);
          string content = p.substr(j + 1, k - j - 1);

          if (str2idx.count(content) == 0) {
            str2idx[content] = uid++;
            temp.emplace_back();
          }

          temp[str2idx[content]].emplace_back(dir + '/' + file_name);

          i = k+1;
        }
      }

      vector<vector<string>> res;
      for (auto& g : temp)
        if (g.size() > 1)
          res.emplace_back(std::move(g));

      return res;
    }
};


int main() {
  // auto parser fails because of space in string
  // wrong input caused null return
  UFUNC(Solution::findDuplicate);
  return 0;
}