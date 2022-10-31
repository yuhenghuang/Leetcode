#include <local_leetcode.hpp>

class Solution {
  private:
    struct encode{
      size_t count[26];

      encode(const string& s): count{0} {
        for (char c : s)
          ++count[c - 'a'];
      }

      bool operator==(const encode& lhs) const {
        for (int i = 0; i < 26; ++i)
          if (count[i] != lhs.count[i])
            return false;

        return true;
      }
    };

    struct hash_encode {
      size_t operator()(const encode& e) const {
        // don't use address as hash for non-heap memory.
        // return reinterpret_cast<uintptr_t>(&e);
        size_t h = 0;
        for (size_t c : e.count)
          h = c ^ (h << 2);

        return h;
      }
    };

  public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> res;

      int id = 0;
      // unordered_map<encode, int, hash_encode> s2i;

      unordered_map<
        encode, int, 
        function<size_t (encode)>
      > s2i (
        10, 
        [](const encode& e) {
          size_t h = 0;
          for (size_t c : e.count)
            h = c ^ (h << 2);
          return h;
        }
      );

      for (string& s : strs) {
        encode e(s);
        auto iter = s2i.find(e);
        if (iter == s2i.end()) {
          res.emplace_back().push_back(s);
          s2i[e] = id++;
        }
        else 
          res[iter->second].push_back(s);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::groupAnagrams);
  return 0;
}