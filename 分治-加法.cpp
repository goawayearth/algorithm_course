#include<stdio.h>
#include<cstdlib>
#define MAXSIZE 100000

/*
分治法、递归法求加法
*/

int RecursiveSum(int numbers[], int i, int j)
{
	if (i == j)return numbers[i];
	return RecursiveSum(numbers, i, (i + j) / 2)
		+ RecursiveSum(numbers, (i + j) / 2 + 1, j);
}





int main()
{
	int numbers[MAXSIZE];
	int num = (int)(rand() % 10000);
	for (int i = 0; i < num; i++)
	{
		numbers[i] = (int)(rand() % 10000);
	}
	int n = RecursiveSum(numbers, 0, num-1);
	printf("%d\n",n);
}

