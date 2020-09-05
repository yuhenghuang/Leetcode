import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class LargestComponentSize {
  public int largestComponentSize(int[] A) {
    UnionFind uf = new UnionFind(100001);
    Map<Integer, Integer> map = new HashMap<>();
    for (int x : A) 
      for (int i=2; i*i<x; ++i)
        if (x%i==0) {
          uf.unite(i, x);
          uf.unite(x, x/i);
        }

    int res=0;
    for (int x : A) {
			int idx = uf.find(x);
			int count = map.getOrDefault(idx, 0)+1;
			res = Math.max(res, count);
			map.put(idx, count);
		}

		return res;
  }

  class UnionFind {
    int[] id;
    UnionFind(int n) {
      id = new int[n];
      Arrays.fill(id, -1);
    }

    int find(int x) {
      if (id[x]==-1)
        return x;
      else {
        id[x] = find(id[x]);
        return id[x];
      }
    }

    void unite(int x, int y) {
      x = find(x);
      y = find(y);
      if (x!=y)
        id[y] = x;
    }
  }
}