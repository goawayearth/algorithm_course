#include<stdio.h>
#include<cmath>

int Recursive_Multiply(int x, int y)
{
	int xn=0;
	int tempx = x;
	
	while (tempx)
	{
		xn++;
		tempx /= 2;
	}
	if (xn == 1)return x * y;
	if (x == 0 || y == 0)return 0;

	//计算分解后的系数
	int pow1 = pow(2, xn / 2);
	int x1, x0, y1, y0;
	x1 = x / pow1;
	x0 = x - x1 * pow1;
	y1 = y / pow1;
	y0 = y - y1 * pow1;

	int P1, P2, P3, P4;

	P1 = Recursive_Multiply(x1, y1);
	P2 = Recursive_Multiply(x1, y0);
	P3 = Recursive_Multiply(x0, y1);
	P4 = Recursive_Multiply(x0, y0);

	return P1*pow1*pow1+(P2+P3)*pow1+P4;
}
int main()
{
	int x = 8;
	int y = 10;
	printf("%d",Recursive_Multiply(x, y));
}


