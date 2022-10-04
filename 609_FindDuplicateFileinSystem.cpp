#include <local_leetcode.hpp>


// string + string_view
string operator+(const string& s, const string_view& v) {
  string out(s);
  return out += v;
}


class Solution {
  public:
    vector<vector<string>> findDuplicateRegex(vector<string>& paths) {
      int uid = 0;
      vector<vector<string>> temp;
      unordered_map<string_view, int> content2idx;

      regex re("\\s([^\\(]*)\\(([^\\)]*)\\)");
      sregex_iterator end;
      for (const string& p : paths) {
        size_t i = p.find_first_of(' ', 0);
        if (i == string::npos)
          continue;

        string_view dir(p.data(), i);

        sregex_iterator iter(p.begin() + i, p.end(), re);

        for (; iter != end; ++iter) {
          string_view file(p.data() + (i + iter->prefix().length() + iter->position(1)), iter->length(1));
          string_view content(p.data() + (i + iter->prefix().length() + iter->position(2)), iter->length(2));

          string s;
          s.reserve(dir.size() + file.size() + 1UL);

          s += dir;
          s.push_back('/');
          s += file;

          auto it = content2idx.find(content);
          if (it == content2idx.end()) {
            content2idx[content] = uid++;
            temp.emplace_back().push_back(std::move(s));
          }
          else
            temp[it->second].push_back(std::move(s));
        }
      }

      vector<vector<string>> res;
      for (auto& g : temp)
        if (g.size() > 1)
          res.push_back(std::move(g));

      return res;
    }

    vector<vector<string>> findDuplicate(vector<string>& paths) {
      int uid = 0;
      vector<vector<string>> temp;
      unordered_map<string_view, int> str2idx;
      for (const string& p : paths) {
        size_t i = p.find_first_of(' ', 0);
        if (i == string::npos)
          continue;

        string dir = p.substr(0, i) + '/';
        while (i < p.size()) {
          size_t j = p.find_first_of('(', i);
          size_t k = p.find_first_of(')', i);
          string_view file_name(p.data()+ (i + 1), j - i - 1);
          string_view content(p.data() + (j + 1), k - j - 1);

          if (str2idx.count(content) == 0) {
            str2idx[content] = uid++;
            temp.emplace_back();
          }

          temp[str2idx[content]].push_back(dir + file_name);

          i = k+1;
        }
      }

      vector<vector<string>> res;
      for (auto& g : temp)
        if (g.size() > 1)
          res.push_back(std::move(g));

      return res;
    }
};


int main() {
  // auto parser fails because of space in string
  // wrong input caused null return
  EXECS(Solution::findDuplicate);
  EXECS(Solution::findDuplicateRegex);
  return 0;
}
