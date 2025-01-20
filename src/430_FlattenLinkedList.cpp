#define TERNARY_LIST_NODE
#include <local_leetcode.hpp>

class Solution {
  public:
    Node* flatten(Node* head) {
      if (head) 
        dfs(head);
      return head;
    }

    Node* dfs(Node* head) {
      if (!head->next && !head->child) 
        return head;

      Node* temp = head->next;
      if (head->child) {
        head->next = head->child;
        head->child = nullptr;
        head->next->prev = head;
        head = dfs(head->next);
        if (temp) {
          head->next = temp;
          temp->prev = head;
        }
      }
      return temp ? dfs(temp) : head;
    }
};


int main() {
  EXECS(Solution::flatten);
  return 0;
}