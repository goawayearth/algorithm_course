#include<stdio.h>
/*
斐波那契数列，利用数组存储过程变量，避免像递归运算一样重复计算
减少了时间复杂度
*/
#define NUM 30

long Fibonacii(int n)
{
	long FiboNum[NUM];
	FiboNum[0] = 0;
	FiboNum[1] = 1;
	for (int i = 0; i < n - 2; i++)
	{
		FiboNum[i + 2] = FiboNum[i] + FiboNum[i + 1];
	}
	return FiboNum[n - 1];
}

/*
设想只用三个数的内存执行整个过程,优化第一个函数的空间复杂度
*/
long Fibonacii1(int n)
{
	long FiboNum[3];
	FiboNum[0] = 1;
	FiboNum[1] = 1;
	for (int i = 0; i < n - 2; i++)
	{
		FiboNum[2] = FiboNum[0] + FiboNum[1];
		FiboNum[0] = FiboNum[1];
		FiboNum[1] = FiboNum[2];
	}
	return FiboNum[1];
}


/*
利用矩阵计算
*/



long Matrix(int n)
{
	int matrix[2][2] = {
		{0,1},
		{1,1}
	};
	int fini[2][2] = {
		{0,1},
		{1,1}
	};
	if (n == 1)return 1;
	if (n == 2)return 1;
	n-=3;
	while (n--)
	{
		int n11 = fini[0][0] * matrix[0][0] + fini[0][1] * matrix[1][0];
		int n12 = fini[0][0] * matrix[0][1] + fini[0][1] * matrix[1][1];
		int n21 = fini[1][0] * matrix[0][0] + fini[1][1] * matrix[1][0];
		int n22 = fini[1][0] * matrix[0][1] + fini[1][1] * matrix[1][1];
		fini[0][0] = n11;
		fini[0][1] = n12;
		fini[1][0] = n21;
		fini[1][1] = n22;
	}
	return fini[1][0]+ fini[1][1];
}


int main()
{
	while (1)
	{
int n = 0;
	printf("请输入n(0--30):");
	scanf("%d",&n);
	printf("%ld\n",Fibonacii(n));
	printf("%ld\n", Fibonacii1(n));
	printf("%ld\n", Matrix(n));
	}
	
}