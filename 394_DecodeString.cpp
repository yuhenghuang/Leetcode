#include <local_leetcode.hpp>

class Solution {
  private:
    string repeat(const string& s, size_t n) {
      string out;
      out.reserve(s.size() * n);

      while (n--)
        out += s;

      return out;
    }

    string recursion(const string& s, size_t& i) {
      string res;
      string num;
      while (i < s.size() && s[i] != ']') {
        if (isdigit(s[i]))
          num.push_back(s[i]);
        else if (s[i] == '[') {
          ++i;
          res += repeat(recursion(s, i), stoul(num));

          num.clear();
        }
        else
          res.push_back(s[i]);

        ++i;
      }

      return res;
    }

  public:
    string decodeStringRecursion(string s) {
      size_t i = 0;
      return recursion(s, i);
    }


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
      res[n] = '\0';
      for (int i=n-1; i>=0; --i) {
        res[i] = st.top();
        st.pop();
      }
      
      return string(res);
    }
};


int main() {
  EXECS(Solution::decodeString);
  EXECS(Solution::decodeStringRecursion);
  return 0;
}