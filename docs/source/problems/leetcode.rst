.. _leetcode.rst:

#################
Leetcode Problems
#################

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



