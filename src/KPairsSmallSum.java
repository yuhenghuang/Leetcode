import java.util.List;
import java.util.ArrayList;

public class KPairsSmallSum {
  public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
    int i=0, j=0, cnt=0;
    List<List<Integer>> res = new ArrayList<>();
    while (cnt++<k && i<nums1.length && j<nums2.length) {
      res.add(new ArrayList<>(List.of(nums1[i], nums2[j])));
      if (i<nums1.length-1 && j<nums2.length-1) {
        if (nums1[i+1]<nums2[i+1]) i++;
        else j++;
      }
      else if (i==nums1.length-1 && j<nums2.length-1){
        j++;
      }
      else if (i<nums1.length-1 && j==nums2.length-1) {
        i++;
      }
      else break;
    }
    return res;
  }
}