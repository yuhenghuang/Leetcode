#include <numeric>
#include "utils3.hpp"

// O(nCl) space complexity
class CombinationIterator {
  private:
    vector<string> combs;
    vector<string>::iterator iter;

    void dfs(int i, const string& characters, int l, string& s) {
      if (l == 0) {
        combs.push_back(s);
        return;
      }

      for (; i + l <= characters.size(); ++i) {
        s.push_back(characters[i]);
        dfs(i + 1, characters, l - 1, s);
        s.pop_back();
      }
    }

  public:
    CombinationIterator(string characters, int combinationLength) {
      string s;
      dfs(0, characters, combinationLength, s);

      iter = combs.begin();
    }
    
    string next() {
      return *iter++;
    }
    
    bool hasNext() {
      return iter != combs.end();
    }
};


// O(1)
class CombinationIteratorO1 {
  private:
    vector<int> indicies;
    string str;
    // has next flag
    bool flag;

  public:
    CombinationIteratorO1(string characters, int combinationLength): 
      str(characters), indicies(combinationLength) 
    {
      flag = characters.size() >= combinationLength;

      iota(indicies.begin(), indicies.end(), 0);
    }
    
    string next() {
      string s;
      for (int i : indicies)
        s.push_back(str[i]);

      int n = str.size();
      int i = indicies.size() - 1;
      // find the first index i where indicies[i] + 1 < indicies[i+1]
      // such that we can move ith character in the combination one step forward
      while (i >= 0 && indicies[i] + 1 == n)
        n = indicies[i--];

      // not such index found -> end of combination
      if (i == -1)
        flag = false;
      else {
        ++indicies[i++];
        for (; i < indicies.size(); ++i)
          indicies[i] = indicies[i-1] + 1;
      }

      return s;
    }
    
    bool hasNext() {
      return flag;
    }
};



int main() {
  UFUNCX(
    CTOR(string, int),
    &CombinationIterator::next,
    &CombinationIterator::hasNext
  );
  UFUNCX(
    CTOR(string, int),
    &CombinationIteratorO1::next,
    &CombinationIteratorO1::hasNext
  );
  return 0;
}