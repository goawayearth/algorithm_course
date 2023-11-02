#include<iostream>
using namespace std;
#define size 10000
int result=0;
int L[size];


void QSort(int low, int high, int k);
int Partition(int low, int high, int flag,int sw);//low 和 high 是下标，flag是具体的数值
void swap(int& a, int& b);
int getDivideNum(int n,int);
void QSort1(int low, int high, int k);

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

typedef struct Node
{
	int start;
	int end;
	struct Node* next;
}NODE;

void Find_k_smallest(int low,int high, int k)//n是数据的大小
{
	if (high+1 < k)
	{
		cout << "输入错误！";
		return;
	}
	else if (high-low < 74)
	{
		QSort(0,high, k);
	}
	else if(high-low>=74)
	{
		QSort1(0, high,k);
	}
}


void QSort(int low, int high,int k)
{
	
	int pivot;
	
	if (low < high)
	{
		pivot = Partition(low, high,L[low],0); /*  将L->r[low..high]一分为二，算出枢轴值pivot */
		if (pivot == k - 1) result=L[pivot];
		else if(pivot>k-1)
		QSort(low, pivot - 1,k);		/*  对低子表递归排序 */
		else
		QSort(pivot + 1, high,k);		/*  对高子表递归排序 */
	}
}


int Partition(int low, int high,int flag,int sw)//low 和 high 是下标，flag是具体的数值
{
	if(sw==1)while (high > low&&L[low] < flag)low++;
	
	//
	while (high > low)
	{
		while (high > low&&L[high] >= flag)high--;
		swap(L[low], L[high]);
		while (high > low&&L[low] <= flag)low++;
		swap(L[low], L[high]);
	}
	L[low] = flag;
	return low;
}

void QSort1(int low, int high, int k)//low和high都是下标
{
	
	int p=getDivideNum(low,high);

	int num=Partition(low, high, p, 1);
	if (num == k)result = p;
	else if (num > k)
	{
		Find_k_smallest(low, num - 1, k);
		
	}
	else if (num < k)Find_k_smallest(num+1, high, k);
}



int getDivideNum(int low,int high)//high>=low
{
	int divideNum[size];
	int count1 = -1;
	NODE* head = (NODE*)malloc(sizeof(NODE));//没用结点
	head->start = -1;
	head->end = low-1;
	head->next = NULL;
	NODE* p = head;
	while (1)
	{
		NODE* q= (NODE*)malloc(sizeof(NODE));
		q->start = p->end + 1;
		q->next = NULL;
		p->next = q;
		p = q;
		if (q->start + 4 <high) 
		{
			q->end = q->start + 4;
		}

		else if (q->start + 4 >= high)
		{
			q->end = high;
			break;
		}
	}
	p = head->next;
	while (p)
	{
		QSort(p->start, p->end, (p->start + p->end) / 2);
		divideNum[++count1] = result;
		p = p->next;
	}
	for(int i=0;i<count1;i++)
		for (int j = 0; j < count1; j++)
		{
			if (divideNum[j] > divideNum[j + 1])
				swap(divideNum[j], divideNum[j + 1]);
		}
	return divideNum[count1 / 2];
}



int main()
{
	for (int i = 0; i < 90; i++)
	{
		L[i] = 179 - i;
	}
	int nn;
	while (1)
	{
		cin >> nn;
		Find_k_smallest(0,89, nn);
		cout <<"result:"<< result << endl;
	}
}