#include <local_leetcode.hpp>

class Comparator {
  private:
    vector<int>& norm;
  public:
    Comparator(vector<int>& n): norm(n) {}
    bool operator () (const int& i, const int& j) const {
      return norm[i] < norm[j];
    }
};

class Solution {
  private:
    int computeNorm(vector<int>& p) {
      return p[0] * p[0] + p[1] * p[1];
    }
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
      int n = points.size();
      vector<int> norm(n);
      vector<int> idx(n);
      for (int i=0; i<n; ++i) {
        norm[i] = computeNorm(points[i]);
        idx[i] = i;
      }
      sort(idx.begin(), idx.end(), Comparator(norm));
      vector<vector<int>> res(K);
      for (int i=0; i<K; ++i)
        res[i] = points[idx[i]];
      return res;
    }

    vector<vector<int>> kClosestHeap(vector<vector<int>>& points, int k) {
      int n = points.size();
      
      vector<int> norm(n);
      for (int i=0; i<n; ++i) 
        norm[i] = computeNorm(points[i]);

      priority_queue<int, vector<int>, std::function<bool (int, int)>> heap(
        [&norm](int i, int j) -> bool {
          return norm[i] < norm[j];
        }
      );

      for (int i = 0; i < n; ++i){
        if (heap.size() < k)
          heap.push(i);
        else if (norm[heap.top()] > norm[i]) {
          heap.pop();
          heap.push(i);
        }
      }


      vector<vector<int>> res(k);
      while (!heap.empty()) {
        res[--k] = points[heap.top()];
        heap.pop();
      }

      return res;
    }
};


int main() {
  EXECS(Solution::kClosest);
  EXECS(Solution::kClosestHeap);
  return 0;
}