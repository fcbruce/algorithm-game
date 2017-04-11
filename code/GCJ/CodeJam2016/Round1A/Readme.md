[Google Code Jam 2016 - Round 1A](https://code.google.com/codejam/contest/4304486/dashboard)  
====

#### Problem A. The Last Word  
大的扔前面。  

#### Problem B. Rank and File  
如果都不缺的话那么每个格子的数都恰好出现 2 次，缺一条的话，那些数只出现 1 次，所以输出出现奇数次的数就行了。

#### Problem C. BFFs  
考虑这种情况 `1 -> 2 -> 3 -> 4 -> 5 -> 4`， 这种情况的链是已经满足的了，由若干个这种链组成的环也是满足的；  
然后考虑这种 `1 -> 2 -> 3 -> 4 <-> 5 <- 6 <- 7`，同上；  
以上两种链组合起来都是 ok 的，然后还有是构成环的情况，所以计算前面两种的总长度，和一整个环的比一下就行了。  
