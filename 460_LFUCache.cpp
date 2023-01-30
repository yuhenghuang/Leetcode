#include <local_leetcode.hpp>
#include <forward_list>

class LFUCache {
  private:
    struct Node {
      int key, val, freq;
      Node* prev;
      Node* next;

      Node(): prev(nullptr), next(nullptr) { }
      Node(int _key, int _val, int _freq = 1): key(_key), val(_val), freq(_freq) { }
    };

    int cap;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> dict_key, dict_freq;

    void insert_after(Node* before, Node* node) {
      node->prev = before;
      node->next = before->next;

      before->next = node;
      node->next->prev = node;
    }

    void remove_from_list(Node* node) {
      // detach node from linked list
      node->prev->next = node->next;
      node->next->prev = node->prev;
    }

    void remove_from_freq(Node* node) {
      bool last = node->freq < node->next->freq;
      bool first = node->freq > node->prev->freq;

      if (last && first) 
        dict_freq.erase(node->freq);
      else if (last)
        dict_freq[node->freq] = node->prev;
    }

    // frequency + 1
    void update(Node* node) {
      Node* freq_tail = dict_freq.count(node->freq + 1) ? dict_freq[node->freq + 1] : dict_freq[node->freq];

      remove_from_freq(node);
      
      if (freq_tail != node) {
        remove_from_list(node);
        insert_after(freq_tail, node);
      }

      dict_freq[++node->freq] = node;
    }

  public:
    LFUCache(int capacity): cap(capacity) {
      head = new Node();
      tail = new Node();
      tail->prev = head;
      head->next = tail;
      head->freq = 0;
      tail->freq = INT_MAX;
    }
    
    int get(int key) {
      auto iter = dict_key.find(key);
      if (iter == dict_key.end())
        return -1;
      
      update(iter->second);
      return iter->second->val;
    }
    
    void put(int key, int value) {
      auto iter = dict_key.find(key);
      // already exists
      if (iter != dict_key.end()) {
        iter->second->val = value;
        update(iter->second);
      }
      else if (cap > 0) {
        Node* node;
        if (dict_key.size() == cap) {
          node = head->next;

          dict_key.erase(node->key);
          remove_from_freq(node);
          remove_from_list(node);
          delete node;
        }

        node = new Node(key, value);
        insert_after(dict_freq.count(1) ? dict_freq[1] : head, node);

        dict_key[key] = dict_freq[1] = node;
      }
    }

    ~LFUCache() { ll::destroy(head); }
};


int main() {
  EXECX(
    CTOR(int),
    &LFUCache::get,
    &LFUCache::put
  );
  return 0;
}