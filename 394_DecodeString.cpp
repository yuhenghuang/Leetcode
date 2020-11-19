#include "utils.hpp"

class Solution {
  public:
    string decodeString(string s) {
      string num;
      string temp;
      stack<int> nums;
      stack<char> st;
      for (char c : s) {
        if (isdigit(c)) {
          num.push_back(c);
        }
        else if (c==']') {
          while (st.top()!='[') {
            temp.push_back(st.top());
            st.pop();
          }
          st.pop();

          for (int i=nums.top(); i>0; --i)
            for (int j=temp.size()-1; j>=0; --j) {
              st.push(temp[j]);
            }

          temp.clear();
          nums.pop();
        }
        else {
          if (c=='[') {
            nums.push(stoi(num));
            num.clear();
          }

          st.push(c);
        }
      }

      int n = st.size();
      char res[n+1];
      for (int i=n-1; i>=0; --i) {
        res[i] = st.top();
        st.pop();
      }

      res[n] = '\0';
      
      return string(res);
    }
};


int main() {
  UFUNC(Solution::decodeString);
  return 0;
}