#include "utils.hpp"
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int findPairs(vector<int>& nums, int k) {
      int n=nums.size();

      int res=0;
      if (k>0) {
        unordered_set<int> s;
        for (int& num : nums) {
          if (s.find(num)!=s.end()) continue;

          if (s.find(num+k)!=s.end()) 
            res++;

          if (s.find(num-k)!=s.end()) 
            res++;
          
          s.insert(num);
        }
      }
      else {
        unordered_map<int, int> m;
        for (int& num : nums) {
          ++m[num];
          if (m[num]==2)
            ++res;
        }
      }

      return res;
    }
};


int main() {
  Solution sol;

  vector<string> args;
  vector<int> nums;
  int k;
  utils::parse_vector_1d<int> parser;

  ifstream f("Inputs/532_KDiffPairs.txt");
  string line;
  while (getline(f ,line)) {
    args = utils::string_split(line);
    nums = parser(args[0]);
    k = stoi(args[1]);

    cout << sol.findPairs(nums, k) << endl;
  }

  return 0;
}
