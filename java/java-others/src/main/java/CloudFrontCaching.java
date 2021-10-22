import java.util.Arrays;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

// https://aonecode.com/oa-cloudfront-caching
public class CloudFrontCaching
{
    private static class UnionFind
    {
        int[] sizes;
        int[] parent;

        UnionFind(int n)
        {
            sizes = new int[n];
            Arrays.fill(sizes, 1);
            // generate a sequentially increasing numbers as int[]
            parent = IntStream
                    .rangeClosed(0, n)
                    .boxed()
                    .collect(Collectors.toList())
                    .stream()
                    .mapToInt(i -> i)
                    .toArray();
        }

        int find(int node)
        {
            while (node != parent[node]) {
                node = parent[node];
            }
            return node;
        }

        void union(int node1, int node2)
        {
            int node1Root = find(node1);
            int node2Root = find(node2);
            if (node1Root != node2Root) {
                if (sizes[node1Root] > sizes[node2Root]) {
                    parent[node2Root] = node1Root;
                    sizes[node1Root] += sizes[node2Root];
                    sizes[node2Root] = 0;
                }
                else {
                    parent[node1Root] = node2Root;
                    sizes[node2Root] += sizes[node1Root];
                    sizes[node1Root] = 0;
                }
            }
        }
    }

    public int costEvaluation(int n, int[][] connections)
    {
        UnionFind unionFind = new UnionFind(n);
        for (int[] connection : connections) {
            unionFind.union(connection[0], connection[1]);
        }
        int totalCost = 0;
        for (int i = 0; i < unionFind.sizes.length; ++i) {
            totalCost += (int) Math.ceil(Math.sqrt(unionFind.sizes[i]));
        }
        return totalCost;
    }
}
