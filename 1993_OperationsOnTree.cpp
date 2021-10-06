#include "utils3.hpp"

struct Node {
  int user;
  Node* parent;
  vector<Node*> children;

  Node(): user(0), parent(nullptr) {}
};


// wrong answer 
class LockingTreeOO {
  private:
    vector<Node*> nodes;

  public:
    LockingTreeOO(vector<int>& parent): nodes(parent.size()) {
      for (int i = 0; i < nodes.size(); ++i) 
        nodes[i] = new Node();

      for (int i = 1; i < parent.size(); ++i) {
        nodes[i]->parent = nodes[parent[i]];
        nodes[parent[i]]->children.push_back(nodes[i]);
      }
    }
    
    bool lock(int num, int user) {
      Node* node = nodes[num];

      if (node->user != 0)
        return false;

      node->user = user;
      return true;
    }
    
    bool unlock(int num, int user) {
      Node* node = nodes[num];

      if (node->user != user)
        return false;

      node->user = 0;
      return true;
    }
    
    bool upgrade(int num, int user) {
      Node* root = nodes[num];

      Node* p = root;
      while (p) {
        if (p->user > 0)
          return false;

        p = p->parent;
      }

      vector<Node*> locked;

      queue<Node*> q;
      q.push(root);

      while (!q.empty()) {
        Node* v = q.front();
        q.pop();

        if (v->user > 0)
          locked.push_back(v);

        for (Node* e : v->children) 
          q.push(e);
      }

      if (locked.empty())
        return false;

      for (Node* node : locked)
        node->user = 0;

      root->user = user;
      return true;
    }

    ~LockingTreeOO() { utils3::destroy(nodes.front()); };
};


class LockingTree {
  private:
    vector<vector<int>> edges;
    vector<int> locks;

  public:
    LockingTree(vector<int>& parent): edges(parent.size()), locks(parent.size()) {
      for (int i = 0; i < parent.size(); ++i)
        edges[i].push_back(parent[i]);

      for (int i = 1; i < parent.size(); ++i)
        edges[parent[i]].push_back(i);
    }
    
    bool lock(int num, int user) {
      if (locks[num] != 0)
        return false;

      locks[num] = user;
      return true;
    }
    
    bool unlock(int num, int user) {
      if (locks[num] != user)
        return false;

      locks[num] = 0;
      return true;
    }
    
    bool upgrade(int num, int user) {
      int p = num;
      while (p >= 0) {
        if (locks[p] > 0)
          return false;

        p = edges[p][0];
      }

      int count = 0;
      vector<int> locked;

      queue<int> q;
      q.push(num);

      while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (locks[v] > 0){
          locked.push_back(v);
          ++count;
        }

        for (int i = 1; i < edges[v].size(); ++i) 
          q.push(edges[v][i]);
      }

      if (count == 0)
        return false;

      for (int node : locked)
        locks[node] = 0;

      locks[num] = user;
      return true;
    }
};


int main() {
  UFUNCX(
    CTOR(vector<int>&),
    &LockingTreeOO::lock,
    &LockingTreeOO::unlock,
    &LockingTreeOO::upgrade
  );

  UFUNCX(
    CTOR(vector<int>&),
    &LockingTree::lock,
    &LockingTree::unlock,
    &LockingTree::upgrade
  );
  return 0;
}