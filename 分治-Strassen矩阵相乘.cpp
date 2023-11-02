#include <iostream>


using namespace std;


int *InitMatrix(int row, int col)//初始化矩阵，大小事先不确定，所以需要动态分配  
{
	int *p;
	size_t size = sizeof(int)*row*col;//需要开row*col个int类型大小的空间 
	if (NULL == (p = (int *)malloc(size)))//如果总的空间是空的
	{
		cout << "Error in InitMatrix!" << endl;
		return NULL;
	}
	else
		return p;    //返回矩阵首地址 
}


void FillMatrix(int *MatrixA, int size)
{
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			cin >> MatrixA[row*size + col];
		}
	}
}

//输出矩阵
void PrintMatrix(int *MatrixA, int size)
{
	
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			cout << MatrixA[row*size + col] << "\t";
			if ((col + 1) % ((size)) == 0)
				cout << endl;
		}
	}
	cout << endl;
}

//矩阵相加，当矩阵的秩是2的时候，不在递归，直接矩阵相加
void AddMatrix(int *MatrixIn1, int *MatrixIn2, int *MatrixOut, int size)
{
	for (int i = 0; i < size*size; i++)
	{
		MatrixOut[i] = MatrixIn1[i] + MatrixIn2[i];
	}
}

//矩阵相减
void SubMatrix(int *MatrixIn1, int *MatrixIn2, int *MatrixOut, int size)
{
	for (int i = 0; i < size*size; i++)
	{
		MatrixOut[i] = MatrixIn1[i] - MatrixIn2[i];
	}
}

//将矩阵分成四块，根据part的不同，对应着分的块也不同
void SplitMatrix(int *MatrixIn, int *MatrixOut, int size, int part)
{
	int n = size / 2;//编写方便 
	switch (part)
	{
	case 1://四分左上 
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				MatrixOut[i*n + j] = MatrixIn[i*n + j];
			}
		}
		break;
	}
	case 2://四分右上 
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				MatrixOut[i*n + j] = MatrixIn[i*n + j + n];
			}
		}
		break;
	}
	case 3://四分左下 
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				MatrixOut[i*n + j] = MatrixIn[(i + n)*n + j];
			}
		}
		break;
	}
	case 4://四分右下 
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				MatrixOut[i*n + j] = MatrixIn[(i + n)*n + j + n];
			}
		}
		break;
	}
	default:
		cout << "Error in SplitMatrix!";
	}
}

