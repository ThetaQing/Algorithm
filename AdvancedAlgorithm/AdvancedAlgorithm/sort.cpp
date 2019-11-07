#include "sort.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
using std::vector;
/****************文件说明*********************
* 文件名：sort.cpp
* 文件功能：排序算法的实现
* 实现方法：十大经典排序算法
*			比较类排序：通过比较来决定元素间的相对次序，由于其时间复杂度不能突破 O(nlogn)，被称为非线性时间比较类排序；
				交换排序（1、冒泡排序；2、快速排序）
				插入排序（3、简单插入排序；4、希尔排序）
				选择排序（5、简单选择排序；6、堆排序）
				归并排序（7、二路归并排序；8、多路归并排序）
			非比较排序：不通过比较来决定元素间的相对次序，它可以突破基于比较排序的时间下界，以线性时间运行，因此被称为线性时间非比较类排序。
				9、计数排序；
				10、桶排序；
				11、基数排序。

* 相关概念：
			稳定：如果a原本在b前面，而a=b，排序之后a仍然在b的前面。
			不稳定：如果a原本在b的前面，而a=b，排序之后 a 可能会出现在 b 的后面。
			时间复杂度;对排序数据的总的操作次数。反映当n变化时，操作次数呈现什么规律。
			空间复杂度：是指算法在计算机内执行时所需存储空间的度量，它也是数据规模n的函数。


**/

/************函数说明***********
* 函数名：BubbleSort(vector vec)
* 函数参数：待排序的整数数组
* 函数返回值：无。通过引用传参，将已排好序的数组替换掉原来没有排序的数组
* 函数功能：实现对输入数组的排序
* 函数算法：冒泡排序
			重复地走访过要排序的数列，一次比较两个元素，如果它们的顺序错误就把它们交换过来。走访数列的工作是重复地进行直到没有再需要交换，也就是说该数列已经排序完成。
				1、比较相邻的元素。如果第一个比第二个大，就交换它们两个；
				2、对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，这样在最后的元素应该会是最大的数；
				3、针对所有的元素重复以上的步骤，除了最后一个；
				4、重复步骤1~3，直到排序完成。
* 时间复杂度： 平均O(n^2)，最好O(n)，最坏O(n^2)
**/

void BubbleSort(vector <int> &vec)
{
	size_t count = vec.size();  // 记录比较的轮数,size_t的真实类型与操作系统有关，在64位机上是8字节，32位机上是4字节，是无符号数
	for (int j = 0; j < count; ++j)
	{
		// 对每个元素从第一个到已排序的数比较一次
		for (int i = 0; i < count - 1; ++i)
		{
			if (vec[i] > vec[i+1])
				swap(vec[i], vec[i+1]);  // 比较两个相邻的数，小数放在大数前面
		}  // 每完成一轮，便多一个已排序好的数，即这一轮的最后一个，便可以减少一个数的比较

		count -= 1;
	}	
}

/************函数说明***********
* 函数名：SelectionSort(int *vec, int len)
* 函数参数：待排序的整数数组，数组长度
* 函数返回值：无。通过引用传参，将已排好序的数组替换掉原来没有排序的数组
* 函数功能：实现对输入数组的排序
* 函数算法：选择排序：首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，
			然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。 
				1、初始状态：无序区为R[1..n]，有序区为空；
				2、第i趟排序(i=1,2,3…n-1)开始时，当前有序区和无序区分别为R[1..i-1]和R(i..n）。
					该趟排序从当前无序区中-选出关键字最小的记录 R[k]，将它与无序区的第1个记录R交换，
					使R[1..i]和R[i+1..n)分别变为记录个数增加1个的新有序区和记录个数减少1个的新无序区；
				3、n-1趟结束，数组有序化了。
* 时间复杂度： O(n^2)，最好最坏情况都是O(n^2)。最稳定的算法之一
**/
void SelectionSort(int *vec, int len)
{
	// int len = vec.size();
	int temp_min = 0;  // 定义变量，记录最小值的索引
	// 比较n-1轮
	for (int i = 0; i < len; ++i)
	{		
		// 每一轮找最小值的索引，起始值为i，因为前i-1个已经排好序了
		temp_min = i;
		for (int j = i + 1; j < len; ++j)
		{
			if (vec[temp_min] > vec[j])  // vec[i]已经被记录，所以j=i+1即可
				temp_min = j;  // 记录最小值的索引
		}
		swap(vec[temp_min], vec[i]);  // 将最小值与第i个数交换，此时前i个都排好序了
	}
}

