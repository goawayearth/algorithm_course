#include<iostream>
using namespace std;
int* Compare(int a[], int p, int q)
{
	int* result=(int*)malloc(2*sizeof(int));
	if (q - p <= 1)
	{
		result[0] = a[p];//max
		result[1] = a[q];
		if (a[p] < a[q])
		{
			result[0] = a[q];
			result[1] = a[p];
		}
	}
	else
	{
		int* result1, *result2;
		result1 = Compare(a, p, (p + q) / 2);
		result2 = Compare(a, (p + q) / 2+1, q);
		result[0] = (result1[0] > result2[0])? result1[0] : result2[0];
		result[1]= (result1[1] < result2[1]) ? result1[1] : result2[1];
	}

	return result;
}

int main()
{
	int a[10] = { 2,5,8,15,6,0,12,13,25,33 };
	int* re=Compare(a, 0, 9);
	cout << re[0] << endl;
	cout << re[1] << endl;
	free(re);
}
