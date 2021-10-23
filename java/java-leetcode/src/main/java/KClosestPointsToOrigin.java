import java.util.PriorityQueue;

// LC-973
public class KClosestPointsToOrigin
{
    public int[][] kClosest(int[][] points, int k)
    {
        int[][] res = new int[k][];
        // This is a max heap: note the lambda function: it is p2 calculated value - p1 calculated value
        // max heap is critical for algorithm correctness
        PriorityQueue<int[]> pq = new PriorityQueue<>((p1, p2) -> p2[0] * p2[0] + p2[1] * p2[1] - p1[0] * p1[0] - p1[1] * p1[1]);
        for (int[] point : points) {
            pq.add(point);
            if (pq.size() > k) {
                pq.poll();
            }
        }
        for (int i = 0; i < res.length; ++i) {
            res[i] = pq.poll();
        }
        return res;
    }
}
