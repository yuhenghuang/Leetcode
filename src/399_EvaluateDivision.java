import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

class EvaluateDivisionUF {
  public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
    // unfinished
    UnionFind uf = new UnionFind();
    for (int i=0; i<values.length; ++i) 
      uf.addNode(equations.get(i).get(0), equations.get(i).get(1), values[i]);
    
    double[] res = new double[queries.size()];
    for (int i=0; i<res.length; ++i) 
      res[i] = uf.search(queries.get(i).get(0), queries.get(i).get(1));
    return res;
  }

  class UnionFind {
    Map<String, Map<String, Double>> dict;

    UnionFind() {
      dict = new HashMap<>();
    }

    void addNode(String a, String b, double d) {
      if (!dict.containsKey(a)) {
        dict.put(a, new HashMap<>());
        dict.get(a).put(a, 1.);
      }
      if (!dict.containsKey(b)) {
        dict.put(b, new HashMap<>());
        dict.get(b).put(b, 1.);
      }
      Map<String, Double> map_a = dict.get(a);
      Map<String, Double> map_b = dict.get(b);
      //map_a.put(b, d);
      for (String s : map_b.keySet()) {
        if (!map_a.containsKey(s)) {
          map_a.put(s, d * map_b.get(s));
        }
      }
    }

    double search(String a, String b) {
      if (!dict.containsKey(a) || !dict.containsKey(b)) return -1;

      if (dict.get(a).containsKey(b)) {
        return dict.get(a).get(b);
      }
      else if (dict.get(b).containsKey(a)) {
        return 1. / dict.get(b).get(a);
      }
      else {
        Set<String> set = new HashSet<>(dict.get(a).keySet());
        set.retainAll(dict.get(b).keySet());
        for (String s : set) 
          return dict.get(a).get(s) / dict.get(b).get(s);
      }
      return -1.;
    }
  }
}

class EvaluateDivisionDFS {
  public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
    UnionFind uf = new UnionFind();
    for (int i=0; i<values.length; ++i) {
      String a = equations.get(i).get(0);
      String b = equations.get(i).get(1);
      uf.addNode(a, b, values[i]);
      uf.addNode(b, a, 1 / values[i]);
    }

    double[] res = new double[queries.size()];
    for (int i=0; i<res.length; ++i) {
      res[i] = uf.search(queries.get(i).get(0), queries.get(i).get(1));
    }
    return res;
  }

  class UnionFind {
    Map<String, Map<String, Double>> dict;
    Set<String> visited;

    UnionFind() {
      dict = new HashMap<>();
    }

    void addNode(String a, String b, double d) {
      if (!dict.containsKey(a)) {
        dict.put(a, new HashMap<>());
        dict.get(a).put(a, 1.);
      }
      dict.get(a).put(b, d);
    }

    double search(String a, String b) {
      if (!dict.containsKey(a) || !dict.containsKey(b)) return -1;
      visited = new HashSet<>();
      return dfs(1., a, b);
    }

    double dfs(double d, String a, String b) {
      if (visited.contains(a)) return -1.;
      if (a.equals(b)) return d;
      visited.add(a);
      Map<String, Double> map = dict.get(a);
      double res=-1.;
      for (String s : map.keySet()) {
        res = dfs(d * map.get(s), s, b);
        if (res>-1.) return res;
      }
      return res;
    }
  }
}