/************函数说明***********
* 函数名：InsertionSort(int *vec, int len)
* 函数参数：待排序的整数数组,数组长度
* 函数返回值：无。通过引用传参，将已排好序的数组替换掉原来没有排序的数组
* 函数功能：实现对输入数组的排序
* 函数算法：简单插入排序：通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入
			1、从第一个元素开始，该元素可以认为已经被排序；
			2、取出下一个元素，在已经排序的元素序列中从后向前扫描；
			3、如果该元素（已排序）大于新元素，将该元素移到下一位置；
			4、重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
			5、将新元素插入到该位置后；
			6、重复步骤2~5
* 时间复杂度： O(n)
**/
void InsertionSort(int *vec, int len)
{
	int temp = 0;
	for (int i = 1; i < len; ++i)
	{
		temp = vec[i];
		int j = i-1;
		while (j >= 0 && temp < vec[j] )
		{
			vec[j + 1] = vec[j];  // 向后移动一个位置，第一次实际上是覆盖vec[i]，由此腾出插入temp的位置
			--j;  // 进行下一个数的比较
		}
		vec[j+1] = temp;  // 如果不满足循环条件，说明此时vec[j] < temp，temp插入该元素的后面
	}
}

/************函数说明***********
* 函数名：ShellSort(int *vec, int len)
* 函数参数：待排序的整数数组,数组长度
* 函数返回值：无。通过引用传参，将已排好序的数组替换掉原来没有排序的数组
* 函数功能：实现对输入数组的排序
* 函数算法：希尔排序：第一个突破O(n2)的排序算法，是简单插入排序的改进版.与插入排序的不同之处在于，它会优先比较距离较远的元素。希尔排序又叫缩小增量排序。
				先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，具体算法描述：
					1、选择一个增量序列t1，t2，…，tk，其中ti>tj，tk=1；
					2、按增量序列个数k，对序列进行k 趟排序；
					3、每趟排序，根据对应的增量ti，将待排序列分割成若干长度为m 的子序列，分别对各子表进行直接插入排序。仅增量因子为1 时，整个序列作为一个表来处理，表长度即为整个序列的长度。
* 时间复杂度： 希尔排序的时间复杂度与增量(即，步长gap)的选取有关。例如，当增量为1时，希尔排序退化成了直接插入排序，此时的时间复杂度为O(N^2)，而Hibbard增量(gap = len/2,gap = gap/2)的希尔排序的时间复杂度为O(N^(3/2))。
* 希尔排序的时间复杂度是：O（nlog2n）～O（n2），平均时间复杂度大致是O(n^1.5)
* 空间复杂度：O(1)
* 不稳定
**/

void ShellSort(int* arr, int len)
{
	for (int gap = len / 2; gap > 0; gap = gap / 2)  // 生成增量序列
	{
		// 多个分组交替执行，每个分组达到退出while循环的条件后开始下一个执行分组
		for (int i = gap; i < len; ++i)  // 从gap开始，即默认所有分组的第一都是已排序的
		{
			int j = i;  // 从当前位置开始向数组起始端移动
			int current = arr[i];  // 正在移动比较的数
			while (j - gap >= 0 && current < arr[j - gap])  // 如果当前移动比较的这个数小于比较序列中的数
			{
				arr[j] = arr[j - gap];// 将这个大的数向后移动		
				j = j - gap;  // 继续比较
			}
			arr[j] = current;  // arr[j - gap] < current，在arr[j-gap]的后一个位置arr[j]处插入当前比较的值

		}
	}
	
}


/************函数说明***********
* 函数名：vector<int> MergeSort(vector<int> arr, int start, int end)
* 函数参数：待排序的整数数组,待排序中起始位置索引，待排序数组的终止位置索引，整个数组都进行排序为(ArrayName, 0, ArrayName.size()-1)
* 函数返回值：返回排好序的数组
* 函数功能：实现对输入数组的排序
* 函数算法：归并排序：建立在归并操作上的一种有效的排序算法。
			该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。
			将已有序的子序列合并，得到完全有序的序列；
			即先使每个子序列有序，
			再使子序列段间有序。
			若将两个有序表合并成一个有序表，称为2-路归并。
			1、把长度为n的输入序列分成两个长度为n/2的子序列；
			2、对这两个子序列分别采用归并排序；
			3、将两个排序好的子序列合并成一个最终的排序序列。
* 时间复杂度： O(nlog2n)
* 空间复杂度：O(n)
* 稳定
* 

**/
// 归并两个数组的函数声明
vector<int> Merge(vector<int> left, vector<int> right);

