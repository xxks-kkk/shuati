
import java.util.Comparator;
import java.util.HashMap;
import java.util.PriorityQueue;

// LC-1481
public class LeastNumberOfUniqueIntegersAfterKRemovals
{
    public LeastNumberOfUniqueIntegersAfterKRemovals() {}

    public int findLeastNumOfUniqueInts(int[] arr, int k)
    {
        // idea: scan through all elements in arr with <the number, number of appearances>
        // using a priority queue and keeps removing the number with the smallest number of appearances
        HashMap<Integer, Integer> dict = new HashMap<>();
        for (int element : arr) {
            dict.put(element, dict.getOrDefault(element, 0) + 1);
        }
        // We don't need to use Pair; we can use "Comparator.comparing" instead
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.comparing(dict::get));
        pq.addAll(dict.keySet());
        while (pq.peek() != null && dict.get(pq.peek()) <= k) {
            k -= dict.get(pq.poll());
        }
        return pq.size();
    }
}
