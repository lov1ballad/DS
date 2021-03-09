#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"

void Swap(int* a, int* b)//交换
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void PrintArray(int* ar, int left, int right)
{
	for (int i = left; i < right; ++i)
		printf("%d ", ar[i]);
	printf("\n");
}

void InsertSort_1(int* ar, int left, int right)
{
	for (int i = left + 1; i < right; ++i)
	{
		int k = left;
		while (ar[i] > ar[k])
			k++;
		int tmp = ar[i];
		for (int j = i; j > k; --j)
			ar[j] = ar[j - 1];
		ar[k] = tmp;
	}
}

void InsertSort_2(int* ar, int left, int right)
{
	for (int i = left; i < right; ++i)
	{
		int j = i;
		while (j > left && ar[j] < ar[j - 1])
		{
			Swap(&ar[j], &ar[j - 1]);
			j--;
		}
	}
}

void InsertSort_3(int* ar, int left, int right)
{
	for (int i = left; i < right; ++i)
	{
		int j = i;
		int tmp = ar[j];
		while (j > left && tmp < ar[j - 1])
		{
			ar[j] = ar[j - 1];
			j--;
		}
		ar[j] = tmp;
	}
}

void InsertSort_4(int* ar, int left, int right)
{
	for (int i = left + 1; i < right; ++i)
	{
		ar[0] = ar[i];
		int j = i;
		while (ar[0] < ar[j - 1])//省略了j>left；
		{
			ar[j] = ar[j - 1];
			j--;
		}
		ar[j] = ar[0];
	}
}

void BinInsertSort(int* ar, int left, int right)
{
	for (int i = left + 1; i < right; ++i)
	{
		int tmp = ar[i];
		int low = left;
		int high = i - 1;
		int mid;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (tmp >= ar[mid])
				low = mid + 1;
			if (tmp < ar[mid])
				high = mid - 1;

		}
		for (int j = i; j>low; --j)
		{
			ar[j] = ar[j - 1];
		}
		ar[low] = tmp;


	}
}

void TwoWayInsertSort(int* ar, int left, int right)
{
	int n = right - left;
	int* tmp = (int *)malloc(sizeof(int)* n);

	tmp[0] = ar[left];
	int first, final;
	first = final = 0;

	for (int i = left + 1; i < right; i++)
	{
		if (ar[i] < tmp[first])
		{
			first = (first - 1 + n) % n;
			tmp[first] = ar[i];
		}
		else if (ar[i] >= tmp[final])
		{
			tmp[++final] = ar[i];
		}
		else
		{
			int end = final;
			while (ar[i] < tmp[end])
			{
				tmp[(end + 1)%n] = tmp[end];//取模值是为了防止越界
				end = (end-1+n)%n;
			}
			tmp[(end + 1)%n] = ar[i];
			final++;
		}
	}
	int k = 0;
	for (int i = first; k < n; ++k)
	{
		ar[k] = tmp[i];
		i = (i + 1) % n;
	}
	free(tmp);
	tmp = NULL;
}

/*void _ShellInsert(int* ar, int left, int right, int gap)
{
	for (int i = left + gap; i < right; ++i)
	{
		int tmp = ar[i];
		int j = i;
		while (j>left && tmp < ar[j - gap])
		{
			ar[j] = ar[j - gap];
			j -= gap;
		}
		ar[j] = tmp;
	}
}

int dlta[] = { 5, 3, 2, 1 }; //给定增量

void ShellSort(int* ar, int left, int right)
{
	int n = sizeof(dlta) / sizeof(dlta[0]);//增量个数为排序次数
	for (int i = 0; i < n; ++i)
	{
		_ShellInsert(ar, left, right, dlta[i]);
	}
}*/

void ShellSort(int* ar, int left, int right)
{
	int gap = right - left;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = left + gap; i < right; ++i)
		{
			if (ar[i] < ar[i - gap])
			{
				int tmp = ar[i];
				int j = i;
				while (j>left && tmp < ar[j - gap])
				{
					ar[j] = ar[j - gap];
					j -= gap;
				}
				ar[j] = tmp;
			}
		}
	}
}

int GetMinIndex(int* ar, int left, int right)
{
	int min_value = ar[left];
	int index = left;

	for (int i = left + 1; i < right; ++i)
	{
		if (ar[i] < min_value)
		{
			min_value = ar[i];
			index = i;
		}
	}
	return index;
}

void SelectSort(int* ar, int left, int right)
{
	for (int i = left; i < right - 1; ++i)
	{
		int index = GetMinIndex(ar, i, right);
		if (index != i)
			Swap(&ar[i], &ar[index]);
	}
}

void AdjustDown(int* ar, int left, int right, int start)//赋值法
{
	int n = right - left;
	int i = start;
	int  j = 2*i + 1;

	int tmp = ar[i];
	while (j < n)
	{
		if (j + 1 < n && ar[j] < ar[j + 1])//右树存在且左树大于右数
			j = j + 1;
		if (tmp < ar[j])
		{
			ar[i] = ar[j];//满足条件向上赋值

			i = j;
			j = i * 2 + 1;
		}
		else
			break;
	}
	ar[i] = tmp;
}

