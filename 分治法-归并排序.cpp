#include<stdio.h>
#include<cstdlib>
/*
归并排序，分治思想，递归方法
*/
#define MAXSIZE 100000
void mergearray(int a[], int first, int mid, int last, int temp[])	//将两个有序数组合并排序 
{
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;
	while (i <= m && j <= n)
	{
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while (i <= m)
		temp[k++] = a[i++];
	while (j <= n)
		temp[k++] = a[j++];
	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}

void mergesort(int a[], int first, int last, int temp[])	//将两个任意数组合并排序 
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(a, first, mid, temp);	//左边有序 
		mergesort(a, mid + 1, last, temp);	//右边有序 
		mergearray(a, first, mid, last, temp);	//再将两个有序数组合并 
	}
}

int main()
{
	int a[MAXSIZE];
	int num = (int)(rand() % 100000);
	int temp[MAXSIZE];

	for (int i = 0; i < num; i++)
		a[i]= (int)(rand() % 100000);
	mergesort(a, 0, num - 1, temp);
	for (int i = 0; i < num; i++)
		printf("%d\n", a[i]);
}