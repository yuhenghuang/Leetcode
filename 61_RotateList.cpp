// #include "utils.hpp"
// using namespace std;

#include <local_leetcode.hpp>

class Solution {
  public:
    ListNode* rotateRight(ListNode* head, int k) {
      if (!head || !head->next) return head;

      ListNode* p = head;
      int n = 1;
      while (p->next) {
        ++n;
        p = p->next;
      }

      if (k % n==0) return head;

      k = n - k % n;

      p->next = head;

      while (k--)
        p = p->next;

      head = p->next;
      p->next = nullptr;
      return head;
    }
};


int main() {
  /*
  Solution sol;

  vector<string> args;
  ListNode* head;
  int k;
  
  ifstream f("Inputs/61_RotateList.txt");
  string line;
  while (getline(f, line)) {
    args = utils::string_split(line);
    head = utils::parse_linked_list(args[0]);
    k = stoi(args[1]);

    utils::print_linked_list(sol.rotateRight(head, k));
  }
  */

  EXECS(Solution::rotateRight);
  return 0;
}