void HeapSort(int* ar, int left, int right)
{
	int n = right - left;
	int curpos = n / 2 - 1 + left;//找到最后一个分支
	while (curpos >= 0)
	{
		AdjustDown(ar, left, right, curpos);
		curpos--;
	}

	//将顶与低交换
	int end = right - 1;
	while (end > left)
	{
		Swap(&ar[left], &ar[end]);//出堆
		AdjustDown(ar, left, end, 0);
		end--;
	}
}

void BubbleSort(int* ar, int left, int right)
{
	for (int i = left; i < right - left - 1; ++i)
	{
		for (int j = left; j < right - left - 1 - i; ++j)
		{
			if (ar[j] > ar[j + 1])
			{
				Swap(&ar[j], &ar[j + 1]);
			}
		}
	}
}

void BubbleSort_1(int* ar, int left, int right)
{
	bool flag = false;
	for (int i = left; i < right - left - 1; ++i)
	{
		for (int j = left; j < right - left - 1 - i; ++j)
		{
			if (ar[j] > ar[j + 1])
			{
				Swap(&ar[j], &ar[j + 1]);
				flag = true;
			}
		}
		if (!flag)
			break;
		else
			flag = false;
	}
}

int _Partition_1(int* ar, int left, int right)//hoare法
{
	int low = left, high = right - 1;
	int key = ar[low];
	while (low < high)
	{
		while (low < high && ar[high] > key)
			high--;
		Swap(&ar[low], &ar[high]);
		while (low < high && ar[low] <= key)
			low++;
		Swap(&ar[low], &ar[high]);
	}
	return low;
}

int _Partition_2(int* ar, int left, int right)//挖坑法
{
	int low = left, high = right - 1;
	int key = ar[low];
	while (low < high)
	{
		while (low < high && ar[high] > key)
			high--;
		ar[low] = ar[high];
		while (low < high && ar[low] <= key)
			low++;
		ar[high] = ar[low];
	}
	ar[low] = key;
	return low;
}

int _Partition_3(int* ar, int left, int right)//前后指针法
{
	int key = ar[left];
	int pos = left;
	for (int i = pos + 1; i < right; ++i)
	{
		if (ar[i] < key)
		{
			pos++;
			if (pos != i)
			{
				Swap(&ar[pos], &ar[i]);
			}
		}
	}
	Swap(&ar[left], &ar[pos]);
	return pos;
}

void QuickSort(int* ar, int left, int right)
{
	if (left >= right)
		return;
	int pos = _Partition_3(ar, left, right);
	QuickSort(ar, left, pos);//左子序列
	QuickSort(ar, pos + 1, right);//右子序列
}
///////////////优化
#define M 5

int GetMidIndex(int* ar, int left, int right)
{
	int mid = (left + right - 1) / 2;

	if (ar[left] < ar[mid] && ar[mid] < ar[right - 1])
		return mid;
	if (ar[left]>ar[mid] && ar[left] < ar[right - 1])
		return left;
	return right - 1;
}

int _Partition_4(int* ar, int left, int right)//前后指针法
{
	int mid_index = GetMidIndex(ar, left, right);
	if (mid_index != left)
		Swap(&ar[left], &ar[mid_index]);
	int key = ar[left];
	int pos = left;
	for (int i = pos + 1; i < right; ++i)
	{
		if (ar[i] < key)
		{
			pos++;
			if (pos != i)
			{
				Swap(&ar[pos], &ar[i]);
			}
		}
	}
	Swap(&ar[left], &ar[pos]);
	return pos;
}

void QuickSort_1(int* ar, int left, int right)
{
	if (left >= right)
		return;
	if (right - left < M)
	{
		InsertSort_4(ar, left, right);
	}
	else
	{
		int pos = _Partition_3(ar, left, right);
		QuickSort(ar, left, pos);//左子序列
		QuickSort(ar, pos + 1, right);//右子序列
	}
}
void _MergeSort(int* ar, int left, int right,int* tmp)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	_MergeSort(ar, left, mid, tmp);//分解左边分支
	_MergeSort(ar, mid + 1, right, tmp);//分解右边分支

	////归并
	int begin1, end1, begin2, end2;
	begin1 = left, end1 = mid;
	begin2 = mid + 1, end2 = right;
	int k = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (ar[begin1] < ar[begin2])
			tmp[k++] = ar[begin1++];
		else
			tmp[k++] = ar[begin2++];
	}
	while (begin1 <= end1)
		tmp[k++] = ar[begin1++];
	while (begin2 <= end2)
		tmp[k++] = ar[begin2++];

	memcpy(ar + left, tmp + left, sizeof(int)* (right - left + 1));

}

