#include <iostream>
#include "ArrayHelper.h"
using namespace std;

void EnterArray(int a[], int n);//(1-где, 2-сколько или размерность)
void DisplayArray(int[], int);//* для чістоты кода без імен ТОЛЬКО В ПРОТОТІПЕ
bool IsSimpleNumber(int a);
bool IsSameNumber(int[], int); // 2- идекс = до какого элемента
int CounterSimpleNumber(int[], int);
int EnterDimention(int);

int main()
{
	const int N = 100;
	int a[N] = { 0 };
	int n = EnterDimention(N);
	EnterArray(a, n); // а = имя массива
	system("cls");
	cout << "Source array: " << endl;
	DisplayArray(a, n);
	cout << "There are " << CounterSimpleNumber(a, n) << " prime numbers. " << endl;
	system("pause");
	return 0;
}



bool IsSimpleNumber(int a)
{
	for (int i = 2; i <= sqrt(a); i++)
	if (a % i == 0)
		return false;

	return true;
}
void EnterArray(int a[], int n)
{
	cout << "Enter array elements: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << (i + 1) << "] = ";
		cin >> a[i];
	}
	//for (int i = 0; i < n; i++)
	//a[i] = rand() % 100;
}
void DisplayArray(int a[], int n)
{
	cout << "Source array: " << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << ", ";
}
bool IsSameNumber(int a[], int k)
{
	for (int i = 0; i < k; i++)
	if (a[i] == a[k]) return true;
	return false;
}

int CounterSimpleNumber(int a[], int n)
{
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		if (IsSimpleNumber(a[i]) && !(IsSameNumber(a, i)))
			counter++;
	}
	return counter;
}

int EnterDimention(int n)
{
	int k;
	while (true)
	{
		cout << "Enter the amount of elements (n <= 100): ";
		cin >> k;
		if (k > 0 && k <= n) return k; //n=N, n=k
		cout << "Error! Try again...";
	}
	return k;
}
