#include <local_leetcode.hpp>

class Solution {
  private:
    static const string encoder[26];

    vector<size_t> code2size() const {
      vector<size_t> out;
      out.reserve(26);
      size_t temp;
      for (const string& w : encoder) {
        temp = 0;
        for (char c : w) {
          temp <<= 1;
          temp += c=='.' ? 0 : 1;
        }
        out.push_back(temp);
      }

      return out;
    }
  public:
    int uniqueMorseRepresentations(vector<string>& words) {

      unordered_set<string> codes;

      for (const string& w : words) {
        string temp;
        for (char c : w) 
          temp.append(encoder[c-'a']);

        codes.insert(std::move(temp));
      }

      return codes.size();
    }

    int uniqueMorseRepresentationsBS(vector<string>& words) {
      static const vector<uint64_t> bins = code2size();

      unordered_set<uint64_t> codes;
      uint64_t temp;
      for (const string& w : words) {
        temp = 0;
        for (char c : w) {
          temp <<= encoder[c-'a'].size();
          temp ^= bins[c-'a'];
        }
        codes.insert(temp);
      }

      return codes.size();
    }
};

const string Solution::encoder[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};


int main() {
  EXECS(Solution::uniqueMorseRepresentations);
  EXECS(Solution::uniqueMorseRepresentationsBS);
  return 0;
}