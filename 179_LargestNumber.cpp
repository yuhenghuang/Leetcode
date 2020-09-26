#include "utils.hpp"
#include <fstream>
#include <algorithm>

using namespace std;

struct Comparator {
  bool operator()(const string& lhs, const string& rhs) const {
    int m = lhs.size(), n = rhs.size();
    for (int i=0; i<m+n; ++i) {
      char l = i < m ? lhs[i] : rhs[i-m];
      char r = i < n ? rhs[i] : lhs[i-n];
      if (l>r)
        return true;
      else if (l<r)
        return false;
    }

    return false;
  }
};

class Solution {
  public:
    string largestNumber(vector<int>& nums) {
      int n=nums.size();
      vector<string> vec;
      vec.reserve(n);

      for (int i=0; i<n; ++i)
        vec.push_back(to_string(nums[i]));

      sort(vec.begin(), vec.end(), Comparator());

      string res;
      for (string &s : vec)
        res.append(s);

      size_t pos = res.find_first_not_of('0');

      return pos == string::npos ? "0" : (pos==0 ? res : res.substr(pos));
    }
};

int main() {
  Solution sol;

  ifstream f("Inputs/179_LargestNumber.txt");
  vector<int> nums;
  utils::parse_vector_1d<int> parser;
  string line;
  while (getline(f, line)) {
    nums = parser(line);
    cout << sol.largestNumber(nums) << endl;
  }

  return 0;
}