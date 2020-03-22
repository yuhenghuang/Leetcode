import java.util.Map;
import java.util.HashMap;
import java.util.Arrays;

public class NumofAtoms {
  public static void main(String[] args) {
    NumofAtoms obj = new NumofAtoms();
    obj.countOfAtoms("Mg12(OH)20");
  }


  Map<String, Integer> hash;
  String formula;
  int idx;
  public String countOfAtoms(String formula) {
    hash = new HashMap<>();
    this.formula = formula;
    idx = formula.length()-1;
    recursive(1);
    System.out.println(hash);
    String[] keys = new String[hash.size()];
    hash.keySet().toArray(keys);
    Arrays.sort(keys);
    
    StringBuffer res = new StringBuffer();
    for (String s : keys) {
      res.append(s);
      if (hash.get(s)>1) res.append(String.valueOf(hash.get(s)));
    }
    return res.toString();
  }

  public void recursive (int times) {
    StringBuffer strBuf_times = new StringBuffer();
    StringBuffer strBuf_atoms = new StringBuffer();
    while (idx>=0 && formula.charAt(idx)!='(') {
      if (Character.isDigit(formula.charAt(idx))) {
        strBuf_times.insert(0, formula.charAt(idx));
      }
      else if (Character.isUpperCase(formula.charAt(idx))) {
        strBuf_atoms.insert(0, formula.charAt(idx));
        if (strBuf_times.length()==0) {
          safePut(strBuf_atoms.toString(), times);
        }
        else {
          safePut(strBuf_atoms.toString(), times * Integer.parseInt(strBuf_times.toString()));
          strBuf_times = new StringBuffer();
        }
        strBuf_atoms = new StringBuffer();
      }
      else if (Character.isLowerCase(formula.charAt(idx))) {
        strBuf_atoms.insert(0, formula.charAt(idx));
      }
      else if (formula.charAt(idx)==')') {
        --idx;
        if (strBuf_times.length()==0) recursive(times);
        else {
          recursive(times * Integer.parseInt(strBuf_times.toString()));
          strBuf_times = new StringBuffer();
        }
      }
      --idx;
    }
  }

  public void safePut(String str, int times) {
    if (hash.containsKey(str)) hash.put(str, hash.get(str)+times);
    else hash.put(str, times);
  }
}