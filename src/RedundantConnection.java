import java.util.Map;
import java.util.HashMap;


public class RedundantConnection {
  public int[] findRedundantConnection(int[][] edges) {
    UnionFind uf = new UnionFind();
    for (int[] pair : edges) {
      if (!uf.union(pair)) return pair;
    }
    return new int[2];
  }

  class UnionFind {
    Map<Integer, Integer> map;
    Map<Integer, Integer> rank;
    UnionFind() {
      map = new HashMap<>();
      rank = new HashMap<>();
    }

    public int find(int p) {
      int parent = map.get(p);
      while (parent!=map.get(parent)) {
        parent=map.get(parent);
      }
      map.put(p, parent);
      return parent;
    }

    public boolean union(int[] pair) {
      add(pair[0]);
      add(pair[1]);

      int i = find(pair[0]);
      int j = find(pair[1]);
      if (i==j) return false;
      else {
        if (rank.get(i)>rank.get(j)) {
          map.put(j, i);
        }
        else if (rank.get(i)<rank.get(j)) {
          map.put(i, j);
        }
        else {
          map.put(j, i);
          rank.put(i, rank.get(i)+1);
        }
        return true;
      }
    }

    public void add(int num) {
      if (!map.containsKey(num)) {
        map.put(num, num);
        rank.put(num, 1);
      }
    }
  }
}