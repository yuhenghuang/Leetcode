import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;

// WHITE: unseen, GREY: searching, BLACK: searched
enum Colors {WHITE, GREY, BLACK}

class SortItemsByGroups {
  public static void main(String[] args) {
    SortItemsByGroups obj = new SortItemsByGroups();
    List<List<Integer>> beforeItems = LeetcodeUtil.listInt2dParser("[[],[6],[5],[6],[3,6],[],[],[]]");
    int[] group = LeetcodeUtil.arrayIntParser("[-1,-1,1,0,0,1,0,-1]");
    System.out.println(Arrays.toString(obj.sortItems(8, 2, group, beforeItems)));
  }
  Colors[] clr_item, clr_group;
  Stack<Integer> stack;
  boolean possible;
  public int[] sortItems(int n, int m, int[] group, List<List<Integer>> beforeItems) {
    List<List<Integer>> graph_item = new ArrayList<>(n);
    List<List<Integer>> graph_group = new ArrayList<>(n);
    clr_item = new Colors[n];
    clr_group = new Colors[n];
    int group_id = n;
    for (int i=0; i<n; ++i) {
      // initialize graphs and colors of items/groups
      graph_item.add(new ArrayList<>());
      graph_group.add(new ArrayList<>());
      clr_item[i] = Colors.WHITE;
      clr_group[i] = Colors.WHITE;
      if (group[i]<0) // -1 to new group ids from n-1, n-2, ...
        group[i] = --group_id;
    }

    for (int i=0; i<n; ++i) 
      for (int before : beforeItems.get(i)) {
        graph_item.get(before).add(i);
        if (group[before]==group[i]) continue;
        List<Integer> ws = graph_group.get(group[before]);
        if (!ws.contains(group[i]))
          ws.add(group[i]);
      }

    // arrays of topological orders
    // index : item/group, value : order
    int[] order_item = new int[n], order_group = new int[n];
    stack = new Stack<>();
    possible = true; // flag for no circle
    for (int i=0; i<n; ++i)
      if (clr_item[i]==Colors.WHITE)
        dfs(i, graph_item, clr_item);
    if (!possible)  return new int[]{};
    int order = -1;
    while(!stack.empty())
      order_item[stack.pop()] = ++order;

    for (int i=0; i<n; ++i)
      if (clr_group[i]==Colors.WHITE)
        dfs(i, graph_group, clr_group);
    if (!possible)  return new int[]{};
    order = -1;
    while(!stack.empty())
      order_group[stack.pop()] = ++order;

    Integer[] res = new Integer[n];
    for (int i=0; i<n; ++i)
      res[i] = i;
    Arrays.sort(res, (v, w)-> (order_group[group[v]]==order_group[group[w]])?(order_item[v]-order_item[w]):(order_group[group[v]]-order_group[group[w]]));
    return Arrays.stream(res).mapToInt(i->i).toArray();
  }

  void dfs(int v, List<List<Integer>> graph, Colors[] clr) {
    if (!possible) return;
    clr[v] = Colors.GREY;
    for (int w : graph.get(v)) {
      if (clr[w]==Colors.WHITE) {
        dfs(w, graph, clr);
      }
      else if (clr[w]==Colors.GREY) {
        possible = false;
        return;
      }
    }
    stack.push(v); // possible improvement: save topological orders directly instead of through stack.
    clr[v] = Colors.BLACK;
  }
}