## 树上启发式合并
适用于维护子树内信息
### 例题：CF246E
#### 思路

1. 暴力
将询问离线下来，挂在每个点上\
对于每个点 $x$，维护一个桶 $cnt_{dep}$，统计深度 $dep$ 下不同字符串出现的次数\
对于 $x$ 上的询问输出 $cnt_{dep_x+k}$\
每切换一个 $x$，$cnt$ 要重置

2. $DSU$ 优化
维护每个子树的大小 $size_x$，以及每个点 $x$ 最大的字数大小的节点 $son_x$\
定义 $x$ 下最大的字数大小为 $x$ 的重儿子，其余为轻儿子\
设从根往下走，每次只走重儿子的链叫重链\
对于离线下来的询问，约定根节点为 $x$，先遍历 $x$ 的轻儿子，在遍历重儿子\
此时对于重儿子的 $cnt$ 将不会被重构\
那么重链上的点只被遍历一遍，只有轻儿子会被重复遍历，接下来就变成了并查集的按秩合并
