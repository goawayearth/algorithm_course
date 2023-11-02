#include<iostream>
#include<cmath>
using namespace std;
#define SIZE 1000
#define INFI 1000

int getNum(int start, int end);

typedef struct Node//点坐标
{
	double x;
	double y;

}Node;

typedef struct PairPoint//返回值专用，返回两个点和距离
{
	double x1, x2, y1, y2,far;
}PairP;



PairP getCloest(Node* points,int start, int end)//start 和end是下标
{
	PairP pair;
	pair.far= INFI;
	//end==start的时候不作为
	//两个元素的时候
	if (start == end)return pair;
	if (end - start == 1)
	{
		double temp = (points[start].x - points[end].x)*(points[start].x - points[end].x)
			+ (points[start].y - points[end].y)*(points[start].y - points[end].y);
		pair.far = pow(temp, 0.5);
		pair.x1 = points[start].x;
		pair.y1 = points[start].y;
		pair.x2 = points[end].x;
		pair.y2 = points[end].y;
		//cout << "%%" << far;
		return pair;
	}
	else if (end - start > 1)//说明至少有三个元素
	{
		PairP P1, P2;
		double sst = points[start].x;
		double eed = points[end].x;
		double divide = (sst + eed) / 2;
		Node points1[SIZE]; int p1 = -1;
		Node points2[SIZE]; int p2 = -1;
		for (int i = start; i <= end; i++)//分成两个数组
		{
			if (points[i].x <= divide)
			{
				points1[++p1] = points[i];
			}
			else
			{
				points2[++p2] = points[i];
			}
		}
		P1=getCloest(points1, 0, p1);
		P2=getCloest(points2, 0, p2);
		pair = P1.far < P2.far ? P1 : P2;//将两边最小的长度和两个点的坐标都返回了
		double leftFlag = divide - pair.far;//left和divide之间的点要重新计算
		for (int i = 0; i <= p1; i++)//左边数组找
		{
			if (points1[i].x > leftFlag && points1[i].x <= divide)//点在左界内
			{
				double top = points[i].y + pair.far;
				double bottom = points[i].y - pair.far;
				double right = points[i].x + pair.far;
				for (int j = 0; j < p2; j++)
				{
					if (points2[j].x<right&&points2[j].y>bottom&&points2[j].y < top)
					{
						double f;
						double temp = (points1[i].x - points2[j].x)*(points1[i].x - points2[j].x)
							+ (points1[i].y - points2[j].y)*(points1[i].y - points2[j].y);
						f = pow(temp, 0.5);
						if (f < pair.far)
						{
							pair.far = f;
							pair.x1 = points1[i].x;
							pair.y1 = points1[i].y;
							pair.x2 = points2[j].x;
							pair.y2 = points2[j].y;
						}
					}
				}
			}
		}

		return pair;
	}

}

int main()
{
	Node points[SIZE];
	int n;
	cout << "请输入点的个数：";
	cin >> n;
	cout << "请输入每个点的坐标，x要求有序:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> points[i].x;
		cin >> points[i].y;
	}

	PairP p=getCloest(points, 0, n-1);
	cout << "最近的两个点是:(" << p.x1 << "," << p.y1 << ")和(" << p.x2 << "," << p.y2 << ")" << endl;
	cout <<"距离是:"<< p.far << endl;
}









