vector<int> MergeSort(vector<int> arr, int start, int end)
{ 
	vector <int> left, right, result;

	if (start < end)  // 还可以继续分支
	{
		left = MergeSort(arr, start, (start + end) / 2);  // 递归分支
		right = MergeSort(arr, (start + end) / 2 + 1, end);  // 递归分支
		return Merge(left, right);  // 合并左右两支
	}
	else  // 只剩一个元素时，返回这个元素
	{
		result.push_back(arr[start]);
		return result;
	}	

}

/************函数说明***********
* 函数名：vector<int> Merge(vector<int> left, vector<int> right)
* 函数参数：两个有序数组，从小到大
* 函数返回值：返回这两个数组合并排序的数组
* 函数功能：实现对两个输入有序数组的排序
* 函数算法：归并
			1、比较两个数组公共长度部分，谁小push谁
			2、若right还有剩余元素未push，全部push到总数组末尾
			3、若left还有剩余元素未push，全部push到总数组末尾
			4、返回总数组
* 时间复杂度： O(n)
* 空间复杂度：O(n)

*

**/
vector<int> Merge(vector<int> left, vector<int> right)
{
	int i1 = 0, i2 = 0, i = 0;
	size_t len1 = left.size();  // 第一个数组的长度
	size_t len2 = right.size();  // 第二个数组的长度
	vector <int> result;  // 返回的排序数组
	while (i1 < len1 && i2 < len2)  // 当两个数组均有元素未push时
	{
		if (left[i1] < right[i2])  // push小的元素到结果数组中
		{
			result.push_back(left[i1]);
			i1 += 1;
		}
		else
		{
			result.push_back(right[i2]);
			i2 += 1;
		}

	}
	if (i1 >= len1)  // 当第一个数组元素全部push完后，将第二个数组剩余元素全部push到结果数组中
	{
		while (i2 < len2)
		{
			result.push_back(right[i2]);
			i2 += 1;
		}
	}
	if (i2 >= len2)  // 反之亦然
	{
		while (i1 < len1)
		{
			result.push_back(left[i1]);
			i1 += 1;
		}
	}
	return result;  // 返回排序好的数组
}

/************函数说明***********
* 函数名：void QuickSort(int *arr,int left, int right)
* 函数参数：待排序数组，起始元素索引，最后一个元素的索引，整个数组全排的调用为：QuickSort（arr, 0, arr.size()-1）
* 函数返回值：数组指针做参数，无返回值，数组的值直接发生变化
* 函数功能：实现对输入数组[left,right]区间数据的排序
* 函数算法：快速排序：通过一趟排序将待排记录分隔成独立的两部分，其中一部分记录的关键字均比另一部分的关键字小，则可分别对这两部分记录继续进行排序，以达到整个序列有序。
			快速排序使用分治法来把一个串（list）分为两个子串（sub-lists）。具体算法描述如下：
			1、从数列中挑出一个元素，称为 “基准”（pivot）；
			2、重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。
				在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；
			3、递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序。
* 时间复杂度： O(nlogn)
* 空间复杂度： O(nlogn)

*

**/

