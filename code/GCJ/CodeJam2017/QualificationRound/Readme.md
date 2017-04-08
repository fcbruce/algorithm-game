[Google Code Jam 2017 - Qualification Round](https://code.google.com/codejam/contest/3264486/dashboard)
====

#### Problem A. Oversized Pancake Flipper  
虽然是高斯消元，但其实是个上三角的矩阵，所以直接回代就能求解 => 直接贪心从前往后扫，遇到 `'-'` 直接翻。  

#### Problem B. Tidy Numbers
第一眼看成求数量以为是数位dp，求last的话就直接dfs了。  

#### Problem C. Bathroom Stalls
小数据的话直接 O(nlogn) 搞；  
大数据要推一下，本质是 Perfect Binary Tree, 画几棵就能发现每一层的值最大最小不会超过1，那么先定位在第几层，然后二分求一下这一层最大的又多少个就行，复杂度 O(logn)。

#### Problem D. Fashion Show
老子不会。
