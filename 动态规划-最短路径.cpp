#include<iostream>
using namespace std;
#define N 1000

int V_NUM;//顶点数
string V_NAME[N];//定点名称
int matrix[N][N];
int done[N];

int PATH[N];//记录路径
int p=0;

void getPath()
{
  for(int k=0;k<V_NUM;k++)
    {
      for(int i=0;i<V_NUM;i++)
      {
        for(int j=0;j<V_NUM;j++)
          {
            int min=matrix[i][k]+matrix[k][j];
            if(min<matrix[i][j])
            {
              matrix[i][j]=min;
            }
          }
      }
     
    }
}



int main()
{
  cout<<"请输入顶点数：";
  cin>>V_NUM;

  cout<<"请输入顶点名称：";
  for(int i=0;i<V_NUM;i++)
    {
      cin>>V_NAME[i];
      done[i]=0;
    }
  cout<<"请输入矩阵:";
  for(int i=0;i<V_NUM;i++)
    {
      for(int j=0;j<V_NUM;j++)
	{
	  cin>>matrix[i][j];
	}
    }

   getPath();
   cout<<"请输入要选择的两个顶点的序号：";
   int x,y;
   cin>>x>>y;
   cout<<x<<"和"<<y<<"之间的最短距离是：";
   cout<<matrix[x][y]<<endl;
   
}

