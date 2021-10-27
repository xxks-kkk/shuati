import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

/**
 * Given max travel distance and forward and backward route list,
 * return a pair of ids of forward and backward routes that optimally
 * utilized the max travel distance.
 * https://www.careercup.com/question?id=5750442676453376
 */
public class PrimeAirRoute
{
    List<List<Integer>> primeAirRoute(int maxTravelDist, int[][] forwardRouteList, int[][] returnRouteList)
    {
        List<List<Integer>> res = new ArrayList<>();
        int sumOfDist = 0;
        // List<Integer> contains three elements: <sum of distance, id from forwardRouteList, id from returnRouteList>
        PriorityQueue<List<Integer>> pq = new PriorityQueue<>(Comparator.comparingInt(a -> (maxTravelDist - a.get(0))));
        for (int[] forwardRoute : forwardRouteList) {
            for (int[] returnRoute : returnRouteList) {
                sumOfDist = forwardRoute[1] + returnRoute[1];
                if (sumOfDist <= maxTravelDist) {
                    pq.add(Arrays.asList(sumOfDist, forwardRoute[0], returnRoute[0]));
                }
            }
        }
        int diffWithMaxTravelDist = maxTravelDist;
        while (!pq.isEmpty()) {
            List<Integer> element = pq.poll();
            sumOfDist = element.get(0);
            if (sumOfDist <= maxTravelDist && maxTravelDist - sumOfDist <= diffWithMaxTravelDist) {
                diffWithMaxTravelDist = maxTravelDist - sumOfDist;
                res.add(Arrays.asList(element.get(1), element.get(2)));
            }
            else {
                break;
            }
        }
        return res;
    }
}
