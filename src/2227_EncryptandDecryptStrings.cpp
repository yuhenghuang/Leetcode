#include <local_leetcode.hpp>

class Encrypter {
  private:
    struct Node {
      bool leaf;
      Node* children[26];

      Node(): leaf(false), children {0} { }

      Node*& getChild(int i) {
        if (children[i] == nullptr)
          children[i] = new Node();

        return children[i];
      }
    };

    // keys (0 - 25), values
    vector<string> encrypter;

    // values (to 26 * a + b), keys (0 - 25)
    vector<vector<int>> decrypter;

    Node* root; // trie root

    int twoChars2Int(const char* w) {
      return (*w - 'a') * 26 + (*(w+1) - 'a');
    }

    int decryptImpl(const char* w, Node* node) {
      if (!node)
        return 0;
      else if (*w == '\0')
        return node->leaf ? 1 : 0;

      int v = twoChars2Int(w);
      
      w += 2;

      int res = 0;
      for (const int& k : decrypter[v])
        res += decryptImpl(w, node->children[k]);

      return res;
    }

  public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary): 
      encrypter(26), decrypter(26 * 26)
    {
      // create key, value mapping (and reverse mapping)
      for (int i = 0; i < keys.size(); ++i) {
        encrypter[keys[i] - 'a'] = values[i];
        decrypter[twoChars2Int(values[i].c_str())].push_back(keys[i] - 'a');
      }

      // create trie of dictionary
      root = new Node();

      for (auto& word : dictionary) {
        Node* node = root;

        for (char c : word) 
          node = node->getChild(c - 'a');

        node->leaf = true;
      }
    }

    ~Encrypter() { ll::destroy(root); }
    
    string encrypt(string word1) {
      string res;

      res.reserve(word1.size() << 1);

      for (char c : word1)
        res += encrypter[c - 'a'];

      return res;
    }
    
    int decrypt(string word2) {
      return decryptImpl(word2.c_str(), root);
    }
};


int main() {
  EXECX(
    CTOR(vector<char>&, vector<string>&, vector<string>&),
    &Encrypter::encrypt,
    &Encrypter::decrypt
  );
  return 0;
}