void MergeSort(int* ar, int left, int right)
{
	int n = right - left;
	int * tmp = (int*)malloc(sizeof(int)* n);

	_MergeSort(ar, left, right-1,tmp);

	free(tmp);
}
#include"SList.h"//需要用来构造基数
#define K 2 //三位数
#define RADIX 10 //10个基数
SList list[RADIX];
int GetKey(int value, int k)
{
	int key;
	while (k >= 0)
	{
		key = value % 10;
		value /= 10;
		k--;
	}
	return key;
}

void Distribute(int* ar, int left, int right, int k)
{
	for (int i = left; i < right; ++i)
	{
		int key = GetKey(ar[i], k);
		SListPushBack(&list[key], ar[i]);//放入数据
	}
}

void Collect(int* ar)
{
	int k = 0;
	for (int i = 0; i < RADIX; ++i)
	{
		SListNode* p = list[i].head;
		while (p != NULL)
		{
			ar[k++] = p->data;
			p = p->next;
		}
	}
	for (int i = 0; i < RADIX; ++i)//清除链表
		SListClear(&list[i]);
}

void RadixSort(int* ar, int left, int right)
{
	for (int i = 0; i < RADIX; ++i)
		SListInit(&list[i]);
	for (int i = 0; i < K; ++i)
	{
		//分发
		Distribute(ar, left, right, i);

		//回收
		Collect(ar);
	}

}

void TestSortEfficient()
{
	int n = 20000;
	int* a = (int*)malloc(sizeof(int)*n);
	int* a1 = (int*)malloc(sizeof(int)*n);
	int* a2 = (int*)malloc(sizeof(int)*n);
	int* a3 = (int*)malloc(sizeof(int)*n);
	int* a4 = (int*)malloc(sizeof(int)*n);
	int* a5 = (int*)malloc(sizeof(int)*n);
	int* a6 = (int*)malloc(sizeof(int)*n);
	int* a7 = (int*)malloc(sizeof(int)*n);
	int* a8 = (int*)malloc(sizeof(int)*n);
	int* a9 = (int*)malloc(sizeof(int)*n);
	int* a10 = (int*)malloc(sizeof(int)*n);
	int* a11 = (int*)malloc(sizeof(int)*n);
	int* a12 = (int*)malloc(sizeof(int)*n);
	int* a13 = (int*)malloc(sizeof(int)*n);
	int* a14 = (int*)malloc(sizeof(int)*n);
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand();
		a1[i] = a[i];
		a2[i] = a[i];
		a3[i] = a[i];
		a4[i] = a[i];
		a5[i] = a[i];
		a6[i] = a[i];
		a7[i] = a[i];
		a8[i] = a[i];
		a9[i] = a[i];
		a10[i] = a[i];
		a11[i] = a[i];
		a12[i] = a[i];
		a13[i] = a[i];
		a14[i] = a[i];
	}
	time_t start = clock();
	InsertSort_1(a, 0, n);
	time_t end = clock();
	printf("InsertSort_1 time = %u\n", end - start);

	start = clock();
	InsertSort_2(a1, 0, n);
	end = clock();
	printf("InsertSort_2 time = %u\n", end - start);

	start = clock();
	InsertSort_3(a2, 0, n);
	end = clock();
	printf("InsertSort_3 time = %u\n", end - start);

	start = clock();
	InsertSort_4(a3, 0, n);
	end = clock();
	printf("InsertSort_4 time = %u\n", end - start);

	start = clock();
	BinInsertSort(a4, 0, n);
	end = clock();
	printf("BinInsertSort time = %u\n", end - start);

	start = clock();
	TwoWayInsertSort(a5, 0, n);
	end = clock();
	printf("TwoWayInsertSort time = %u\n", end - start);

	start = clock();
	ShellSort(a6, 0, n);
	end = clock();
	printf("ShellSort time = %u\n", end - start);

	start = clock();
	SelectSort(a7, 0, n);
	end = clock();
	printf("SelectSort time = %u\n", end - start);

	start = clock();
	HeapSort(a8, 0, n);
	end = clock();
	printf("HeapSort time = %u\n", end - start);

	start = clock();
	BubbleSort(a9, 0, n);
	end = clock();
	printf("BubbleSort time = %u\n", end - start);

	start = clock();
	BubbleSort_1(a10, 0, n);
	end = clock();
	printf("BubbleSort_1 time = %u\n", end - start);

	start = clock();
	QuickSort(a11, 0, n);
	end = clock();
	printf("QuickSort time = %u\n", end - start);

	start = clock();
	QuickSort_1(a12, 0, n);
	end = clock();
	printf("QuickSort_1 time = %u\n", end - start);

	start = clock();
	MergeSort(a13, 0, n);
	end = clock();
	printf("MergeSort time = %u\n", end - start);

	start = clock();
	RadixSort(a14, 0, n);
	end = clock();
	printf("RadixSort time = %u\n", end - start);
}
