import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestAnalyzeUserWebsiteVisitPattern
{
    private AnalyzeUserWebsiteVisitPattern analyzeUserWebsiteVisitPattern;

    @BeforeAll
    public void setUp()
    {
        analyzeUserWebsiteVisitPattern = new AnalyzeUserWebsiteVisitPattern();
    }

    private static Object[][] testAnalyzeUserWebsiteVisitPatternDataProvider()
    {
        return new Object[][] {
                {new String[] {"joe", "joe", "joe", "james", "james", "james", "james", "mary", "mary", "mary"},
                        new int[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                        new String[] {"home", "about", "career", "home", "cart", "maps", "home", "home", "about", "career"},
                        Arrays.asList("home", "about", "career")},
                {new String[] {"ua", "ua", "ua", "ub", "ub", "ub"},
                        new int[] {1, 2, 3, 4, 5, 6},
                        new String[] {"a", "b", "a", "a", "b", "c"},
                        Arrays.asList("a", "b", "a")}
        };
    }

    @ParameterizedTest
    @MethodSource("testAnalyzeUserWebsiteVisitPatternDataProvider")
    public void testLeastNumberOfUniqueIntegersAfterKRemovals(String[] username, int[] timestamp, String[] website, List<String> expectation)
    {
        List<String> ret = analyzeUserWebsiteVisitPattern.mostVisitedPattern(username, timestamp, website);
        assertEquals(expectation.size(), ret.size());
        for (int i = 0; i < ret.size(); ++i) {
            assertEquals(expectation.get(i), ret.get(i));
        }
    }
}
