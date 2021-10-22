import java.util.Arrays;

// LC-1465
// variant:
// Amazon: storage optimization
// Create a function that takes in a matrix, and an array of rows and
// an array of columns to be removed from the matrix, and return the
// size of the biggest cubic space after removing the shelves and columns.
public class MaximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCuts
{
    public int maxArea(int h, int w, int[] horizontalCuts, int[] verticalCuts) {
        long verticalMaxDistanceBetweenTwoCuts = maxDistanceBetweenTwoCuts(verticalCuts, w);
        long horizontalMaxDistanceBetweenTwoCuts = maxDistanceBetweenTwoCuts(horizontalCuts, h);
        return (int) ((verticalMaxDistanceBetweenTwoCuts * horizontalMaxDistanceBetweenTwoCuts) % ((int) Math.pow(10,9) + 7));
    }

    private long maxDistanceBetweenTwoCuts(int[] cuts, int size) {
        long maxDistanceBetweenTwoCuts = 0;
        int[] cutsWithBoundaries = new int[cuts.length + 2];
        System.arraycopy(cuts, 0, cutsWithBoundaries, 0, cuts.length);
        cutsWithBoundaries[cuts.length] = 0;
        cutsWithBoundaries[cuts.length + 1] = size;
        Arrays.sort(cutsWithBoundaries);
        for (int i = 1; i < cutsWithBoundaries.length; ++i) {
            if (cutsWithBoundaries[i] - cutsWithBoundaries[i-1] > maxDistanceBetweenTwoCuts) {
                maxDistanceBetweenTwoCuts = cutsWithBoundaries[i] - cutsWithBoundaries[i-1];
            }
        }
        return maxDistanceBetweenTwoCuts;
    }
}
