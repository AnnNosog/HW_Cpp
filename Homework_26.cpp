#include <iostream>
#include <cstring>

#define N 500
#define M 2
#define P 52
#define K 30

using namespace std;

void SpaceRemoval(char *arr, int size = N);
void InputArrey(int **arr, int sizeM = M, int sizeP = P);
int AffirmativeSentence(const char *arr, int size = N);
int ExclamatorySentence(const char *arr, int size = N);
int InterrogativeSentence(const char *arr, int size = N);
void CapitalLetter(char *arr, int size = N);
void LetterAppears(const char *arr, int **arrLett, int sizeN = N, int sizeM = M, int sizeP = P);
void PrintLetterAppears(int **arrLett, int sizeM = M, int sizeP = P);
int AmountOfDigits(const char *arr, int size = N);
int WordSearch(const char *arr, const char *arrSear, int size = N);


int main()
{
	char *mainString = new char[N]{ '\0' };
	int **arrLetters = new int*[M]{ 0 };		
	char *stringSearch = new char[K] {'\0'};

	InputArrey(arrLetters);		

	cout << "Enter a text." << endl;
	cin.getline(mainString, N);
	cout << endl;

	SpaceRemoval(mainString);
	
	cout << "Amount of affirmative sentence: " << AffirmativeSentence(mainString) << endl;
	cout << "Amount of exclamatory sentence: " << ExclamatorySentence(mainString) << endl;
	cout << "Amount of interrogative sentence: " << InterrogativeSentence(mainString) << endl;
	cout << endl;

	CapitalLetter(mainString);				

	cout << mainString << endl;
	cout << endl;

	LetterAppears(mainString, arrLetters);
	PrintLetterAppears(arrLetters);

	cout << endl;

	cout << "Amount of digits: " << AmountOfDigits(mainString) << endl;
	cout << endl;

	cout << "Enter the word: ";
	cin >> stringSearch;

	cout << "The word \"" << stringSearch << "\" occurs " << WordSearch(mainString, stringSearch) << " times" << endl;


	delete[] mainString;
	delete[] arrLetters;

	system("pause");
	return 0;
}

void SpaceRemoval(char *arr, int size)
{
	for (size_t i = 0; i < N; i++)
	{
		if (arr[i] == ' ' && arr[i + 1] == ' ')
		{
			memmove(arr + (i + 1), arr + (i + 2), N - i - 1);
			i--;
		}
	}
}

void InputArrey(int **arr, int sizeM, int sizeP)
{
	for (size_t i = 0; i < M; i++)
	{
		arr[i] = new int[P];
	}

	for (size_t i = 0; i < M - 1; i++)
	{
		for (size_t j = 0, k = 65; j < P && k < 123; j++, k++)
		{
			if (k == 91)
			{
				k = 96;
				j--;
				continue;
			}

			arr[i][j] = k;
		}
	}

	for (size_t i = 1; i < M; i++)
	{
		for (size_t j = 0; j < P; j++)
		{
			arr[i][j] = 0;
		}
	}
}

int AffirmativeSentence(const char *arr, int size)
{
	char symbol = '.';
	int number = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == symbol)
		{
			number++;
		}
	}
	return number;
}

int ExclamatorySentence(const char *arr, int size)
{
	char symbol = '!';
	int number = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == symbol)
		{
			number++;
		}
	}
	return number;
}

int InterrogativeSentence(const char *arr, int size)
{
	char symbol = '?';
	int number = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == symbol)
		{
			number++;
		}
	}
	return number;
}

void CapitalLetter(char *arr, int size)
{
	if (arr[0] > 97 && arr[0] < 122)
	{
		arr[0] -= 32;
	}

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == '.' || arr[i] == '!' || arr[i] == '?')
		{
			if (arr[i + 1] == ' ')
			{
				if (arr[i + 2] < 97 || arr[i + 2] > 122)
				{
					continue;
				}
				else
				{
					arr[i + 2] -= 32;
					//arr[i + 2] = (char)toupper(ptr[i + 2]);

				}				
			}
			else if (arr[i + 1] > 97 && arr[i + 1] < 122)
			{
				arr[i + 1] -= 32;
				//arr[i + 1] = (char)toupper(ptr[i + 1]);
			}
			else
			{
				continue;
			}
		}
	}
}

void LetterAppears(const char *arr, int **arrLett, int sizeN, int sizeM, int sizeP)
{
	for (size_t i = 0; i < sizeN; i++)
	{
		for (size_t j = 0; j < M - 1; j++)
		{
			for (size_t k = 0; k < sizeP; k++)
			{
				if (arr[i] == arrLett[j][k])
				{
					arrLett[M - 1][k]++;
				}
			}
		}
	}
}

void PrintLetterAppears(int **arrLett, int sizeM, int sizeP)
{
	for (size_t i = 1; i < sizeM; i++)
	{
		for (size_t j = 0; j < sizeP; j++)
		{
			if (arrLett[i][j] == 0)
			{
				continue;
			}
			else
			{
				cout << "Amount of letter " << (char)arrLett[0][j] << " is " << arrLett[i][j] << endl;
			}
		}
	}
}

int AmountOfDigits(const char *arr, int size)
{	
	int number = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > 47 && arr[i] < 58)
		{
			number++;
		}
	}
	return number;
}

int WordSearch(const char *arr, const char *arrSear, int size)
{
	int num = 0;
	const char *found = nullptr;

	found = strstr(arr, arrSear);

	while (found != nullptr)
	{
		num++;		
		found++;
		found = strstr(found, arrSear);
	}

	return num;
}
