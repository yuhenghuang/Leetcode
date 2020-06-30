import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.Stack;

class ReconstructItinerary {
  public static void main(String[] args) {
    ReconstructItinerary obj = new ReconstructItinerary();
    List<List<String>> tickets = new ArrayList<>();
    tickets.add(new ArrayList<>(List.of("MUC", "LHR")));
    tickets.add(new ArrayList<>(List.of("JFK", "MUC")));
    tickets.add(new ArrayList<>(List.of("SFO", "SJC")));
    tickets.add(new ArrayList<>(List.of("LHR", "SFO")));
    System.out.println(obj.findItinerary(tickets));
  }
  int n, m;
  String[] cities;
  int[][] seen;
  List<Integer> ls;
  Stack<Integer> stack;
  Map<String, Integer> map;
  List<List<Integer>> graph;
  public List<String> findItinerary(List<List<String>> tickets) {
    Set<String> set = new HashSet<>();
    for (List<String> flight : tickets) 
      set.addAll(flight);

    n = set.size();
    cities = new String[n];

    int idx=0;
    for (String city : set) 
      cities[idx++] = city;

    Arrays.sort(cities);
    map = new HashMap<>();
    graph = new ArrayList<>();
    for (int i=0; i<n; ++i) {
      map.put(cities[i], i);
      graph.add(new ArrayList<>());
    }

    seen = new int[n][n];
    for (List<String> flight : tickets) {
      int st = map.get(flight.get(0)), ed = map.get(flight.get(1));
      graph.get(st).add(ed);
      ++seen[st][ed];
    }

    for (int i=0; i<n; ++i)
      graph.get(i).sort(Comparator.naturalOrder());

    m = tickets.size()+1;
    // ls = new ArrayList<>();
    stack = new Stack<>();

    stack.push(map.get("JFK"));
    dfs(map.get("JFK"));

    List<String> ans = new ArrayList<>();
    for (int i : ls)
      ans.add(cities[i]);

    return ans;
  }

  void dfs(int v) {
    // System.out.println(stack.size());
    if (ls!=null) return;
    if (stack.size()==m) {
      ls = new ArrayList<>(stack);
      return;
    }

    for (int w : graph.get(v)) {
      if (seen[v][w]==0) continue;
      stack.push(w);
      --seen[v][w];
      dfs(w);
      stack.pop();
      ++seen[v][w];
    }
  }
}