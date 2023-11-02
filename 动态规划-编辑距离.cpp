#include<iostream>
using namespace std;
#define N 1000
int matrix[N][N];
string str1,str2;

int EditDistance1(int l1,int l2)
{
  for(int i=0;i<l1+1;i++)
    {
      matrix[i][0]=i;
    }
  for(int i=0;i<l2+1;i++)
    {
      matrix[0][i]=i;
    }
  for(int i=1;i<l1+1;i++)
    {
      for(int j=1;j<l2+1;j++)
	{
	  int _c=matrix[i][j-1]+1;
	  int c_=matrix[i-1][j]+1;
	  int cc=matrix[i-1][j-1];
	  if(str1[i-1]!=str2[j-1])
	    {
	      cc+=1;
	    }
	  int max=_c;
	  if(c_<max)max=c_;
	  if(cc<max)max=cc;
	  matrix[i][j]=max;
	    
	}
    }
  return matrix[l1][l2];
}




int main()
{
  int l1,l2;//两个字符串的大小
 
  cout<<"请输入两个字符串的大小：";
  cin>>l1>>l2;
  cout<<"请输入两个字符串";
  cin>>str1>>str2;
  cout<<str1<<endl;
  cout<<str2<<endl;
  cout<<"最短距离是：";
  cout<<EditDistance1(l1,l2)<<endl;
  for(int i=0;i<l1+1;i++)
    {
      for(int j=0;j<l2+1;j++)
	{
	  cout<<matrix[i][j]<<"\t" ;
	}
      cout<<endl;
    }
}
