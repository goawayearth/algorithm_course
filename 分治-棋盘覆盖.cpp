#include<iostream>
using namespace std;

#define SIZE 100

int board[SIZE][SIZE];//声明棋盘

int t=0;

void cover(int left_i, int right_j, int dot_i, int dot_j, int size) {
	if (size == 1) {//判断是否棋盘大小为1；
		return;
	}


	int tem = ++t;
	int s = size / 2;//棋盘分开;s为已分方形边长

	//特殊点不在左上，就将左上部分的最后一个位置标记，并且标记的位置作为特殊点进行递归
	if (dot_i < left_i + s && dot_j < right_j + s) 
	{
		cover(left_i, right_j, dot_i, dot_j, s);
	}
	else {
		board[left_i + s - 1][right_j + s - 1] = tem;
		cover(left_i, right_j, left_i + s - 1, right_j + s - 1, s);
	}

	//不在左下，就将左下的第一排最后一个设置为标志位
	if (dot_i < left_i + s && dot_j >= right_j + s) {//判断左上 if有特殊，递归，else 右下角设置L贴纸，带入函数递归；
		cover(left_i, right_j + s, dot_i, dot_j, s);
	}
	else {
		board[left_i + s - 1][right_j + s] = tem;
		cover(left_i, right_j + s, left_i + s - 1, right_j + s, s);
	}
	//左下   右上设置
	if (dot_i >= left_i + s && dot_j < right_j + s) {//判断左上 if有特殊，递归，else 右下角设置L贴纸，带入函数递归；
		cover(left_i + s, right_j, dot_i, dot_j, s);
	}
	else {
		board[left_i + s][right_j + s - 1] = tem;
		cover(left_i + s, right_j, left_i + s, right_j + s - 1, s);
	}
	//右下   左上设置
	if (dot_i >= left_i + s && dot_j >= right_j + s) {//判断左上 if有特殊，递归，else 右下角设置L贴纸，带入函数递归；
		cover(left_i + s, right_j + s, dot_i, dot_j, s);
	}
	else {
		board[left_i + s][right_j + s] = tem;
		cover(left_i + s, right_j + s, left_i + s, right_j + s, s);
	}
}
int main() {

	int dot_i, dot_j;/*特殊点坐标*/
	int size = 1;

	cout<<"输入棋盘大小（只能是2的指数）:";
	cin>>size;
	cout<<"输入特殊点坐标:";
	cin >> dot_i >> dot_j;
	
	cover(1, 1, dot_i, dot_j, size);//以左上角第一个元素为参照点

	for (int i = 1; i <= size; i++) 
	{
		for (int j = 1; j <= size; j++) 
		{
			printf("%d\t",board[i][j]);
		}
		
		printf("\n\n");
	}
	return 0;
}

