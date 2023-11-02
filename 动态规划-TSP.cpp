#include<iostream>
using namespace std;
const int max_ = 0x3f3f3f;   //定义一个最大值
const int NoEdge = -1;      //两个点之间没有边
int citynum;                //城市数
int edgenum;                //边数
int currentcost;            //记录当前的路程
int bestcost;               //记录最小的路程(最优)
int Graph[100][100];        //图的边距记录
int x[100];                 //记录行走顺序
int bestx[100];             //记录最优行走顺序

void InPut()
{
    int pos1, pos2, len;     //点1 点2 距离

    cout << "请输入城市数和边数(c e)：";
    cin >> citynum >> edgenum;

    memset(Graph, NoEdge, sizeof(Graph));

    cout << "请输入两座城市之间的距离(p1 p2 l)：" << endl;
    for (int i = 1; i <= edgenum; ++i)
    {
        cin >> pos1 >> pos2 >> len;
        Graph[pos1][pos2] = Graph[pos2][pos1] = len;
    }
}

//初始化
void Initilize()
{
    currentcost = 0;
    bestcost = max_;
    for (int i = 1; i <= citynum; ++i)
    {
        x[i] = i;
    }
}


void Swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}


void BackTrack(int i) //这里的i代表第i步去的城市而不是代号为i的城市
{
    if (i == citynum)
    {
        if (Graph[x[i - 1]][x[i]] != NoEdge && Graph[x[i]][x[1]] != NoEdge && (currentcost + Graph[x[i - 1]][x[i]] + Graph[x[i]][x[1]] < bestcost || bestcost == max_))
        {
            bestcost = currentcost + Graph[x[i - 1]][x[i]] + Graph[x[i]][x[1]];
            for (int j = 1; j <= citynum; ++j)
                bestx[j] = x[j];
        }
    }
    else
    {
        for (int j = i; j <= citynum; ++j)
        {
            if (Graph[x[i - 1]][x[j]] != NoEdge && (currentcost + Graph[x[i - 1]][x[j]] < bestcost || bestcost == max_))
            {
                Swap(x[i], x[j]);  //这里i 和 j的位置交换了, 所以下面的是currentcost += Graph[x[i - 1]][x[i]];
                currentcost += Graph[x[i - 1]][x[i]];
                BackTrack(i + 1);   //递归进入下一个城市
                currentcost -= Graph[x[i - 1]][x[i]];
                Swap(x[i], x[j]);
            }
        }
    }
}

void OutPut()
{
    cout << "最短路程为：" << bestcost << endl;
    cout << "路线为:" << endl;
    for (int i = 1; i <= citynum; ++i)
        cout << bestx[i] << " ";
    cout << "1" << endl;
}


int main()
{
    InPut();
    Initilize();
    BackTrack(2);
    OutPut();
}

