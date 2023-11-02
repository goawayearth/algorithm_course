#include<stdio.h>
#define MAX 10000
// 设置集合个数
int data[MAX];
bool v[MAX];
int n, c;

bool traceback(int n)
{
	
	int p = 0, sum = 0;

	while (p >= 0)
	{
		
		if (!v[p])
		{
			// 子集中选中v[p]
			v[p] = true;
			// 计算子集和，在sum上进行累加data[p]
			sum += data[p];

			if (c == sum)
				// 返回true
				// 找到子集和的解
				return true;

			// 如果当前累加的子集和sum > 目标值c
			else if (c < sum)
			{
				v[p] = false;
				sum -= data[p];
			}
			// 移动游标到下一位
			p++;
		}

		if (p >= n)
		{
		
			while (v[p - 1])
			{
				// p游标自减
				p--;
				// 对当前v[p]赋值
				v[p] = false;
				// 跑完整个data数组的n个元素
				if (p < 1) return false;
			}
			
			while (!v[p - 1])
			{
				p--;
				if (p < 1) return false;
			}

			// 回溯过程当前子集和sum也回溯到上次
			sum -= data[p - 1];
			// 同时对当前回溯的v[p]重置为false(相当于不要这个元素)
			v[p - 1] = false;
		}
	}

	return false;
}

// 主函数
int main()
{
	// 读入集合元素个数n，子集和目标值c
	scanf("%d %d", &n, &c);
	// 依次读入集合中的n个元素
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);

	if (traceback(n))
	{
		int first = 1;
		for (int i = 0; i < n; i++)
			// 判断v中第(i+1)个元素(v[i])的值是否为0(是否被选中为子集中的元素)
			if (v[i])
			{
				if (first)
					first = 1;
				else
					printf(" ");
				printf("%d ", data[i]);
			}
		printf("\n");
	}
	
	else
		printf("No Solution!\n");

	return 0;
}

