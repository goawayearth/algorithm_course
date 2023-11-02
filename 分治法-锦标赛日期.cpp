#include<iostream>
using namespace std;

#define N 10000

int TS[N][N];

void copy(int j,int size)//j是开始的列,size只能是2的倍数
{
  //比如j=0; size=4


      for(int q=j;q<j+size/2;q++)
	{
	  for(int k=0;k<size/2;k++)
	    {
	        TS[k+size/2][q+size/2]=TS[k][q];
	    }
	}
      for(int k=j+size/2;k<j+size;k++)
	{
	  for(int q=0;q<size/2;q++)
	    {
	       TS[q+size/2][k-size/2]=TS[q][k];
	    }
	}
}

void TSC(int size)//k=8
{

  for(int i=0;i<size;i++)
    {
      TS[0][i]=i+1;
    }

  for(int i=2;i<=size;i=i*2)
    {
       for(int j=0;j<size;j+=i)
      	{
	  cout<<j<<" "<<i<<endl;
	   copy(j,i);
      }
    }
}

int main()
{
  int size;
  cout<<"请输入size:";
  cin>>size;
  TSC(size);

  
  for(int i=0;i<size;i++)
    {
      for(int j=0;j<size;j++)
	{
	  cout<<TS[i][j]<<" ";
	}
      cout<<endl;
    }
}