//拼接矩阵，将最后求出来的四个矩阵拼回去
void StitchMatrix(int *PartA, int *PartB, int *PartC, int *PartD, int *Result, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			Result[i*size * 2 + j] = PartA[i*size + j];
			Result[i*size * 2 + j + size] = PartB[i*size + j];
			Result[(i + size)*size * 2 + j] = PartC[i*size + j];
			Result[(i + size)*size * 2 + j + size] = PartD[i*size + j];
		}
	}
}
/*
/Strassen算法：
/分块，分到2*2
*/
void Strassen(int *MA, int *MB, int *MC, int size)
{
	int n = size / 2;
	if (2 == size)//这样就不用分了，以及分到最后执行这个不用再递归 
	{
		int p1, p2, p3, p4, p5, p6, p7;
		p1 = MA[0] * (MB[1] - MB[3]);
		p2 = (MA[0] + MA[1])*MB[3];
		p3 = (MA[2] + MA[3])*MB[0];
		p4 = MA[3] * (MB[2] - MB[0]);
		p5 = (MA[0] + MA[3])*(MB[0] + MB[3]);
		p6 = (MA[1] - MA[3])*(MB[2] + MB[3]);
		p7 = (MA[0] - MA[2])*(MB[0] + MB[1]);
		MC[0] = p5 + p4 - p2 + p6;
		MC[1] = p1 + p2;
		MC[2] = p3 + p4;
		MC[3] = p5 + p1 - p3 - p7;
		return;
	}
	else
	{
		int *MA1 = NULL, *MA2 = NULL, *MA3 = NULL, *MA4 = NULL;//A矩阵分成4块
		int *MB1 = NULL, *MB2 = NULL, *MB3 = NULL, *MB4 = NULL;//B矩阵分成4块
		int *MC1 = NULL, *MC2 = NULL, *MC3 = NULL, *MC4 = NULL;//C矩阵分成4块
		int *M1 = NULL, *M2 = NULL, *M3 = NULL, *M4 = NULL, *M5 = NULL, *M6 = NULL, *M7 = NULL;//7个指针
		int *TEMP1 = NULL, *TEMP2 = NULL;
		/*初始化开始，一半大小的矩阵*/
		MA1 = InitMatrix(n, n);
		MA2 = InitMatrix(n, n);
		MA3 = InitMatrix(n, n);
		MA4 = InitMatrix(n, n);

		MB1 = InitMatrix(n, n);
		MB2 = InitMatrix(n, n);
		MB3 = InitMatrix(n, n);
		MB4 = InitMatrix(n, n);

		MC1 = InitMatrix(n, n);
		MC2 = InitMatrix(n, n);
		MC3 = InitMatrix(n, n);
		MC4 = InitMatrix(n, n);
	
		M1 = InitMatrix(n, n);
		M2 = InitMatrix(n, n);
		M3 = InitMatrix(n, n);
		M4 = InitMatrix(n, n);
		M5 = InitMatrix(n, n);
		M6 = InitMatrix(n, n);
		M7 = InitMatrix(n, n);
       
		TEMP1 = InitMatrix(n, n);
		TEMP2 = InitMatrix(n, n);
		/*初始化完成*/

		/*将小矩阵赋值，附上大矩阵的值*/
		SplitMatrix(MA, MA1, size, 1); 
		SplitMatrix(MA, MA2, size, 2); 
		SplitMatrix(MA, MA3, size, 3); 
		SplitMatrix(MA, MA4, size, 4);
		SplitMatrix(MB, MB1, size, 1); 
		SplitMatrix(MB, MB2, size, 2); 
		SplitMatrix(MB, MB3, size, 3); 
		SplitMatrix(MB, MB4, size, 4);
		/*赋值完成*/

		/*求M1--M7*/
		//M1=(B00+B11)*(A00+A11)
		AddMatrix(MB1, MB4, TEMP1, n);
		AddMatrix(MA1, MA4, TEMP2, n);
		Strassen(TEMP1, TEMP2, M1, n);

        //M2=B00*(A10+A11)
		AddMatrix(MA3, MA4, TEMP1, n);
		Strassen(MB1, TEMP1, M2, n);

		//M3=A00*(B01-B11)
		SubMatrix(MB2, MB4, TEMP1, n);
		Strassen(MA1, TEMP1, M3, n);

		//M4=A11*(B10-B00)
		SubMatrix(MB3, MB1, TEMP1, n);
		Strassen(MA4, TEMP1, M4, n);

		//M5=B11*(A00+A01)
		AddMatrix(MA1, MA2, TEMP1, n);
		Strassen(MB4, TEMP1, M5, n);
		
	    // M6=(B00+B01)*(A10-A00)
		AddMatrix(MB1, MB2, TEMP1, n);
		SubMatrix(MA3, MA1, TEMP2, n);
		Strassen(TEMP1, TEMP2, M6, n);
		
		//M7=(B10+B11)*(A01-A11)
		AddMatrix(MB3, MB4, TEMP1, n);
		SubMatrix(MA2, MA4, TEMP1, n);
		Strassen(TEMP1, TEMP2, M7, n);
		/*求M1--M7完成*/
	
		//C1=P5+P4+P6-P2
		AddMatrix(M1, M4, TEMP1, n);
		AddMatrix(TEMP1, M7, TEMP2, n);
		SubMatrix(TEMP2, M5, MC1, n);

		//C2=P1+P2
		AddMatrix(M3, M5, MC2, n);

		//C3=P3+P4
		AddMatrix(M2, M4, MC3, n);

		//C4=P5+P1-P3-P7
		AddMatrix(M1, M3, TEMP1, n);
		SubMatrix(TEMP1, M2, TEMP2, n);
		AddMatrix(TEMP2, M6, MC4, n);

		StitchMatrix(MC1, MC2, MC3, MC4, MC, n);

		/*释放内存*/
		free(MA1); free(MA2); free(MA3); free(MA4);
		free(MB1); free(MB2); free(MB3); free(MB4);
		free(MC1); free(MC2); free(MC3); free(MC4);
		free(M1); free(M2); free(M3); free(M4); free(M5); free(M6); free(M7);
		free(TEMP1); free(TEMP2);

		return;
	}
}

int main()
{
	int MaSize = 0;
	cout << "Please input the row of matrix(it must be index of two,like,2,4,8):";
	cin >> MaSize;

	int *MA = NULL;//规避野指针 
	int *MB = NULL;
	int *MC = NULL;

	MA = InitMatrix(MaSize, MaSize);
	MB = InitMatrix(MaSize, MaSize);
	MC = InitMatrix(MaSize, MaSize);

	FillMatrix(MA, MaSize);
	FillMatrix(MB, MaSize);

	Strassen(MA, MB, MC, MaSize);

	cout << "After Strassen multiplication the result is:" << endl << endl;
	PrintMatrix(MC, MaSize);
	
	//释放空间 
	free(MA);
	free(MB);
	free(MC);

	return 0;
}