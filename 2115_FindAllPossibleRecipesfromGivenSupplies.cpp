#include <local_leetcode.hpp>

class Solution {
  private:
    struct Node {
      bool flag; // in recipes
      string name;
      vector<Node*> children;

      Node() = default;
      Node(string _name, bool _flag = false) noexcept : name(_name), flag(_flag) { }

      ~Node() { }
    };

  public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
      // use placement new to avoid memory leaking
      char* buffer = new char[(recipes.size() + supplies.size()) * sizeof(Node)];
      // Node* nodes = new Node[recipes.size() + supplies.size()];
      Node* nodes = reinterpret_cast<Node*>(buffer);

      unordered_map<string, Node*> m;

      queue<Node*> q;
      for (auto& s : supplies) {
        m[s] = new (nodes++) Node(s);
        q.push(m[s]);
      }

      for (auto& r : recipes)
        m[r] = new (nodes++) Node(r, true);

      int n = recipes.size();
      unordered_map<Node*, int> indegree;
      for (int i = 0; i < n; ++i) {
        Node* w = m[recipes[i]];
        indegree[w] = ingredients[i].size();

        for (auto& ing : ingredients[i]) {
          Node* v = m[ing];
          if (v)
            v->children.push_back(w);
        }
      }

      vector<string> res;
      while (!q.empty()) {
        Node* v = q.front();
        q.pop();

        if (v->flag)
          res.push_back(v->name);

        for (auto& w : v->children)
          if (--indegree[w] == 0) 
            q.push(w);
      }

      // delete[] (nodes - recipes.size() - supplies.size());

      // must call dtor since char buffer's array delete doesn't do this for the user
      nodes = reinterpret_cast<Node*>(buffer);
      for (int i = 0; i < (recipes.size() + supplies.size()); ++i)
        nodes++->~Node();
      
      delete[] buffer;

      return res;
    }

    vector<string> findAllRecipesGP(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
      int n = recipes.size();
      // string, index
      unordered_map<string, int> m;

      for (int i = 0; i < n; ++i)
        m[recipes[i]] = i;

      queue<int> q;

      for (int i = 0; i < supplies.size(); ++i) {
        m[supplies[i]] = i + n;
        q.push(i + n);
      }

      vector<int> indegree(n + supplies.size());
      vector<vector<int>> graph(n + supplies.size());

      for (int i = 0; i < n; ++i) {
        indegree[i] = ingredients[i].size();

        for (auto& ing : ingredients[i]) {
          auto iter = m.find(ing);
          if (iter != m.end()) 
            graph[iter->second].push_back(i);
        }
      }


      vector<string> res;
      while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v < n)
          res.push_back(recipes[v]);

        for (int w : graph[v])
          if (--indegree[w] == 0)
            q.push(w);
      }
      
      return res;
    }
};


int main() {
  EXECS(Solution::findAllRecipes);
  EXECS(Solution::findAllRecipesGP);
  return 0;
}