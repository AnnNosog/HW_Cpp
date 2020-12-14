#include <iostream>
#include <ctime>

using namespace std;

int **createMatr(unsigned int sizeN);
void deleteMatr(int **arr, unsigned int sizeN);
void randomMatr(int** arr, unsigned int sizeN);
void printMatr(int** arr, unsigned int sizeN);
void TranspositionToTheMainAxis(int **arr, unsigned int sizeN);
void TranspositionToTheСollateralAxis(int **arr, unsigned int sizeN);


int main()
{
	srand(time(0));

	int **matr = nullptr;
	int sizeN = 5;

	matr = createMatr(sizeN);
	randomMatr(matr, sizeN);
	printMatr(matr, sizeN);
	TranspositionToTheMainAxis(matr, sizeN);

	cout << endl << endl;

	printMatr(matr, sizeN);
	TranspositionToTheСollateralAxis(matr, sizeN);

	cout << endl << endl;

	printMatr(matr, sizeN);
	deleteMatr(matr, sizeN);

	system("pause");
	return 0;
}

int **createMatr(unsigned int sizeN)
{
	int **arr = nullptr;
	arr = new int *[sizeN];

	for (size_t i = 0; i < sizeN; i++)
	{
		arr[i] = new int[sizeN];
	}

	return arr;
}

void deleteMatr(int **arr, unsigned int sizeN)
{
	for (size_t i = 0; i < sizeN; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;
}

void randomMatr(int **arr, unsigned int sizeN)
{
	for (size_t i = 0; i < sizeN; i++)
	{
		for (size_t j = 0; j < sizeN; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}
}

void printMatr(int **arr, unsigned int sizeN)
{
	for (size_t i = 0; i < sizeN; i++)
	{
		for (size_t j = 0; j < sizeN; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void TranspositionToTheMainAxis(int **arr, unsigned int sizeN)
{
	int temp = 0;
	
	for (size_t i = 0; i < sizeN; i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;
		}
	}
}

void TranspositionToTheСollateralAxis(int **arr, unsigned int sizeN)
{
	int temp = 0;
	
	for (size_t i = 0; i < sizeN; i++)
	{
		for (size_t j = 0; j < sizeN - i; j++)
		{			
			temp = arr[i][j];
			arr[i][j] = arr[sizeN - 1 - j][sizeN - 1 - i];
			arr[sizeN - 1 - j][sizeN - 1 - i] = temp;
		}
	}	
}
