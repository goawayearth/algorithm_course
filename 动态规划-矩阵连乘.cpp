#include<iostream>
using namespace std;
#define N 1000
typedef struct
{
  int row;
  int col;
}MatStruct;

int matrix_num;//矩阵的数量
MatStruct Mat[N];//存储矩阵的宽和高

int Dpmatrixmul(int start,int end)
{
  if(start==end)
    {
      return 0;
    }
  int result[N];
  int p=0;


  for(int k=start;k<end;k++)
    {
      result[p]=Dpmatrixmul(start,k)+Dpmatrixmul(k+1,end)+Mat[start].row * Mat[k].col * Mat[end].col;
      p++;
    }

  //找最小值
  int min=result[0];
  for(int i=0;i<p;i++)
    {
      if(result[i]<min)
	{
	  min=result[i];
	}
    }
  return min;
  
  
}







int main()
{
  cout<<"请输入矩阵的数量：";
  cin>>matrix_num;

  cout<<"请输入每个矩阵的大小:";
  for(int i=0;i<matrix_num;i++)
    {
      cin>>Mat[i].row;
      cin>>Mat[i].col;
    }

  cout<<"最小是："<< Dpmatrixmul(0,matrix_num-1)<<endl;

  
}
