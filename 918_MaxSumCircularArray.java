import java.util.Arrays;

class MaxSumCircularArray {
  public int maxSubarraySumCircular(int[] A) {
    int sum_all = Arrays.stream(A).sum();
    int sum_min = Integer.MAX_VALUE, temp=0;
    for (int num : A) {
      if (temp>0) temp=0;
      temp += num;
      if (temp<sum_min) sum_min = temp;
    }

    int sum_max = Integer.MIN_VALUE;
    temp = 0;
    for (int num : A) {
      if (temp<0) temp=0;
      temp += num;
      if (temp>sum_max) sum_max = temp;
    }
    return sum_all==sum_min ? sum_max : Math.max(sum_max, sum_all - sum_min);
  }
}