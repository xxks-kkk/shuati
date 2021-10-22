import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestCloudFrontCaching
{
    private CloudFrontCaching cloudFrontCaching;

    @BeforeAll
    public void setUp()
    {
        cloudFrontCaching = new CloudFrontCaching();
    }

    private static Object[][] testCloudFrontCachingDataProvider()
    {
        return new Object[][] {
                {4, new int[][]{{0,2},{1,2}}, 3},
                {10, new int[][] {{2,6},{3,5},{0,1},{2,9},{5,6}}, 8},
        };
    }

    @ParameterizedTest
    @MethodSource("testCloudFrontCachingDataProvider")
    public void testCloudCaching(int n, int[][] connections, int expected)
    {
        assertEquals(expected, cloudFrontCaching.costEvaluation(n, connections));
    }
}
