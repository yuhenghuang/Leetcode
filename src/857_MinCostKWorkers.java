import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

class MinCostKWorkers {
  public double mincostToHireWorkers(int[] quality, int[] wage, int K) {
    int N = quality.length;
    Worker[] jobmarket = new Worker[N];
    for (int i=0; i<N; ++i)
      jobmarket[i] = new Worker(quality[i], wage[i]);

    PriorityQueue<Integer> heap = new PriorityQueue<>(
      (a, b) -> b - a
    );
    
    Arrays.sort(jobmarket);
    int qsum=0;
    for (int i=0; i<K; ++i) {
      qsum+=jobmarket[i].quality;
      heap.offer(jobmarket[i].quality);
    }
    double res = qsum * jobmarket[K-1].unitwage;

    for (int i=K; i<N; ++i) {
      Worker wk = jobmarket[i];
      if (wk.quality<heap.peek()) {
        qsum = qsum - heap.poll() + wk.quality;
        heap.offer(wk.quality);
        res = Math.min(res, qsum * wk.unitwage);
      }
    }
    return res;
  }

  class Worker implements Comparable<Worker> {
    int quality, wage;
    double unitwage;
    Worker(int q, int w) {
      quality = q;
      wage = w;
      unitwage = (double) w / q;
    }

    @Override
    public int compareTo(Worker other) {
      return Double.compare(unitwage, other.unitwage);
    }
  }


  public double mincostToHireWorkersSlow(int[] quality, int[] wage, int K) {
    int N = quality.length;
    double res=0;
    double[] unitwage = new double[N];

    Integer[] idx = new Integer[N];
    for (int i=0; i<N; ++i) {
      idx[i] = i;
      unitwage[i] = (double) wage[i] / (double) quality[i];
    }
    Arrays.sort(idx, new Comparator<Integer>() {
      @Override
      public int compare(Integer a, Integer b) {
        return Double.compare(unitwage[a], unitwage[b]);
      }
    });


    int prev_qsum=0;
    PriorityQueue<Integer> heap = new PriorityQueue<>((a, b) -> b-a);
    for (int i=0; i<K; ++i) {
      int p = idx[i];
      heap.offer(quality[p]);
      prev_qsum+=quality[p];
    }
    res=prev_qsum * unitwage[idx[K-1]];

    for (int i=K; i<N; ++i) {
      int p = idx[i];
      if (unitwage[p] * (prev_qsum - heap.peek() + quality[p])<res) {
        prev_qsum = prev_qsum - heap.peek() + quality[p];
        res = unitwage[p] * prev_qsum;
        heap.poll();
        heap.offer(quality[p]);
      }
      else if (quality[p]<heap.peek()) {
        prev_qsum = prev_qsum - heap.peek() + quality[p];
        heap.poll();
        heap.offer(quality[p]);
      }
    }
    return res;
  }
}