#include<iostream>
using namespace std;
#define N 1000

typedef struct path
{
  int V;
  int length;
}Path;

typedef struct V1
{
  int color;
  string name;
  int pre;
}V1;

V1 ve[N];//这个将i与点的名称和颜色统一了起来

int V_Num;

int matrix[N][N];//图的邻接矩阵

int PATH[N];//临时路径

int pathPosi=0;//最终路径

int finalNum;

int max1=0;//最大路径值

int finalPath[N];//最后的结果

int dilg(int U)
{
 
    Path lengths[N];
    int p=0;
    int flag=0;
    for(int i=0;i<V_Num;i++)//寻找入度的点，而且是没有遍历过的
    {
      
        if(matrix[i][U]>0&&ve[i].color==0)
        {
        
            flag=1;//找到了入度
            ve[i].color=1;//标记颜色
            int leng=dilg(i)+matrix[i][U];
            ve[i].color=0;
            lengths[p].length=leng;
            lengths[p].V=i;
            p++;
        }
    }
    if(flag==0)
      {
          return 0;
      }

  //寻找最大值
  Path fina=lengths[0];
  for(int i=0;i<p;i++)
    {
      if(lengths[i].length>fina.length)
      {
        fina=lengths[i];
      } 
    }
  //寻找最大值结束

  ve[fina.V].color=1;
  ve[U].pre=fina.V;
  
  return fina.length;
}

void getLongestPath(int v)
{
  
  for(int i=0;i<v;i++)//每个顶点都作为结尾顶点，轮一遍，找最大的
    {
      for(int i=0;i<v;i++)ve[i].color=0;
      ve[i].color=1;
      int length=dilg(i);//从i开始的最长的路径
     
      if(length>max1)
	{
	  max1=length;
	  finalNum=i;
	}
    }
}

int main()
{
  cout<<"请输入图的顶点个数：";
  cin>>V_Num;
  int v=V_Num;
  cout<<"请输入顶点名称：";
  for(int i=0;i<V_Num;i++)
    {
      cin>>ve[i].name;
      ve[i].color=0;
    }
  cout<<"请输入邻接矩阵：";
  for(int i=0;i<v;i++)//输入邻接矩阵
    for(int j=0;j<v;j++)//正数是边，0或者-1代表没有边
      {
	cin>>matrix[i][j];
      }
  
  for(int i=0;i<v;i++)
    {
      ve[i].pre=-1;
    }
  
  getLongestPath(v);
  
  cout<<"最长路径是："<<max1<<endl;
  PATH[pathPosi]=finalNum;
  pathPosi++;
  for(int i=finalNum;ve[i].pre!=-1;i=ve[i].pre)
    {
      PATH[pathPosi]=ve[i].pre;
      pathPosi++;
    }
  for(int i=pathPosi-1;i>0;i--)
    {
      cout<<ve[PATH[i]].name<<"->";
    }
  cout<<ve[PATH[0]].name<<endl;
}
