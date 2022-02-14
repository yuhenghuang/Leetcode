#include <local_leetcode.hpp>

class FileSystem {
  private:
    struct Node {
      string str; // director name or file content
      bool dir; // dir or file

      // files/subdirectories in lexicographic order
      map<string, Node*> children;

      Node(bool _d = true): dir(_d) { }
    };

    static const sregex_iterator end;

    Node* root;
    regex re;

    Node* query(Node* node, sregex_iterator iter) {
      if (iter == end)
        return node;

      node = node->children[iter++->str(1)];
      return query(node, iter);
    }

    Node* create(Node* node, sregex_iterator iter) {
      if (iter == end)
        return node;

      string name = iter++->str(1);
      map<string, Node*>& m = node->children;

      if (m.find(name) == m.end())
        m[name] = new Node();

      node = m[name];
      return create(node, iter);
    }

  public:
    FileSystem(): 
      root(new Node()), re("/(\\w+)")
    { }

    vector<string> ls(string path) {
      sregex_iterator iter(path.begin(), path.end(), re);
      Node* node = query(root, iter);

      vector<string> res;
      if (node->dir) {
        res.reserve(node->children.size());
        for (auto& p : node->children) 
          res.push_back(p.first);
      }
      else
        res.push_back(path.substr(path.find_last_of('/') + 1));

      return res;
    }

    // mkdir -p
    void mkdir(string path) {
      sregex_iterator iter(path.begin(), path.end(), re);
      create(root, iter);
    }

    void addContentToFile(string filePath, string content) {
      sregex_iterator iter(filePath.begin(), filePath.end(), re);
      Node* node = create(root, iter);
      node->dir = false;

      node->str.append(content);
    }

    string readContentFromFile(string filePath) {
      sregex_iterator iter(filePath.begin(), filePath.end(), re);
      Node* node = query(root, iter);

      return node->str;
    }

    ~FileSystem() { ll::destroy(root); }
};

const sregex_iterator FileSystem::end;


int main() {
  EXECX(
    CTOR(),
    &FileSystem::ls,
    &FileSystem::mkdir,
    &FileSystem::addContentToFile,
    &FileSystem::readContentFromFile
  );
  return 0;
}