// 分区函数声明
int Partition(int *arr,int left, int right);  // 总是选择第一个元素
void QuickSort(int *arr,int left, int right)
{
	

	if (left < right)
	{
		int r = Partition(arr,left, right);
		QuickSort(arr, left, r-1);
		QuickSort(arr, r + 1, right);
	}	

}
/************函数说明***********
* 函数名：int Partition(int *arr, int left, int right)
* 函数参数：待分区数组，起始元素索引，最后一个元素的索引，整个数组全排的调用为：Partition（arr, 0, arr.size()-1）
* 函数返回值：返回输入数组中第一个元素在整个数组中按从小到大顺序排序后的索引。
* 函数功能：实现对输入数组[left,right]将第一个元素作为基准的数组分区，即基准左边全部是小于基准的数，右边全部是大于基准的数。
* 函数算法：主要思路是将数组分为两部分，以基准为分水岭，左边是小于基准的，右边是大于基准的
			实现方法：
				1、选中基准元素（这里选第一个元素，当然也可以换成最后一个元素或中间元素等）；
				2、找到第一个比基准大的数arr[last]并记录索引为last  (如果出现了大于基准的数，这个数就是第一个大于基准的数，否则是小于基准的数)；
				3、找到last索引之后第一个小于基准的数，交换这两个数的位置，并更新last索引；
				4、重复2~3步直到交换最后一个小于基准的值。
* 时间复杂度： O(nlogn)
* 空间复杂度： O(nlogn)

*

**/
int Partition(int *arr, int left, int right)
{
	// 分区的关键在于找到最后一个比基准小的数，将这个数和基准交换位置
	// 在这之前要把所有比基准小的数都划分到一边，最后一个交换过来的数就是最后一个比基准小的数

	int pivot = left;  // 选中第一个元素
	int last = left + 1;  // 指向已知比基准小的元素下一个位置
	for (int i = last; i <= right; ++i)  // 一定要注意right是最后一个元素的索引，arr[right]是可以取到值的
	{
		if (arr[i] < arr[pivot])
		{
			swap(arr[i], arr[last]);  // arr[i]始终是小于基准的，交换的要么是小于基准的数自己和自己交换（即i == last），要么arr[last]>arr[i]，即大于基准的数和小于基准的数发生交换
			last += 1;  // 如果该元素比基准小，索引标记指向当前元素的下一个位置，该位置可能比基准小也可能比基准大
			// 如果比基准大，那么将与下一个比基准小的数发生交换，或者在循环结束时，该位置的前一个元素（比基准小）与基准发生交换
			// 如果比基准小，那么将在新的一轮中指向下一个位置
		}
	}
	swap(arr[pivot], arr[last - 1]);  // 由于last指向的总是当前小于基准数的元素的下一个位置，所以要-1
	return last - 1;

}


/************函数说明***********
* 函数名：void HeapSort(int* arr,int len)
* 函数参数：待排序数组，数组长度
* 函数返回值：数组指针形式隐性返回排序的数组
* 函数功能：将输入数组排序
* 函数算法：利用堆这种数据结构所设计的一种排序算法。堆积是一个近似完全二叉树的结构，并同时满足堆积的性质：即子结点的键值或索引总是小于（或者大于）它的父节点。
			1、将初始待排序关键字序列(R1,R2….Rn)构建成大顶堆，此堆为初始的无序区；
			2、将堆顶元素R[1]与最后一个元素R[n]交换，此时得到新的无序区(R1,R2,……Rn-1)和新的有序区(Rn),且满足R[1,2…n-1]<=R[n]；
			3、由于交换后新的堆顶R[1]可能违反堆的性质，因此需要对当前无序区(R1,R2,……Rn-1)调整为新堆，然后再次将R[1]与无序区最后一个元素交换，
				得到新的无序区(R1,R2….Rn-2)和新的有序区(Rn-1,Rn)。不断重复此过程直到有序区的元素个数为n-1，则整个排序过程完成。

* 数据类型：数组
			如果i是节点的索引，那么有
				parent(i) = floor((i - 1)/2);
				left(i) = 2i + 1;
				right(i) = 2i + 2.
			所以在最大堆中，父节点的值总是大于或等于其子节点的值，即
				arr[parent(i)] >= arr[i]
			恒成立。
* 时间复杂度： O(nlogn)
* 空间复杂度： O(1)
* 不稳定，相等的元素可能在叶子节点上被交换到父节点上

*

**/
// 函数声明
int Parent(int i);
int Left(int i);
int Right(int i);
void BuildMaxHeap(int* arr, int len);  // 建立最大堆
void Heapify(int* arr, int len, int i);  // 将第i个节点调整成堆

