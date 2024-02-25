.. _others.rst:

######
Others
######

******************
CloudFront Caching
******************

.. figure:: /_static/others/cloudfront-caching.png

   CloudFront Caching problem.

A :ref:`union-find.rst` problem.

*******************
Get Mean Rank Count
*******************

The problem is a varaint of `count subarrays with average K <https://www.geeksforgeeks.org/count-of-subarrays-with-average-k/>`__. I'll use the link problem
for explanation.

Consider an array :math:`x_0, x_1, \dots, x_4` and a subarray :math:`x_1, x_2, x_3` has average :math:`k`. The **key observation** is that if
every number in :math:`x_1, x_2, x_3` is subtracted by :math:`k`, the average becomes 0, i.e.,

.. math::

   (x_1 + x_2 + x_3)/ 3 = k \implies (x_1 - k + x_2 - k + x_3 - k) / 3 = 0

Thus, the problem becomes that we are looking for the subarrays who have average 0. The average becomes 0 if :math:`x_1' + x_2' + x_3' = 0` where :math:`x_i' = x_i - k`.
There are two possible situations we can detect that:

1. :math:`x_1' + x_2' + x_3' = 0` directly via the sum
2. We can rewrite :math:`x_1' + x_2' + x_3'` as :math:`(x_0' + x_1' + x_2' + x_3') - x_0'` and :math:`x_0' + x_1' + x_2' + x_3'  = x_0'`.
   In general, for :math:`\sum_l=i^j x_l'`, we can rewrite it as :math:`\sum_{l=0}^j x_l' - \sum_{l=0}^{i-1} x_l'`.

How to implement the two checks can be seen in the referenced link.
