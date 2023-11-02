/*
* 动态规划问题，不断地分解出子问题
* 将两个人的马从最慢的比，如果田忌的马慢，那就让田忌的最慢的马去和齐王的最快的马比
* 如果两人最慢的马相等，那最慢的马和最快的马比还是和最慢的马比这两种情况都要计算一下比大小
* 总之就是不断减小现存马的差距，使得同级的马占优势
*/
#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define N 100
int MAX = 1000;
int n;
int tian[N], qi[N];

//第一个参数是田忌的最慢的马，第二个是齐王最快的马
int Match(int i, int j)
{
    if (i == -1)//所有的马都比完了
        return 0;
    else
    {
        if (tian[i] > qi[j + i])//如果田忌的目前最慢的马比齐王目前最慢的马快，两者相抵，得一分 
        {
            return Match(i - 1, j) + 1;
        }
        else if (tian[i] < qi[j + i])//若没有齐王快，将其最快的马拉下水输一分
        {
            return Match(i - 1, j + 1) - 1;
        }
        else
        {//相等的时候，可以选择
            int a = Match(i - 1, j);//平局，不丢分
            int b = Match(i - 1, j + 1) + (tian[i] < qi[j] ? -1 : 0);//刚掉其最快的马，输一分来保后面赢
            return max(a, b);//两者取其大值
        }
    }
    return 0;
}
int main()
{
    cout << "请输入马的数量：";
    cin >> n;
    cout << "请输入田忌的马的速度:";
    for (int i = 0; i < n; i++)//田忌的马
        cin >> tian[i];
    cout << "请输入齐王的马的速度:";
    for (int j = 0; j < n; j++)//齐王的马
        cin >> qi[j];
    for (int i = 0; i < n; i++)  //排序,从大到小
    {
        for (int j = i; j < n; j++)
        {
            if (tian[i] < tian[j])
            {
                swap(tian[i], tian[j]);
            }
            if (qi[i] < qi[j])
            {
                swap(qi[i], qi[j]);
            }
        }
    }
    
    cout << "最多可以赢得黄金"<<Match(n - 1, 0)<<"两" << endl;
    
    return 0;
}