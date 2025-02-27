#### 项目简介
跟随课程《高级计算机算法》，将课堂上涉及的算法逐个实现。  
涵盖的主要算法有：

* 递归
* 贪心算法
* 分治法
* 动态规划

并根据自身不足补充和回顾部分算法


#### 第一章  绪论
##### 1.1 求最大公约数
文件：[greatest_common_division.cpp](https://github.com/ThetaQing/Algorithm/blob/master/AdvancedAlgorithm/AdvancedAlgorithm/greatest_common_division.cpp)  
主要使用了三种算法：欧几里得算法、连续正整数检测算法和公共质因数相乘法，并比较三种算法的复杂度。

##### 1.2 素数检测
文件：[primality_check.cpp](https://github.com/ThetaQing/Algorithm/blob/master/AdvancedAlgorithm/AdvancedAlgorithm/primality_check.cpp)  
由于1.1 求最大公约数问题中涉及到质数相乘，所以添加素数检测部分。  
主要使用的同余运算。实现了费马小定理判断质数以及对费马小定理的改进——MilleRabin算法判断质数。

##### 1.3 模取幂运算
文件：[modular_exponention.cpp](https://github.com/ThetaQing/Algorithm/blob/master/AdvancedAlgorithm/AdvancedAlgorithm/modular_exponention.cpp)  
在MilleRabin算法中反复用到了模取幂运算，即求一个数的幂对另一个数的模运算，所以展开讨论并实现。  
主要算法是反复平方法。

#### 第二章 递归
##### 2.1 斐波那契数列
文件：[fibonacci.cpp](https://github.com/ThetaQing/Algorithm/blob/master/AdvancedAlgorithm/AdvancedAlgorithm/fibonacci.cpp)  
主要包括递归实现和非递归实现。非递归实现又有利用数组暂存中间结果（需要O(n)的内存空间）和利用公式累加实现（O(1)的空间复杂度）。

##### 2.2 汉诺塔问题的求解
文件：[hanoi.cpp](https://github.com/ThetaQing/Algorithm/blob/master/AdvancedAlgorithm/AdvancedAlgorithm/hanoi.cpp)  
主要包括递归实现和压栈实现。

#### 第三章 分治法

分治法很大程度上是利用的递归，但是思路还是不一样，所以单独一章~

##### 3.1 排序算法
文件：[sort.cpp](https://github.com/ThetaQing/Algorithm/blob/master/AdvancedAlgorithm/AdvancedAlgorithm/sort.cpp)  
排序算法中堆排序和快排都是运用的分治法，所以这里对十大经典排序逐一实现和分析。  
主要有：比较类排序：通过比较来决定元素间的相对次序，由于其时间复杂度不能突破 O(nlogn)，被称为非线性时间比较类排序；  
				交换排序（1、冒泡排序；2、快速排序）  
				插入排序（3、简单插入排序；4、希尔排序）  
				选择排序（5、简单选择排序；6、堆排序）  
				归并排序（7、二路归并排序；8、多路归并排序（暂未实现））  
			非比较排序：不通过比较来决定元素间的相对次序，它可以突破基于比较排序的时间下界，以线性时间运行，因此被称为线性时间非比较类排序。  
				9、计数排序；  
				10、桶排序；  
				11、基数排序。

##### 3.2 两个大整数相乘
文件：[divide_and_conquer.cpp](https://github.com/ThetaQing/Algorithm/blob/master/AdvancedAlgorithm/AdvancedAlgorithm/divide_and_conquer.cpp)  
主要实现算法为karatsuba乘法。

##### 3.3 棋牌覆盖问题
文件：[divide_and_conquer.cpp](https://github.com/ThetaQing/Algorithm/blob/master/AdvancedAlgorithm/AdvancedAlgorithm/divide_and_conquer.cpp)  
##### 3.4 寻找第k个最小值
文件：[divide_and_conquer.cpp](https://github.com/ThetaQing/Algorithm/blob/master/AdvancedAlgorithm/AdvancedAlgorithm/divide_and_conquer.cpp)  
主要实现了两种方法，一种是基于快排的，平均时间复杂度O(nlogn)，最差情况为O(n^2)；另一种是基于分组的分治算法，正在实现中……
