#include<iostream>
using namespace std;

#define N 10000

int matrix[N][N];

void getCoefficient(int k)
{
    //初始化第一列和对角线
      for(int i=0;i<=k;i++)
      {
          matrix[i][0]=1;
          matrix[i][i]=1;
      }
  for(int i=1;i<=k;i++)//第几行就做几次加法
    {
      int n=i;
      int start=0;
      while(n--)
	{
	  matrix[i+1][start+1] =  matrix[i][start]+matrix[i][start+1];
	  start++;
	}
    }
}

int main()
{
    cout<<"请输入二项式指数：";
    int k;
    cin>>k;
    getCoefficient(k);
    for(int i=0;i<=k;i++)
    {
        cout<<matrix[k][i]<<" ";
    }
}
