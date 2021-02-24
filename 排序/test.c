#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"


int main()
{
	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	int n = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, 0, n);
	PrintArray(arr, 0, n);
	return 0;
}