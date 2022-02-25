#include <local_leetcode.hpp>

class Solution {
  private:
    class SubString {
      private:
        string_view str; // string view of the substring
        size_t hash_val; // pre-computed hash value

      public:
        SubString(const char* _c_str, size_t _n, size_t _hash_val):
          str(_c_str, _n), hash_val(_hash_val)
        { }

        struct SubStringHash {
          size_t operator()(const SubString& _sub_str) const {
            return _sub_str.hash_val;
          }
        };

        bool operator==(const SubString& rhs) const {
          // the second equality increases time complexity but avoids hash collision
          return hash_val == rhs.hash_val && str == rhs.str;
        }
    };

    struct Node {
      Node* children[26];

      Node(): children{0} { }

      Node*& at(char c) {
        return nullptr == children[c - 'a'] ? (children[c - 'a'] = new Node()) : children[c - 'a'];
      }
    };

  public:
    int distinctEchoSubstrings(string text) {
      constexpr size_t mod = 1e9 + 7;
      constexpr size_t k = 29;

      int n = text.size();
      size_t multiply = 1;

      int res = 0;
      for (int len = 1; len <= n / 2; ++len) {
        queue<SubString> q;
        unordered_set<SubString, SubString::SubStringHash> s; // set

        int i = 0; // index of text

        size_t hash_val = 0;

        // first substring
        for (; i < len; ++i) 
          hash_val = (hash_val * k + (text[i] - 'a' + 1)) % mod;

        q.emplace(text.c_str(), len, hash_val);

        for (; i + 1 < len * 2; ++i) {
          hash_val = ((hash_val - ((text[i - len] - 'a' + 1) * multiply) % mod + mod) * k + (text[i] - 'a' + 1)) % mod;
          q.emplace(text.c_str() + i - len + 1, len, hash_val);
        }

        for (; i < n; ++i) {
          hash_val = ((hash_val - ((text[i - len] - 'a' + 1) * multiply) % mod + mod) * k + (text[i] - 'a' + 1)) % mod;

          SubString substr(text.c_str() + i - len + 1, len, hash_val);

          if (q.front() == substr)
            s.insert(substr);

          q.pop();

          if (i + len < n)
            q.emplace(substr);
        }

        res += s.size();
        multiply = (multiply * k) % mod;
      }

      return res;
    }

    int distinctEchoSubstringsTrie(string text) {
      int n = text.size();

      vector<vector<uintptr_t>> addr(n, vector<uintptr_t>(n/2 + 1));

      Node* root = new Node();
      for (int i = 0; i < n; ++i) {
        Node* node = root;

        /*
        max(
          min(
            previous longest substring, 
            remaining possible longest substring
          ), 
          half of remaining substring
        )
        */
        int maxlen = max(min(i, n - i), (n - i) / 2);
        for (int len = 1; len <= maxlen; ++len) {
          node = node->at(text[i + len - 1]);
          addr[i][len] = reinterpret_cast<uintptr_t>(node);
        }
      }

      unordered_set<uintptr_t> s;
      for (int i = 0; i < n; ++i)
        for (int len = 1; len <= (n - i) / 2; ++len)
          if (addr[i][len] == addr[i+len][len])
            s.insert(addr[i][len]);

      ll::destroy(root);

      return s.size();
    }
};


int main() {
  EXECS(Solution::distinctEchoSubstrings);
  EXECS(Solution::distinctEchoSubstringsTrie);
  return 0;
}