void HeapSort(int* arr,int len)
{
	int last = len-1;
	BuildMaxHeap(arr, len);  // 初始化最大堆
	
	while (last > 0)
	{
		swap(arr[0], arr[last]); // 最大值转移
		// last表示数组中最后一个元素的索引，在交换一次之后，新的数组长度刚好是上一个数组最后一个元素的索引
		Heapify(arr, last, 0);  // 对新的数组进行堆化,从上到下开始调整！！！	
		last -= 1;
		
	}	
}
/************函数说明***********
* 函数名：void BuildMaxHeap(int* arr, int len) 
* 函数参数： 待排序数组，数组长度，注意是长度
* 函数返回值：数组指针做参数，返回最大堆排序的数组
* 函数功能：将无序数组初始化为最大堆
* 实现方法：定义法，最大堆的定义，父节点的值比左右节点的值都大
* 注意：初始化的时候是从下到上的顺序，要将最大的数一步一步移到父节点处，如果从上往下，最大值可能在最后一层非叶子节点上

*/
void BuildMaxHeap(int* arr, int len)  // 从下到上初始化！！！！
{
	
	// 从第一个非叶子节点开始
	for (int i = Parent(len-1); i >= 0; --i)
	{
		Heapify(arr, len, i);  // 从父节点开始堆化

	}
}
/************函数说明***********
* 函数名：void Heapify(int* arr, int len, int i)
* 函数参数： 待排序数组，数组长度，待堆化的节点索引
* 函数返回值：数组指针做参数，返回以节点i为根节点的最大堆排序的数组
* 函数功能：将节点i堆化，以节点i为父节点的最大堆
* 实现方法：定义法，最大堆的定义，父节点的值比左右节点的值都大
* 注意：每一次交换之后都要重新堆化，从上到下，因为上面的部分已经是最大堆的一部分了

*/
void Heapify(int* arr, int len, int i)
{
	int left = Left(i);
	int right = Right(i);
	
	if (left < len && arr[i] < arr[left])  // 比较左边
	{
		swap(arr[i], arr[left]);
		Heapify(arr, len, left);  // 发生交换，对新的数组堆化
	}
	if (right < len && arr[i] < arr[right])  // 比较右边
	{
		swap(arr[i], arr[right]);
		Heapify(arr, len, right);   // 发生交换，对新的数组堆化
	}
	
	

}

// 返回节点i的父节点
int Parent(int i)
{
	return (i - 1) / 2;
}
// 返回节点i的左节点
int Left(int i)
{
	return 2 * i + 1;
}
// 返回节点i的右节点
int Right(int i)
{
	return 2 * i + 2;
}

/************函数说明***********
* 函数名：void CountingSort(int* arr, int len)
* 函数参数：待排序数组，数组长度
* 函数返回值：数组指针隐性返回已排序的数组
* 函数功能：对输入数组进行排序
* 函数算法：计数排序，核心在于将输入的数据值转化为键存储在额外开辟的数组空间中，作为一种线性时间复杂度的排序，计数排序要求输入的数据必须是有确定范围的整数。
			1、找出待排序的数组中最大和最小的元素；
			2、统计数组中每个值为i的元素出现的次数，存入数组C的第i项；
			3、对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）；
			4、反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1。

* 数据类型：数组
* 时间复杂度： O(n+k)
* 空间复杂度： O(n+k)
* 稳定

* 注意：计数排序申请的额外空间跨度是从最小元素值到最大元素值，存在空间浪费现象

**/

void CountingSort(int* arr, int len)
{
	
	int min = 0, max = 0; 
	// 找到最大值和最小值
	for (int i = 0 ; i < len; ++i)
	{
		if (arr[i] > arr[max])
			max = i;
		if (arr[i] < arr[min])
			min = i;
	}
	// 申请一片内存，内存大小为最大值-最小值+1，即可能出现的每一个数分配一个内存空间
	int length = arr[max] - arr[min] + 1;
	int* bucket = new int[length]();  // 申请一片内存空间
	// 新数组存储的数表示这个下标对应的数出现的个数，下标+最小值即为这个数的大小
	for (int i = 0 ,temp = 0; i < len; ++i)
	{
		temp = arr[i] - arr[min];  // 求出新数组的下标
		bucket[temp] += 1;  // 计数+1
	}
	min = arr[min];  // 记录最小值
	// 将新数组内的值覆盖原来的数组
	for (int i = 0, j = 0; i < length; ++i)
	{
		while (bucket[i]>0)  // 当bucket[i]不为0时，即bucket[i]表示的值出现了bucket[i]次
		{
			arr[j] = i + min;  // 读取这个数，并覆盖原来的数组
			j += 1;
			bucket[i] -= 1;  // 读取一个-1
		}
	}
	delete[] bucket;  // 释放分配的内存空间
}
/************函数说明***********
* 函数名：void BucketSort(int* arr, int len)
* 函数参数：待排序数组，数组长度
* 函数返回值：数组指针隐性返回已排序的数组
* 函数功能：对输入数组进行排序
* 函数算法：桶排序：计数排序的升级版，利用了函数的映射关系。
			桶排序 (Bucket sort)的工作的原理：
			假设输入数据服从均匀分布，将数据分到有限数量的桶里，每个桶再分别排序（有可能再使用别的排序算法或是以递归方式继续使用桶排序进行排）。
			1、设置一个定量的数组当作空桶；
			2、遍历输入数据，并且把数据一个一个放到对应的桶里去；（函数中采用vector表示桶）
			3、对每个不是空的桶进行排序；（函数中采用归并排序）
			4、从不是空的桶里把排好序的数据拼接起来。
* 改进之处：申请空间为最大值到最小值之间每一个固定区域申请空间，尽量减少了元素值大小不连续情况下的空间浪费现象
* 算法关键：
		1、元素值域的划分，过于宽泛演变成比较排序，过于严苛演变成计数排序
		2、排序算法的选择，对于各个桶中元素的排序，决定了复杂度和稳定性
* 数据类型：数组和vector
* 时间复杂度： O(N+N(log2N-log2M))，其中M表示桶的个数
* 空间复杂度： O(N+M)
* 稳定

*

**/

