#include<stdio.h>
#include<cstdlib>		
/*
快速排序，递归算法，分治思想
*/
#define MAXSIZE 100000
void Quick_Sort(int *arr, int begin, int end) {
	if (begin > end)
		return;
	int tmp = arr[begin];
	int i = begin;
	int j = end;
	while (i != j) 
	{
		while (arr[j] >= tmp && j > i)
			j--;
		while (arr[i] <= tmp && j > i)
			i++;
		if (j > i) 
		{
			int t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}
	arr[begin] = arr[i];
	arr[i] = tmp;
	Quick_Sort(arr, begin, i - 1);
	Quick_Sort(arr, i + 1, end);
}

int main()
{
	int arrayToSort[MAXSIZE];
	int num = (int)(rand()%10000);
	for(int i=0;i<num;i++)arrayToSort[i]= (int)(rand() % 10000);
	Quick_Sort(arrayToSort, 0, num-1);
	for (int i = 0; i < num; i++)
	{
		printf("%d\n", arrayToSort[i]);
	}
}