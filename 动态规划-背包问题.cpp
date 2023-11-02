#include<iostream>
#define N 100
using namespace std;

//全局变量
int item_num;
int Weight[N];
int Value[N];
int flags[N];
int TakeOut;


int MaxValue1(int take0)//返回价值
{
  int getV[N];
  int p=0;
   int flag=0;
  for(int i=0;i<item_num;i++)
    {
                int take=take0;
              
                if(Weight[i]<=take)
            {
              flag=1;
              int Val=Value[i]+MaxValue1(take-Weight[i]);
              getV[p]=Val;
              p++;
            }
     
    }
   if(!flag)
     {return 0;}
    
  int max=getV[0];
  for(int i=0;i<p;i++)
    {
      if(getV[i]>max)
	{
	  max=getV[i];
	}
    }
  return max;
}


int MaxValue2(int take0)//返回价值
{
  int getV[N];
  int p=0;
   int flag=0;
  for(int i=0;i<item_num;i++)
    {
      int take=take0;
      int temp;
      temp=Weight[i];
      if(Weight[i]<=take)
	{
	 
	
	  Weight[i]=TakeOut;//之后不可能拿他了
	 
	  flag=1;
	 
	  int Val=Value[i]+MaxValue2(take-temp);
     
	  getV[p]=Val;
	
	  p++;
	}
      Weight[i]=temp;
   
    }
   if(!flag)
     {return 0;}
  int max=getV[0];

  for(int i=0;i<p;i++)
    {
      if(getV[i]>max)
	{
	  max=getV[i];
	}
    }
  return max;
}



int main()
{
  cout<<"请输入物品数量：";
  cin>>item_num;
  cout<<"请输入每个物品的重量和价值：";
  for(int i=0;i<item_num;i++)
    {
      cin>>Weight[i]>>Value[i];
    }
  cout<<"请输入能够拿走的最大的重量：";
  cin>>TakeOut;
  cout<<"若可以重复，最多拿走的价值是："<<MaxValue1(TakeOut)<<endl;
  cout<<"若不可以重复，最多可以拿走的价值是："<<MaxValue2(TakeOut)<<endl;
  
}
