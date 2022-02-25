#include <local_leetcode.hpp>

class Solution {
  private:
    struct Node {
      bool leaf;
      unordered_map<string, Node*> children;

      Node(): leaf(false) { }
    };

    void dfs(Node* root, string&& s, vector<string>& res) {
      if (root->leaf) {
        res.push_back(std::move(s));
        return;
      }

      s.push_back('/');
      for (auto& [name, child] : root->children)
        dfs(child, s + name, res);
    }

  public:
    vector<string> removeSubfolders(vector<string>& folder) {
      static const regex re("/(\\w+)");
      static const sregex_iterator last;

      Node* root = new Node();
      for (auto& f : folder) {
        Node* node = root;
        sregex_iterator first(f.begin(), f.end(), re);
        for (; first != last; ++first) {
          string&& name = first->str(1);

          if (node->children.count(name) == 0)
            node = node->children[name] = new Node();
          else
            node = node->children[name];
        }

        node->leaf = true;
      }

      vector<string> res;
      dfs(root, "", res);

      ll::destroy(root);

      return res;
    }

    vector<string> removeSubfoldersSort(vector<string>& folder) {
      sort(folder.begin(), folder.end());

      vector<string> res;
      res.push_back(folder.front());

      string_view prev(folder.front());
      for (int i = 1; i < folder.size(); ++i) {
        string_view curr = folder[i];
        if (prev == curr || (curr.size() > prev.size() && curr.compare(0, prev.size(), prev) == 0 && curr[prev.size()] == '/')) {
        }
        else {
          res.emplace_back(curr);
          prev = curr;
        }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::removeSubfolders);
  EXECS(Solution::removeSubfoldersSort);
  return 0;
}

