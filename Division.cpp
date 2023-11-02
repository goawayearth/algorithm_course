#include<stdio.h>

/*
求x被y除之后的商和余数
*/
int ret[2];
void divide(int x, int y)
{
	if (x == 0)
	{
		ret[0] = 0;
		ret[1] = 0;
		return;
	}
	divide(x / 2, y);
	ret[0] = 2 * ret[0];
	ret[1] = 2 * ret[1];
	if (x % 2 == 0)
	{
		ret[1]++;
	}
	if (ret[1] >= y)
	{
		ret[1] = ret[1] - y;
		ret[0]++;
	}
}

int main()
{
	int x, y;
	printf("请输入两个个数:");
	scanf("%d %d",&x, &y);
	divide(x, y);
	printf("商是%d,余数是%d", ret[0], ret[1]);
}







