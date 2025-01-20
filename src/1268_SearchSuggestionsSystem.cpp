#include <local_leetcode.hpp>

class Solution {
  private:
    static bool Compare(const string& x, const string& y) {
      int n = min(x.size(), y.size());
      for (int i = 0; i < n; ++i) {
        if (x[i] < y[i])
          return true;
        else if (x[i] > y[i])
          return false;
      }

      return x.size() < y.size();
    }

    struct Node {
      int len; // length of suggestions
      int indicies[3]; // index of suggestions

      Node* children[26];

      Node(): len(0), children{0} { };
    };

    void update(Node* root, const char* w, int idx) {
      // root is always valid, update best suggestions
      if (root->len < 3)
        root->indicies[root->len++] = idx;

      if (*w == '\0')
        return;

      int i = *w - 'a';

      if (root->children[i] == nullptr)
        root->children[i] = new Node();

      update(root->children[i], w + 1, idx);
    }

    void query(Node* root, int i, const string& word, const vector<string>& products, vector<vector<string>>& res) {
      if (i == word.size())
        return;

      root = root->children[word[i] - 'a'];

      if (root != nullptr) {
        for (int j = 0; j < root->len; ++j)
          res[i].push_back(products[root->indicies[j]]);

        query(root, i + 1, word, products, res);
      }
    }

  public:
    vector<vector<string>> suggestedProductsOld(vector<string>& products, string searchWord) {
      sort(products.begin(), products.end(), Compare);

      int n = searchWord.size();
      vector<vector<string>> res(n);
      for (int i = 0; i < n; ++i) {
        string prefix = searchWord.substr(0, i+1);

        auto bg = lower_bound(products.begin(), products.end(), prefix, Compare);
        for (int j = 0; j < 3; ++j, ++bg) {
          if (bg == products.end() || bg->size() <= i || bg->substr(0, i+1) != prefix) break;
          res[i].push_back(*bg);
        }
      }

      return res;
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
      sort(products.begin(), products.end());

      Node* root = new Node();

      for (int i = 0; i < products.size(); ++i)
        update(root, products[i].c_str(), i);

      vector<vector<string>> res(searchWord.size());

      // or implement by iterative approach
      query(root, 0, searchWord, products, res);

      ll::destroy(root);

      return res;
    }
};


int main() {
  EXECS(Solution::suggestedProductsOld);
  EXECS(Solution::suggestedProducts);
  return 0;
}