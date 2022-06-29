#include <local_leetcode.hpp>

class TextEditor {
  private:
    struct Node {
      char c;
      Node* prev;
      Node* next;

      Node(char _c = '#'): c(_c), prev(nullptr), next(nullptr) { }

      void addNext(char _c) {
        Node* node = new Node(_c);

        if (next) {
          node->next = next;
          next->prev = node;
        }

        node->prev = this;
        next = node;
      }

      void removeNext() {
        // next is always valid
        Node* node = next;

        if (node->next)
          node->next->prev = this;

        next = node->next;

        delete node;
      }
    };

    class Cursor {
      private:
        Node* node;

      public:
        Cursor(Node* _node): node(_node) { }

        Cursor& operator++() {
          node = node->next;
          return *this;
        }

        Cursor& operator--() {
          node = node->prev;
          return *this;
        }

        bool operator==(const Cursor& rhs) const {
          return node == rhs.node;
        }

        bool operator!=(const Cursor& rhs) const {
          return !(*this == rhs);
        }

        Node*& operator->() {
          return node;
        }

        Node* get() const { return node; }
    };

    Cursor head;
    Cursor cursor;

  public:
    TextEditor(): head(new Node()), cursor(head) { }
    
    void addText(string text) {
      for (char c : text) {
        cursor->addNext(c);
        ++cursor;
      }
    }
    
    int deleteText(int k) {
      int i = 0;
      for (; i < k && cursor != head; ++i) {
        --cursor;
        cursor->removeNext();
      }

      return i;
    }
    
    string cursorLeft(int k) {
      for (; k > 0 && cursor != head; --k, (void) --cursor);

      string out;
      Cursor iter = cursor;
      for (int i = 0; i < 10 && iter!= head; ++i, (void) --iter)
        out.push_back(iter->c);

      reverse(out.begin(), out.end());
      return out;
    }
    
    string cursorRight(int k) {
      string out;

      // cursor has next
      for (; k > 0 && cursor->next; --k, (void) ++cursor);

      Cursor iter = cursor;
      for (int i = 0; i < 10 && iter!= head; ++i, (void) --iter)
        out.push_back(iter->c);

      reverse(out.begin(), out.end());

      return out;
    }

    ~TextEditor() { ll::destroy(head.get()); }
};


class TextEditorVector {
  private:
    vector<char> front;
    stack<char> rear;

  public:
    TextEditorVector() {
      // avoid nullptr offset error
      // occurs if cursor movement is called before memory in front is allocated
      front.reserve(4);
    }
    
    void addText(string text) {
      for (char c : text)
        front.push_back(c);
    }
    
    int deleteText(int k) {
      int i = 0;
      for (; i < k && !front.empty(); ++i)
        front.pop_back();

      return i;
    }
    
    string cursorLeft(int k) {
      for (; k > 0 && !front.empty(); --k) {
        rear.push(front.back());
        front.pop_back();
      }

      return string(max(front.begin(), front.end() - 10), front.end());
    }
    
    string cursorRight(int k) {
      for (; k > 0 && !rear.empty(); --k) {
        front.push_back(rear.top());
        rear.pop();
      }

      return string(max(front.begin(), front.end() - 10), front.end());
    }
};


int main() {
  EXECX(
    CTOR(),
    &TextEditor::addText,
    &TextEditor::deleteText,
    &TextEditor::cursorLeft,
    &TextEditor::cursorRight
  );
  
  EXECX(
    CTOR(),
    &TextEditorVector::addText,
    &TextEditorVector::deleteText,
    &TextEditorVector::cursorLeft,
    &TextEditorVector::cursorRight
  );
  return 0;
}