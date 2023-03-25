#include <stdio.h>
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void AdjustDown(int* a, int n, int parent)//实现的前提是左右子树都是堆
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//选出左右孩子中比较大的孩子，假设child为左边，假设左边孩子比较大
		if (child + 1 < n && a[child] < a[child + 1])//不过这里存在越界的风险，不能保证右边的孩子一定存在
		{//右边的孩子要存在的话也需要小于n才可以所以我们再加上去
			++child;//让右边的孩子成为比较大的child
		}
		//然后让根（父亲）与较大儿子比较，这里是大堆，父亲要大于儿子的
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			//交互完后，让parent跳到儿子位置上去，儿子继续往下找
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}


	}
}
void AdjustUp(int* a, int child)//向上调整的前提就是child之前的数是堆
{

	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}

}
void HeapSort(int* a, int n)
{
	for (int i = 1; i <10; i++)//模拟插入建堆，时间复杂度为N*logN
	{
		AdjustUp(a, i);
	}
}
int main()
{
	int a[10] = { 9,5,2,3,6,7,8,4,1,0 };
	
	//直接使用数组进行模拟建堆
	//将数组第一个元素当作堆顶元素，而后面的元素进行向上调整操作
	HeapSort(a, 10);
	return 0;
}