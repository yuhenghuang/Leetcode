import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class AccountMerge {
  int uid=-1;
  List<String> tmp;
  List<List<Integer>> graph;
  Map<String, Integer> map;
  String[] emails;
  boolean[] visited;
  public List<List<String>> accountsMerge(List<List<String>> accounts) {
    // accounts.sort((x, y) -> x.get(0).compareTo(y.get(0)));
    graph = new ArrayList<>();
    map = new HashMap<>();

    int id_a, id_b;
    for (List<String> person: accounts) {
      if (person.size()==1) continue;
      id_a = getUID(person.get(1));
        for (int j=2; j<person.size(); ++j) {
          id_b = getUID(person.get(j));
          graph.get(id_a).add(id_b);
          graph.get(id_b).add(id_a);
        }
    }
    emails = new String[map.size()];
    visited = new boolean[map.size()];
    for (Map.Entry<String, Integer> entry : map.entrySet()) 
      emails[entry.getValue()] = entry.getKey();

    for (String e :emails)
      System.out.println(e);
    tmp = new ArrayList<>();
    List<List<String>> res = new ArrayList<>();
    for (List<String> person: accounts) {
      if (person.size()<2) continue;
      goThought(map.get(person.get(1)));
      if (tmp.size()>0) {
        tmp.sort((x, y) -> x.compareTo(y));
        List<String> todo = new ArrayList<>();
        todo.add(person.get(0));
        todo.addAll(tmp);
        res.add(todo);
        tmp.clear();
      }
    }
    return res;
  }

  void goThought(int cur) {
    if (visited[cur]) return;
    tmp.add(emails[cur]);
    visited[cur] = true;
    for (int next : graph.get(cur))
      goThought(next);
  }

  int getUID(String s) {
    if (uid>=graph.size())
      graph.add(new ArrayList<>());
    map.computeIfAbsent(s, val -> ++uid);
    return map.get(s);
  }
}