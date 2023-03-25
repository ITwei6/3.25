#include <stdio.h>
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void AdjustDown(int* a, int n, int parent)//ʵ�ֵ�ǰ���������������Ƕ�
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//ѡ�����Һ����бȽϴ�ĺ��ӣ�����childΪ��ߣ�������ߺ��ӱȽϴ�
		if (child + 1 < n && a[child] < a[child + 1])//�����������Խ��ķ��գ����ܱ�֤�ұߵĺ���һ������
		{//�ұߵĺ���Ҫ���ڵĻ�Ҳ��ҪС��n�ſ������������ټ���ȥ
			++child;//���ұߵĺ��ӳ�Ϊ�Ƚϴ��child
		}
		//Ȼ���ø������ף���ϴ���ӱȽϣ������Ǵ�ѣ�����Ҫ���ڶ��ӵ�
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			//���������parent��������λ����ȥ�����Ӽ���������
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}


	}
}
void AdjustUp(int* a, int child)//���ϵ�����ǰ�����child֮ǰ�����Ƕ�
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
	for (int i = 1; i <10; i++)//ģ����뽨�ѣ�ʱ�临�Ӷ�ΪN*logN
	{
		AdjustUp(a, i);
	}
}
int main()
{
	int a[10] = { 9,5,2,3,6,7,8,4,1,0 };
	
	//ֱ��ʹ���������ģ�⽨��
	//�������һ��Ԫ�ص����Ѷ�Ԫ�أ��������Ԫ�ؽ������ϵ�������
	HeapSort(a, 10);
	return 0;
}