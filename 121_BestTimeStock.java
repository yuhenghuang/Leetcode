import java.io.FileInputStream;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

class BestTimeStock {
  public static void main(String[] args) {
    FileInputStream f = null;
    Scanner sc = null;
    int[] prices;
    BestTimeStock obj = new BestTimeStock();

    try {
      f = new FileInputStream("Inputs/121_BestTimeStock.txt");
      sc = new Scanner(f);
      String line;
      while (sc.hasNextLine()) {
        line = sc.nextLine();
        line = line.replaceAll("[\\[\\]\\s]+", "");
        prices = Arrays.stream(line.split(",")).mapToInt(Integer::parseInt).toArray();
        System.out.println(obj.maxProfit(prices));
      }
      if (f!=null)
        f.close();
    }
    catch (IOException e) {

    }
    finally {
      if (sc!=null)
        sc.close();
    }
  }
  
  public int maxProfit(int[] prices) {
    int n=prices.length, res=0, curr_min=Integer.MAX_VALUE;
    for (int i=0; i<n; ++i) {
      res = Math.max(res, prices[i]-curr_min);
      curr_min = Math.min(curr_min, prices[i]);
    }
    return res;
  }
}