void BucketSort(int* arr, int len)
{
	int min = 0, max = 0;
	// 找到最大值和最小值
	for (int i = 0; i < len; ++i)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}

	int size = max / 10 - min / 10 + 1;  // 桶的数量
	vector<int>* bucket = new vector<int>[size]();  // 申请内存空间，由于不确定每个桶中含有多少元素，所以用vector容器
	int index = 0;
	for (int i = 0; i < len; ++i)  // 遍历数组
	{
		index = arr[i] / 10 - min / 10;  // arr[i]对应的桶索引
		bucket[index].push_back(arr[i]);
	}
	index = 0; // 索引清零
	vector <int> temp;  // 临时变量，存储归并排序后返回的数组
	for (int i = 0; i < size; ++i)  // 遍历桶
	{
		if (!bucket[i].empty())  // 如果桶内有元素的话
		{
			temp = MergeSort(bucket[i], 0, bucket[i].size() - 1);  // 归并排序
			for (int j = 0; j <temp.size() && index < len; ++j)
			{
				arr[index] = temp[j];  // 将排序完成的值覆盖掉原来的数组值
				index += 1;
			}
		}
	}
	delete[] bucket;  // 释放内存空间
}

/************函数说明***********
* 函数名：void RadixSort(int* arr, int len)
* 函数参数：待排序数组，数组长度
* 函数返回值：数组指针隐性返回已排序的数组
* 函数功能：对输入数组进行排序
* 函数算法：基数排序：按照低位先排序，然后收集；再按照高位排序，然后再收集；依次类推，直到最高位。最后的次序就是高优先级高的在前，高优先级相同的低优先级高的在前。
			1、取得数组中的最大数，并取得位数；
			2、arr为原始数组，从最低位开始取每个位组成radix数组；
			3、对radix进行计数排序（利用计数排序适用于小范围数的特点）；

* 数据类型：
* 时间复杂度：
* 空间复杂度：
* 稳定

* 注意：仅支持整数

**/
void RadixSort(int* arr, int len)
{
	int count = 1;  // 记录位数,最小一位数
	int  max = 0;
	// 找到最大值
	try 
	{
		for (int i = 0; i < len; ++i)
		{
			if (arr[i] > max)
				max = arr[i];
			if (arr[i] < 0)
				throw "the input of RadixSort() must be positive integer!!!";
		}
	
		// 求最大值的位数
		while (max / 10)
		{
			count += 1;
			max = max / 10;
		}

		int temp = 0;  // 临时变量，记录当前排序的位数，从最低位开始直到最高位
		while (temp < count)
		{
			vector<int>* bucket = new vector<int>[10]();  // 申请一片内存空间
			// 对该位数进行计数排序
			for (int i = 0; i < len; ++i)  // 遍历数组
			{
				int index = (arr[i] / int(pow(10, temp))) % 10;
				bucket[index].push_back(arr[i]);  // 将对应索引的值存入桶中

			}
			int index = 0;
			// 将桶中的数取出来覆盖原来的数组
			for (int i = 0; i < 10; ++i)
			{
				for (int j = 0; j < bucket[i].size(); ++j)
				{
					arr[index] = bucket[i][j];
					index += 1;
				}
			}
			delete[] bucket;  // 释放内存空间
			temp += 1;  // 下一位数
		}
	}
	catch (const char* e)
	{
		cerr << e << endl;
	}
	catch (...)
	{
		cerr << "other error." << endl;
	}	
	
}



