import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestPrimeAirRoute
{
    private PrimeAirRoute primeAirRoute;

    @BeforeAll
    public void setUp()
    {
        primeAirRoute = new PrimeAirRoute();
    }

    private static Object[][] testPrimeAirRouteDataProvider()
    {
        return new Object[][] {
                {7000, new int[][] {{1, 2000}, {2, 4000}, {3, 6000}}, new int[][] {{1, 2000}}, List.of(Arrays.asList(2, 1))},
                {10000, new int[][] {{1, 3000}, {2, 5000}, {3, 7000}, {4, 10000}}, new int[][] {{1, 2000}, {2, 3000}, {3, 4000}, {4, 5000}},
                        Arrays.asList(Arrays.asList(2, 4), Arrays.asList(3, 2))}
        };
    }

    @ParameterizedTest
    @MethodSource("testPrimeAirRouteDataProvider")
    public void testPrimeAirRoute(int maxTravelDist, int[][] forwardRouteList, int[][] returnRouteList, List<List<Integer>> expectation)
    {
        List<List<Integer>> ret = primeAirRoute.primeAirRoute(maxTravelDist, forwardRouteList, returnRouteList);
        assertEquals(expectation.size(), ret.size());
        ret.sort(Comparator.comparingInt(a -> a.get(0)));
        List<List<Integer>> sortableExpectation = new ArrayList<>(expectation);
        sortableExpectation.sort(Comparator.comparingInt(a -> a.get(0)));
        for (int i = 0; i < ret.size(); ++i) {
            assertEquals(sortableExpectation.get(i), ret.get(i));
        }
    }
}
