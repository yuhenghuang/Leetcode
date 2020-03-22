import java.util.Arrays;

public class Search2DMatrixII {
  public static void main(String[] args) {
    int[][] input = new int[][] {
      {1,   4,  7, 11, 15},
      {2,   5,  8, 12, 19},
      {3,   6,  9, 16, 22},
      {10, 13, 14, 17, 24},
      {18, 21, 23, 26, 30}
    };

    Search2DMatrixII obj = new Search2DMatrixII();
    System.out.println(obj.searchMatrix(input, 5));
    
  }

  public boolean searchMatrix(int[][] matrix, int target) {
    int m = matrix.length, n = m==0?0:matrix[0].length;
    if (m==0 || n==0) return false;
    int left = bs(matrix, target, m, 0);
    int right = bs(matrix, target, m, n-1);
    System.out.println(left+" "+right);
    for (int i=right; i<=left; ++i)
      if (Arrays.binarySearch(matrix[i], target)>=0)
        return true;
    return false;
  }

  private int bs(int[][] matrix, int target, int m, int n) {
    int up=0, down=m, mid=0;
    while (up<down) {
      mid = (up + down) / 2;
      if (matrix[mid][n]>target) down=mid-1;
      else if (matrix[mid][n]<target) up=mid+1;
      else return mid;
    }
    return mid;
  }
}