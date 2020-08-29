

int rand7();

class Solution {
public:
    int rand10() {
      int num;
      do {
        num = rand7() + (rand7()-1) * 7;
      } while (num>40);
      return (num-1) % 10 + 1;
    }
};