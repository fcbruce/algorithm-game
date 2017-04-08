[Kickstart 2017 - Round A](https://code.google.com/codejam/contest/8284486/dashboard)
====

#### Problem A. Square Counting  
对于边长为l的正方形，大概能生成 l * (w - l + 1) * (h - l + 1) 个“内接”正方形  
w和h分布为矩形的宽和高  
化简一下公式能O(1)求

#### Problem B. Patterns Overlap  
dp[i][j] 瞎搞搞

#### Problem C. Space Cubes  
先考虑二维的情况：  
1. 用一个正方形，显然算出圆形的4个方向上的最值  
2. 用两个正方形，显然两个正方形按对角放置，枚举对角方案  

考虑三维，多了几个对角线方案，枚举一下，可以状压瞎搞搞，二分边长  
