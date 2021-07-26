.. _lc525-continus-array.rst:

#######################
LC525 Contiguous Array
#######################

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

   .. figure:: /_static/lc525-contiguous-array/intuition-example.png

      :math:`{\color{red} \text{Red arrow}}` indicates :math:`A = [0,1]` with the property that number of 0s equal to number of 1s.

   Let :math:`i_1` denote the index of the number that corresponds to :math:`m[s_1]`. Let :math:`i_2` denote the index of the number
   that :math:`sum = s_1`. Then, to calculate the length of :math:`A`, we have :math:`i_2 - (i_1 + 1) + 1`, which is
   :math:`i_2 - i_1`. In this example, :math:`A = [0,1]` has length :math:`2 - (0 + 1) + 1 = 2`.
   
