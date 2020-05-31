class NumOfSubsrrayKGreater {
  public static void main(String[] args) {
    NumOfSubsrrayKGreater obj = new NumOfSubsrrayKGreater();
    int[] arr = LeetcodeUtil.arrayIntParser("[7,7,7,7,7,7,7]");
    System.out.println(obj.numOfSubarrays(arr, 7, 7));
  }
  public int numOfSubarrays(int[] arr, int k, int threshold) {
    int target = k * threshold - 1, sum=0, res=0;
    for (int i=0; i<arr.length; ++i) {
      sum += arr[i];
      if (i>=k)
        sum -= arr[i-k];

      if (i>k-2 && sum>target)
        ++res;
    }
    return res;
  }
}