#include<stdio.h>
/*
x*y = 2*x*(y/2)如果y是偶数
x*y = X+2*x*(y/2)如果y是奇数
本质是一个数不断除以二，另一个不断乘以2的过程
递归实现
*/
int multiply(int x, int y)
{
	int result;
	if (y == 0)return 0;
	if (y % 2 == 0)
	{
		return 2*multiply(x, y / 2);
	}
	else
	{
		return x + 2 * multiply(x, y / 2);
	}
}

int main()
{
	int a,b;
	printf("请输入两个乘数：");
	scanf("%d %d", &a, &b);
	printf("%d", multiply(a, b));
}