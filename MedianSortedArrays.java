public class MedianSortedArrays {
  public double findMedianSortedArrays(int[] nums1, int[] nums2) {
    int m=nums1.length, n=nums2.length;
    if (m>n) {
      int[] temp = nums1; nums1=nums2; nums2=temp;
      int tmp = m; m=n; n=tmp;
    }
    
    int left=0, right=m, target=(m+n+1)/2;  
    while (left<=right) {
      int mid1 = (left + right)/2;
      int mid2 = target-mid1;
      if (mid1<right && nums1[mid1]<nums2[mid2-1]) {
        left = mid1+1;
      }
      else if (mid1>left && nums1[mid1-1]>nums1[mid2]) {
        right = mid1-1;
      }
      else {
        int maxLeft=0;
        if (mid1==0) maxLeft=nums2[mid2-1];
        else if (mid2==0) maxLeft=nums1[mid1-1];
        else maxLeft=Math.max(nums1[mid1-1], nums2[mid2-1]);
        if ((m+n)%2==1) return maxLeft;

        int maxRight=0;
        if (mid1==m) maxRight=nums2[mid2];
        else if (mid2==n) maxRight=nums1[mid1];
        else maxRight=Math.min(nums1[mid1], nums2[mid2]);
        return (maxLeft+maxRight)/2;
      }
    }

    // 4 situations (mid1==0, mid1==n, mid2<0, mid2>n)
    // (m+n) % 2 == 1 or 0
    // etc....

    return 0;
  }
}