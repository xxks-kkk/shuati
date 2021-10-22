import java.util.Arrays;

// LC-1465
// variant:
// Amazon: storage optimization
// Create a function that takes in a matrix, and an array of rows and
// an array of columns to be removed from the matrix, and return the
// size of the biggest cubic space after removing the shelves and columns.
public class MaximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCuts
{
    public int maxArea(int h, int w, int[] horizontalCuts, int[] verticalCuts)
    {
        long verticalMaxDistanceBetweenTwoCuts = maxDistanceBetweenTwoCuts(verticalCuts, w);
        long horizontalMaxDistanceBetweenTwoCuts = maxDistanceBetweenTwoCuts(horizontalCuts, h);
        return (int) ((verticalMaxDistanceBetweenTwoCuts * horizontalMaxDistanceBetweenTwoCuts) % ((int) Math.pow(10, 9) + 7));
    }

    private long maxDistanceBetweenTwoCuts(int[] cuts, int size)
    {
        Arrays.sort(cuts);
        long maxDistanceBetweenTwoCuts = cuts[0];
        for (int i = 1; i < cuts.length; ++i) {
            if (cuts[i] - cuts[i - 1] > maxDistanceBetweenTwoCuts) {
                maxDistanceBetweenTwoCuts = cuts[i] - cuts[i - 1];
            }
        }
        // We need to consider the distance between last cut and the boundary (i.e., size)
        maxDistanceBetweenTwoCuts = Math.max(maxDistanceBetweenTwoCuts, size - cuts[cuts.length - 1]);
        return maxDistanceBetweenTwoCuts;
    }
}
