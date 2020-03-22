import java.util.List;
import java.util.ArrayList;

public class Game24 {
  public boolean judgePoint24(int[] nums) {
    List<Double> list = new ArrayList<>();
    for (int num : nums) list.add((double) num);
    return dfs(list);
  }

  public boolean dfs(List<Double> list) {
    if (list.size()==0) return false;
    if (list.size()==1) return Math.abs(list.get(0)-24)<1e-6;

    for (int i=0; i<list.size(); ++i)
      for (int j=0; j<list.size(); ++j) 
        if (i!=j) {
          List<Double> listNew = new ArrayList<>();
          for (int k=0; k<list.size(); ++k) 
            if (k!=i && k!=j)
              listNew.add(list.get(k));
          
          for (int k=0; k<4; ++k) {
            if (k<2 && j>i) continue;
            switch(k) {
              case 0 : listNew.add(list.get(i)+list.get(j)); break;
              case 1 : listNew.add(list.get(i)*list.get(j)); break;
              case 2 : listNew.add(list.get(i)-list.get(j)); break;
            }
            if (k==3)
              if (list.get(j)!=0)
                listNew.add(list.get(i)/list.get(j));
            else continue;
            
            if (dfs(listNew)) return true;
            listNew.remove(listNew.size()-1);
          }
        }
    return false;
  }
}