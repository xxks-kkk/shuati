// https://allhackerranksolutionsbykaira.blogspot.com/2020/08/group-division-hackerrank-solution.html
// Amazon OA 2021
public class GroupDivision
{
    public int groupDivision(int[] levels, int maxSpread)
    {
        int numGroups = 0;
        int[] marks = new int[levels.length];
        for (int i = 0; i < levels.length; ++i) {
            if (marks[i] == 0) {
                numGroups++;
                marks[i] = 1;
                for (int j = i; j < levels.length; ++j) {
                    if (Math.abs(levels[j] - levels[i]) <= maxSpread) {
                        marks[j] = 1;
                    }
                }
            }
        }
        return numGroups;
    }
}
