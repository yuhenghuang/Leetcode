#include <local_leetcode.hpp>

class Skiplist {
  private:
    struct Node {
      int count;

      Node* next;
      Node* down;

      Node(): count(0), next(nullptr), down(nullptr) { }
    };

    int n;
    Node* head;

    void init_impl(Node* p, Node* q, int l, int r) {
      p->next = q;

      if (l + 1 < r) {
        p->down = new Node();
        p = p->down;

        if (q) {
          // q->down = new Node();
          q = q->down;
        }

        int m = l + (r - l) / 2;
        Node* o = new Node();

        init_impl(o, q, m, r);
        init_impl(p, o, l, m);
      }

    }

    
    Node* find_impl(Node* p, int l, int r, int t) {
      if (l == t) 
        return p;

      int m = l + (r - l) / 2;
      return t < m ? find_impl(p->down, l, m, t) : find_impl(p->down->next, m, r, t);
    }


    void init() { init_impl(head, nullptr, 0, n); }

    Node* find(int t) { return find_impl(head, 0, n, t); }

  public:
    Skiplist(): n(2e4 + 1), head(new Node()) {
      init();
    }
    
    bool search(int target) {
      return find(target)->count > 0;
    }
    
    void add(int num) {
      ++find(num)->count;
    }
    
    bool erase(int num) {
      Node* p = find(num);
      if (p->count > 0) {
        --p->count;
        return true;
      }

      return false;
    }

    ~Skiplist() {
      while (head) {
        Node* p = head->down;
        ll::destroy(head);
        head = p;
      }
    }
};


int main() {
  EXECX(
    CTOR(),
    &Skiplist::search,
    &Skiplist::add,
    &Skiplist::erase
  );

  return 0;
}