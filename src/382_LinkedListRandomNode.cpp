#include <local_leetcode.hpp>

class Solution {
  private:
    ListNode* head;
  public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head): head(head) { }
    
    /** Returns a random node's value. */
    int getRandom() {
      ListNode* p = head;
      int v;
      int n = 1;
      while (p) {
        if (rand() % n++ == 0)
          v = p->val;
        p = p->next;
      }
      return v;
    }
};


int main(int argc, const char** argv) {
  /*
  if (argc>1) {
    int seed;
    sscanf(argv[1], "%d", &seed);
    cout << "Random seed is set to be " << seed << endl;
    srand(seed);
  }

  string line = "[1,2,3]";
  ListNode* head = utils::parse_linked_list(line);

  Solution sol(head);

  cout << '[';
  for (int i=0; i<15; ++i)
    cout << sol.getRandom() << ", ";
  cout << sol.getRandom() << ']' << endl;
  */

  EXECX(
    CTOR(ListNode*),
    &Solution::getRandom
  );

  return 0;
}