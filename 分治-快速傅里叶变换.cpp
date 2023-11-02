#include <iostream>
#include <cmath>
#include<complex>

#define PI acos(-1)
using namespace std;

typedef complex<double> cd;


cd* FFT(cd* value,int num)
{
  cd* y=(cd*)malloc(1000*sizeof(cd));
  if(num==1)
    {
      return value;
    }
  cd  w(cos(2*PI/num),sin(2*PI/num));
 
  cd* Pe=(cd*)malloc(1000*sizeof(cd));int e_num=0;
  cd* P0=(cd*)malloc(1000*sizeof(cd));int o_num=0;

  for(int i=0;i<num;i+=2)
    {
	  Pe[e_num]=value[i];
	  e_num++;

	  P0[o_num]=value[i+1];
	  o_num++;

    }

  cd* ye=(cd*)malloc(1000*sizeof(cd));
  cd* y0=(cd*)malloc(1000*sizeof(cd));
  ye=FFT(Pe,e_num);
  y0=FFT(P0,o_num);

 

  for(int i=0;i<num/2;i++)
    {
      cd w1=w;
      int n=i;
      if(n==0)
	{
	  w1=w1/w1;
	}
      else
	{
	  n--;
	   while(n--)
	     {
	       w1*=w1;
	     }
	}
     
      y[i]=w1*y0[i]+ye[i];
      y[i+num/2]=ye[i]-(w1*y0[i]);
    }
  return y;
}


cd* IFFT(cd* value,int num)
{
  cd* y=(cd*)malloc(1000*sizeof(cd));
  if(num==1)
    {
      return value;
    }
  cd  w(cos(2*PI/num),-sin(2*PI/num));
 
  cd* Pe=(cd*)malloc(1000*sizeof(cd));int e_num=0;
  cd* P0=(cd*)malloc(1000*sizeof(cd));int o_num=0;

  for(int i=0;i<num;i+=2)
    {
	  Pe[e_num]=value[i];
	  e_num++;

	  P0[o_num]=value[i+1];
	  o_num++;
    }

  cd* ye=(cd*)malloc(1000*sizeof(cd));
  cd* y0=(cd*)malloc(1000*sizeof(cd));
  ye=IFFT(Pe,e_num);
  y0=IFFT(P0,o_num);

  for(int i=0;i<num/2;i++)
    {
      cd w1=w;
      int n=i;
      if(n==0)
	{
	  w1=w1/w1;
	}
      else
	{
	  n--;
	   while(n--)
	     {
	       w1*=w1;
	     }
	}
     
      y[i]=w1*y0[i]+ye[i];
      y[i+num/2]=ye[i]-(w1*y0[i]);
    }
  return y;
}




int main()
{  
  cout<<"输入num(num是2的倍数)：";
  int num;
  cin>>num;
  
  cd* A=(cd*)malloc(1000*sizeof(cd));
  cout<<"输入A系数：";
  for(int i=0;i<num;i++)
    {
      double temp;
      cin>>temp;
      cd tem(temp,0);
      A[i]=tem;
    }

  cd* B=(cd*)malloc(1000*sizeof(cd));
  cout<<"请输入B系数：";
  for(int i=0;i<num;i++)
    {
      double temp;
      cin>>temp;
      cd tem(temp,0);
      B[i]=tem;
    }
 
  cd* A_ret=FFT(A,num);
  cd* B_ret=FFT(B,num);
  cd* C_point=(cd*)malloc(1000*sizeof(cd));

  
  for(int i=0;i<num;i++)
    {
      C_point[i]=A_ret[i]*B_ret[i];
    }
  
   A_ret=IFFT(C_point,num);

   for(int i=0;i<num;i++)
     {
       cout<<A_ret[i].real()/num<<"  ";
     }
   cout<<endl;
 
 
  return 0;
}
