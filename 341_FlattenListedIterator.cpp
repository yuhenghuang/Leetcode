#include "utils3.hpp"

/*
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

*/

/*
class NestedIterator {
  private:
    typedef typename vector<NestedInteger>::const_iterator iter_type;
    stack<const vector<NestedInteger>*> lists;
    stack<iter_type> iters;
  
  public:
    NestedIterator(vector<NestedInteger> &nestedList) {
      lists.push(&nestedList);
      iters.push(nestedList.cbegin());
    }
    
    int next() {
      return iters.top()++->getInteger();
    }
    
    bool hasNext() {
      while (!lists.empty() && (iters.top() == lists.top()->cend() || !iters.top()->isInteger())) {
        if (iters.top() == lists.top()->cend()) {
          lists.pop();
          iters.pop();
          if (!lists.empty())
            ++iters.top();
        }
        else {
          lists.push(&iters.top()->getList());
          iters.push(lists.top()->cbegin());
        }
      }
      
      return !lists.empty();
    }
};
*/

class NestedIterator {
  private:
    typedef typename vector<NestedInteger>::const_iterator iter_type;
    stack<pair<iter_type, iter_type>> iters;
  
  public:
    NestedIterator(vector<NestedInteger> &nestedList) {
      iters.emplace(nestedList.cbegin(), nestedList.cend());
    }
    
    int next() {
      return iters.top().first++->getInteger();
    }
    
    bool hasNext() {
      while (!iters.empty() && (iters.top().first == iters.top().second || !iters.top().first->isInteger())) {
        if (iters.top().first == iters.top().second) {
          iters.pop();
          if (!iters.empty())
            ++iters.top().first;
        }
        else {
          const vector<NestedInteger>& vec = iters.top().first->getList();
          iters.emplace(vec.cbegin(), vec.cend());
        }
      }
      
      return !iters.empty();
    }
};


class Solution {
  public:
    vector<int> flattenList(vector<NestedInteger>& nestedList) {
      vector<int> res;

      NestedIterator iter(nestedList);
      while (iter.hasNext())
        res.push_back(iter.next());

      return res;
    }
};


int main() {
  UFUNCS(Solution::flattenList);
  return 0;
}