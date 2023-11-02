#include <iostream>
#include <queue>
#include <functional>
#include <vector>
using namespace std;

//分支限界算法 - 01背包问题  优先级队列
int w[] = { 16,15,15 };//物品的重量
int v[] = { 45, 25, 25 };//物品的价值
int c = 31;//背包的容量
const int n = sizeof(w) / sizeof(w[0]);//物品的个数
int cw = 0;//已选择物品的重量
int cv = 0;//已选择物品的价值
int bestv = 0;//装入背包的物品的最优价值

//描述节点类型
struct Node
{
	Node(int w, int v, int l, int up, Node* p, bool left)
	{
		weight = w;
		value = v;
		level = l;
		parent = p;
		isleft = left;
		upbound = up;
	}
	int weight;//已选择物品的总重量
	int value;//已选择物品的总价值
	int level;//节点所在的层数
	Node* parent;//记录父节点
	bool isleft;//节点是否被选择
	int upbound;//节点的价值上界
};

//queue<Node*> que; //广度遍历需要的FIFO队列
priority_queue<Node*, vector<Node*>, function<bool(Node*, Node*)>> que([](Node* n1, Node* n2)->bool //默认是大根堆
	{
		return n1->upbound < n2->upbound;
	});

void addLiveNode(int w, int v, int l, int up, Node* parent, bool isleft)
{
	Node* node = new Node(w, v, l, up, parent, isleft);
	que.push(node);
}

//求价值上界
int maxBound(int i)
{
	int bound = cv;
	for (int level = i; level < n; ++level)
	{
		bound += v[level];
	}
	return bound;
}
int main()
{
	int i = 0;//起始的层数
	Node* node = nullptr;//记录父节点
	int upbound = maxBound(0);
	while (i < n)
	{
		//选择物品i
		int wt = cw + w[i];
		if (wt <= c) {
			if (cv + v[i] > bestv)
			{
				bestv = cv + v[i];
			}

			//把左孩子加入活结点队列当中
			addLiveNode(cw + w[i], cv + v[i], i + 1, upbound, node, true);
		}

		//不选择物品i
		upbound = maxBound(i + 1);//i+1表示第一个未被处理的物品的数组下标
		if (upbound >= bestv)
		{
			addLiveNode(cw, cv, i + 1, upbound, node, false);
		}

		node = que.top();
		que.pop();
		i = node->level;
		cw = node->weight;
		cv = node->value;
		upbound = node->upbound;
	}

	cout << bestv << endl;
	int x[n] = { 0 };
	for (int j = n - 1; j >= 0; --j)
	{
		x[j] = node->isleft ? 1 : 0;
		node = node->parent;
	}

	for (int v : x)
	{
		cout << v << " ";
	}
	cout << endl;
	return 0;
}

