.. _leetcode.rst:

#################
Leetcode Problems
#################

********
15. 3Sum
********

.. note::

   - `Youtube video <https://youtu.be/jzZsG8n2R9A>`__

The hard part of this problem is on how to make sure the solution set doesn't contain duplicate
triplets. Let :math:`(a,b,c)` represent a triplet that is part of the solution set. We have to
ensure that :math:`a` will be unique for each triplet in the solution set; otherwise, we may
run into the possibilities of including duplicates because :math:`a = -(b+c)` and :math:`a`
values are the same for two triplets, the rest two values are likely the same.

.. proof:example::

   Suppose ``nums = [-3,3,4,-3,1,2]``. For the first :math:`-3`, we find :math:`(-3,1,2)`.
   Now, when we use the second :math:`-3` as the :math:`a` value, we will find :math:`(-3,1,2)` again,
   which will be duplicate.

Then, the central idea to solve this problem is for each unique :math:`a` value, we reduce the problem
into a variant of twoSum problem: find all pairs of two sums without duplicate given array has been sorted.

We first sort ``nums``. Doing so helps us to identify all unique :math:`a` values efficiently and more importantly,
help us to find all pairs of two sums without duplicate efficiently by leveraging the fact that the array is sorted.

It is general hard to find all pairs of two sums without duplicate using hash map approach because it is very hard to
remove duplicates. Instead, we use two pointers approach, which is similar method to solve
`2Sum II <https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/>`__.

The idea follows: we use two pointers to point to two sides of the array. We move left or right pointer given the
sum is smaller than target or bigger than the target (see ``findAllTwoSums`` in solution). The key part is how to update
pointer when we hit a sum equals to the target. As pointed out in the Youtube video, we can just update left pointer
by one (or more if we hit duplicates: think about it, find two sums without duplicate is just a 3Sum problem reduced to
2Sum version). The reason we don't need to update right pointer is because once we update left pointer, the side effect
causes the sum bigger than target and in the next iteration of the while loop, the right pointer will be updated automatically.
The end result is that we have each unique value pointed by left pointer corresponds to a unique value pointed by right pointer.
     
.. note::

   I think there is a connection to binary search as well. Maybe think a bit more to master this idea.

In summary, the takeaways are:

- Ensure :math:`a` value being unique by using sorting and reduce the problem into a variant of twoSum problem
  (the two pointer solution is similar to `2Sum II <https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/>`__)

- Find all pairs of two sums without duplicate is hopeless to achieve uses traditional hash map approach as in twoSum problem.
  Instead, we should sort the array first and uses two pointers approach instead.

- In two pointer approach, when sum meets target, we only need to update left pointer.   

*********************
525. Contiguous Array
*********************

.. note::

   - problem: :cite:`LeetCode525`
   - `solution <https://github.com/xxks-kkk/shuati/tree/master/leetcode/525-ContiguousArray>`_
   - ref: :cite:`wh0ami`

The key idea of this problem is to use a hashmap :math:`m` to keep track of
unique sum of numbers that the algorithm has seen so far (denoted as :math:`s`) and
the associated index of the number that reaches :math:`s` for the first time (denoted as :math:`idx`).
:math:`m` then can be used to identify the desired subarray (denoted as :math:`A`) as following: algorithm computes accumulated
sum of numbers that have seen so far (denoted as :math:`sum`). Then, if `sum` is already in :math:`m`,
then it must be that we have found :math:`A` with starting index :math:`m[sum]` because each 1 adds one to :math:`sum`
and each 0 subtracts one from :math:`sum`. If :math:`sum` is found in :math:`m`, it must be that the same number of 0s and
1s have seen since the value corresponds to :math:`sum` first added in :math:`m`.

.. proof:example::

   Consider :math:`nums = [0,0,1,1,1,0,0]`. The corresponding :math:`sum` is
   :math:`[-1,-2,-1,0,1,0,-1]`. After the first 0, :math:`m` contains :math:`\langle 0,-1 \rangle, \langle -1,0 \rangle`.
   When algorithm checks first 1, :math:`sum` becomes :math:`-1` again. The algorithm finds an :math:`A`, which is :math:`[0,1]`.
   Intuitively, we can have the following picture:

   .. figure:: /_static/lc525/intuition-example.png

      :math:`{\color{red} \text{Red arrow}}` indicates :math:`A = [0,1]` with the property that number of 0s equal to number of 1s.

   Let :math:`i_1` denote the index of the number that corresponds to :math:`m[s_1]`. Let :math:`i_2` denote the index of the number
   that :math:`sum = s_1`. Then, to calculate the length of :math:`A`, we have :math:`i_2 - (i_1 + 1) + 1`, which is
   :math:`i_2 - i_1`. In this example, :math:`A = [0,1]` has length :math:`2 - (0 + 1) + 1 = 2`.


*****************************
1041. Robot Bounded In Circle
*****************************

.. note::

   `This Youtube video <https://youtu.be/nKv2LnC_g6E>`_ has a great explanation, which explains the idea behind
   `this LC post <https://leetcode.com/problems/robot-bounded-in-circle/discuss/290856/JavaC%2B%2BPython-Let-Chopper-Help-Explain>`__.

The central idea is to realize the connection between the impact of instructions on robot and conditions when circle can happen. One whole execution of ``instructions``
can impact the robot in two ways:

1. change the robot position; and 
2. change the direction that the robot is facing.

Robot can be bounded in a circle if after one whole execution of ``instructions``,

1. the robot stays at :math:`(0,0)`; or
2. the robot is no longer facing north. 

Let's consider a few examples.

.. proof:example::

   Suppose ``instructions = "GG"``. Initially, the robot is facing north (indicated by a direction vector :math:`\langle 0,1 \rangle`). After two ``G``, the
   robot moves to the position :math:`(0,2)` and is still facing north. In this case, no matter how many times ``instructions`` are executed, robot is still
   facing north and circle can never be formed.

.. proof:example::

   Suppose ``instructions = "GGLL"``. After two ``G``, the robot is at :math:`(0,2)` facing north. Now, ``L`` will make the robot turn left (the direction vector
   is :math:`\langle -1,0 \rangle`) and another ``L`` will make the robot turn left again (the direction vector is :math:`\langle 0,-1 \rangle`). In this case,
   one more ``instructions`` execution make the robot back to the origin.

.. proof:example::

   Suppose ``instructions = "GGR"``. After two ``G``, the robot is at :math:`(0,2)` facing north. Now, ``R`` will make the robot turn right (the direction vector
   is :math:`\langle 1,0 \rangle`). The robot follows such instruction will get back to :math:`(0,0)` after additional three executions as shown in :numref:`GGR-example`.

   .. _GGR-example:
   .. figure:: /_static/lc1041/GGR-example.png

      Illustration of ``instructions = "GGR"`` makes the robot back to the origin and thus, form a circle.

Implementation wise, make sure the direction change is calculated correctly. For example, when the robot change from facing north to facing west. The direction vector changes
from :math:`\langle 0,1 \rangle` to :math:`\langle -1,0 \rangle`. If the direction vector is :math:`\langle vec_x, vec_y \rangle`, then after the direction change, the direction vector
becomes :math:`\langle -vec_y, vec_x \rangle`.
      

******************************************************
1481. Least Number of Unique Integers after K Removals
******************************************************

There is :math:`O(n)` solution (compared to priority queue :math:`O(n\log n)` solution) available as well.

`ref <https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/discuss/686335/JavaPython-3-Greedy-Alg.%3A-3-methods-from-O(nlogn)-to-O(n)-w-brief-explanation-and-analysis.>`__



