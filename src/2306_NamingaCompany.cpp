#include <local_leetcode.hpp>

class Solution {
  private:
    struct Node {
      bool leaf;
      int count;
      Node* children[26];

      Node(): leaf(false), count(0), children{nullptr} { }
    };


    void update(Node* root, const char* w) {
      ++root->count;

      if (*w == '\0') {
        root->leaf = true;
        return;
      }

      int i = *(w++) - 'a';

      if (root->children[i] == nullptr)
        root->children[i] = new Node();

      update(root->children[i], w);
    }

    bool find(Node* root, const char* w) {
      if (!root)
        return false;
      
      int i = *(w++) - 'a';

      // end of string
      if (i < 0)
        return root->leaf;
      
      return find(root->children[i], w);
    }

    int query(Node* root, const char* w) {
      if (!root)
        return 0;

      int i = *(w++) - 'a';

      int res = 0;

      for (int j = 0; j < 26; ++j)
        if (i != j)
          res += root->children[j] ? root->children[j]->count : 0;
        else
          res += query(root->children[j], w);

      return res;
    }

    int query(Node* root1, Node* root2) {
      if (!root1 || !root2)
        return 0;

      int res = root1->leaf && root2->leaf;
      for (int i = 0; i < 26; ++i)
        res += query(root1->children[i], root2->children[i]);

      return res;
    }

    uint64_t pairs(const unordered_set<uint64_t>& s1, const unordered_set<uint64_t>& s2) {
      if (s1.size() > s2.size())
        return pairs(s2, s1);

      uint64_t k = 0;
      for (auto& val : s1)
        if (s2.count(val))
          ++k;

      return ((s1.size() - k) * (s2.size() - k)) << 1;
    }

  public:
    long long distinctNames(vector<string>& ideas) {
      /*
        ~~wrong answer!! T_T~~
        SLOW answer!!

        idea1: a + c
        idea2: b + d

        (a + b), (a + c) -> (a + c), (b + c) dame
        (a + c), (b + c) -> (a + c), (b + c) dame

        --> condition is
        a != b and c != d

        and ...
      */

      Node* roots[26];
      for (int i = 0; i < 26; ++i)
        roots[i] = new Node();

      int count[26] = {0};
      for (auto& idea : ideas) {
        const char* w = idea.c_str();

        int i = *(w++) - 'a';
        ++count[i];
        update(roots[i], w);
      }

      int64_t res = 0;
      /*
      for (auto& idea : ideas) {
        const char* w = idea.c_str();

        int i = *(w++) - 'a';
        for (int j = 0; j < 26; ++j)
          // diffrent initials
          if (i != j && !find(roots[j], w))
            res += query(roots[j], w) + roots[j]->leaf;
      }
      */

      for (int i = 0; i < 26; ++i)
        for (int j = 0; j < i; ++j) {
          int64_t k = query(roots[i], roots[j]);
          // res -= k * (count[i] + count[j] - 2 * k);
          res += (count[i] - k) * (count[j] - k) * 2;
        }

      // for (auto& root : roots) ll::destroy(root);
      ll::universal_destroyer<Node*[]>()(roots);

      return res;
    }

    long long distinctNamesHash(vector<string>& ideas) {
      unordered_set<uint64_t> vals[26];

      for (auto& idea : ideas) {
        auto iter = idea.begin();
        int i = *iter - 'a';

        uint64_t val = 0;

        // leave 0 for empty substring
        // shift 5 bits every time to cover 26 letters (and 1 empty char)
        for (++iter; iter != idea.end(); ++iter)
          val = (val << 5) | (*iter - 'a' + 1);

        vals[i].insert(val);
      }

      uint64_t res = 0;

      for (int i = 0; i < 26; ++i)
        for (int j = 0; j < i; ++j)
          res += pairs(vals[i], vals[j]);

      return res;
    }
};


int main() {
  EXECS(Solution::distinctNames);
  EXECS(Solution::distinctNamesHash);
  return 0;
}