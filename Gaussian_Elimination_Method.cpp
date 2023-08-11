#include <iostream>
using namespace std;
const int MAX = 100;
void input_Matrix(int &n, float M[][MAX]);
void show_Matrix(int n, float M[][MAX]);
void gaussianElimination(int n, float M[][MAX]);

int main()
{
	int c, n;
	float M[MAX][MAX];
	input_Matrix(n, M);
	
	cout << "\n\n\n Matrix of linear equations: \n\n";
	show_Matrix(n, M);
	
	gaussianElimination(n, M);
	cout << "\n\n\n Solutions:\n";
	for (c = 1; c <= n; c++){
		cout << "\n X" << c << "=" << M[c][n + 1] << endl;}
	

	return 0;
}

void input_Matrix(int &n, float M[][MAX])
{
	int i, j;
	cout << "\n\n|| Solving system of Linear equations by Gaussian Elimination||\n";
	
	do{
	cout << "\n\n\n Enter the order of Matrix: ";
	cin >> n;
	}while(n<=0 || n>MAX);
	
	cout << "\n\n Introduce each element AX=B:";
	cout << "\n\n MATRIX A:\n";
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++)
	{
			cout << "\n A[" << i<< "][" << j << "]: ";
			cin >> M[i][j];
	}
	}
		cout << "\n\n\n Enter Values to the right side of B";
		for (i = 1; i <= n; i++)
		{
			cout << "\n B[" << i << "]: ";
			cin >> M[i][n + 1];
		}
}

void show_Matrix(int n, float M[][MAX])
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= (n + 1); j++)
		{
			
			cout<< M[i][j]<<"\t"; 
			if (j == n)
				cout << "   |";
		}
		cout << endl;
	}
}

void gaussianElimination(int n, float M[][MAX])
{
	int num, Col, rowIdx1, rowIdx2, i;
	float val, v1;
	
	
	// Forward Elimination loop
	for (Col = 1; Col <= n; Col++)
	{
		num = 0;
		i = Col;
		
		while (num == 0)
		{
			if (M[i][Col] != 0)
			{
				num= 1;
			}
			else
			{
				i++;
			}
		}
		
		val = M[i][Col];
		for (rowIdx1 = 1; rowIdx1 <= (n + 1); rowIdx1++)
		{
			v1 = M[i][rowIdx1];
			M[i][rowIdx1] = M[Col][rowIdx1];
			M[Col][rowIdx1] = v1 / val;
		}
		for (rowIdx2 = Col + 1; rowIdx2 <= n; rowIdx2++)
		{
			v1 = M[rowIdx2][Col];
			for (rowIdx1 = Col; rowIdx1 <= (n + 1); rowIdx1++)
			{
				M[rowIdx2][rowIdx1] = M[rowIdx2][rowIdx1] - v1 * M[Col][rowIdx1];
			}
		}
	}
	
	// Back-Substitution loop
	for (Col = n; Col >= 1; Col--)
	{
		for (rowIdx1 = (Col - 1); rowIdx1 >= 1; rowIdx1--)
		{
			M[rowIdx1][n + 1] = M[rowIdx1][n + 1] - M[rowIdx1][Col] * M[Col][n + 1];
			M[rowIdx1][Col] = 0;
		}
	}
}
