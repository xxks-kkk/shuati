package org.zhu45.shuati.java.leetcode.twoSum;

import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;
import static org.zhu45.shuati.java.leetcode.twoSum.TwoSum.twoSum;

public class TestTwoSum
{
    private static Object[][] testTwoSumDataProvider() {
        return new Object[][] {
                {new int[] {2,7,11,15}, 9}
        };
    }

    @ParameterizedTest
    @MethodSource("testTwoSumDataProvider")
    public void testTwoSum(int[] num, int target) {
        assertArrayEquals(new int[] {0, 1}, twoSum(num, target));
    }
}
