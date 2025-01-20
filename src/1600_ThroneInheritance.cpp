#include "utils3.hpp"

class ThroneInheritance {
  private:
    struct Node {
      bool alive;
      string name;
      vector<Node*> children;

      Node(const string& s): name(s), alive(true) { }
    };

    Node* root;
    unordered_map<string, Node*> dict;

    void inorder_traverse(Node* node, vector<string>& s) {
      if (node->alive)
        s.push_back(node->name);

      // tip: use reference even for pointer for better performance
      for (auto& child : node->children)
        inorder_traverse(child, s);
    }

  public:
    ThroneInheritance(string kingName) {
      root = new Node(kingName);
      dict[kingName] = root;
    }
    
    void birth(string parentName, string childName) {
      Node* node = new Node(childName);

      dict[parentName]->children.push_back(node);
      dict[childName] = node;
    }
    
    void death(string name) {
      dict[name]->alive = false;
    }
    
    vector<string> getInheritanceOrder() {
      vector<string> res;
      inorder_traverse(root, res);

      return res;
    }

    ~ThroneInheritance() { utils3::destroy(root); }
};


int main() {
  UFUNCX(
    CTOR(string),
    &ThroneInheritance::birth,
    &ThroneInheritance::death,
    &ThroneInheritance::getInheritanceOrder
  );
  return 0;
}