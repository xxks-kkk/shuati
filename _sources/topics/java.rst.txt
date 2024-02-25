.. _java.rst:

#############
Java Snippets
#############

==============
Priority Queue
==============

- custom comparator

  - `comparator can perform arbitrary calculation <https://github.com/xxks-kkk/shuati/blob/master/java/java-leetcode/src/main/java/KClosestPointsToOrigin.java>`__
  - `comparator comparing based on element in hashmap <https://github.com/xxks-kkk/shuati/blob/master/java/java-leetcode/src/main/java/LeastNumberOfUniqueIntegersAfterKRemovals.java>`__

=====
Array
=====

- `generate a sequentially increasing numbers as int[] <https://github.com/xxks-kkk/shuati/blob/master/java/java-others/src/main/java/CloudFrontCaching.java>`__

- `sort int[] in decreasing order <https://github.com/xxks-kkk/shuati/blob/master/java/java-others/src/main/java/OptimizeBoxWeight.java>`__

- `convert List<List<Integer>> into int[][] <https://github.com/xxks-kkk/shuati/blob/3dfeb445d035093afa2027059dab378d0c93c9f6/java/java-leetcode/src/main/java/MergeIntervals.java#L26>`__

- `get a subarray from an array using lambda <https://github.com/xxks-kkk/shuati/blob/914af3077ebbbd55fe76fd2cea5aa667ebb54e4a/java/java-leetcode/src/main/java/ThreeSum.java#L48>`__.
  Note that ``i+1`` and ``nums.length`` are inclusive, i.e., :math:`[i+1, nums.length]`.

- `extend each list inside a 2D list with one more element using lambda <https://github.com/xxks-kkk/shuati/blob/914af3077ebbbd55fe76fd2cea5aa667ebb54e4a/java/java-leetcode/src/main/java/ThreeSum.java#L50>`__.
  An example is: Given ``[[1,2],[3,4]]``, we add ``5`` to each list and obtain ``[[1,2,5],[3,4,5]]``.

- `create List<String> from String[] <https://github.com/xxks-kkk/shuati/blob/74bc965b4f491e6ad81fc3afc3ea3748352b1a56/java/java-leetcode/src/main/java/AnalyzeUserWebsiteVisitPattern.java#L51-L53>`__  

========
Hash Map
========

- We can use the following snippet to quickly initialize a hash map that counts
  the number of appearances for each unique value inside a given array of int.

  .. code-block:: java

     // key: unique num val: number of appearances inside int array
     HashMap<Integer, Integer> dict = new HashMap<>();
     for (int num: nums) {
         dict.put(num, dict.getOrDefault(num, 0) + 1);
     }

    
