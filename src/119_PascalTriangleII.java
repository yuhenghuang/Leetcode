import java.util.ArrayList;
import java.util.List;

class PascalTriangleII {
  public static void main(String[] args) {
    PascalTriangleII obj = new PascalTriangleII();
    System.out.println(obj.getRow(3));
  }
  int N;
  List<Integer> prev, res;
  public List<Integer> getRow(int rowIndex) {
    N = rowIndex;
    prev = new ArrayList<>();
    res = new ArrayList<>();
    res.add(1);
    dfs(0);
    return res;
  }

  void dfs(int layer) {
    if (layer==N) return;
    res.clear();
    res.add(1);
    for (int i=1; i<=layer; ++i) {
      res.add(prev.get(i-1) + prev.get(i));
    }
    res.add(1);

    prev.clear();
    prev.addAll(res);
    dfs(layer+1);
  }
}