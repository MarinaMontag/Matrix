// Matrix72.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Дана матрица размера M × N. Перед первым столбцом, содержащим только положительные элементы, вставить столбец из единиц. 
//Если требуемых столбцов нет, то вывести матрицу без изменений.

#include "pch.h"
#include <iostream>
using namespace std;

void input_matrix(int m, int n, int**a) {
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			while (!(cin >> a[i][j]))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Введите значение элемента массива " << i << " рядочка и " << j << " столбца" << endl;

			}
		}
}

void output_matrix(int m, int n, int**a)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

bool positive_column(int j, int m, int**a) 
{
	bool Boolean = true;
	for(int i=0;i<m;i++)
		if (a[i][j] <= 0)
		{
			Boolean = false;
			}
	if(Boolean == true)
		return true;
	else return false;
}

int first_positive_column(int m, int n, int**a)
{
	int first_pos;
	for (int j = 0; j < n; j++)
	{
		if (positive_column(j, m, a))
		{
			first_pos = j;
			break;
		}
	}
	return first_pos;
}

int existing_of_pos_column(int m, int n, int **a)
{
	int result = 0;
	for(int j=0;j<n;j++)
	if (positive_column(j, m, a))
	{
		result = 1;
		break;
	}
	return result;
}

void new_column(int &k,int m,int n, int**a)
{
	for (int i = 0; i < m; i++)
		for (int j = n+1; j >k; j--)
			a[i][j] = a[i][j-1];
	for (int i = 0; i < m; i++)
	{
		int j = k;
		a[i][j] = 1;
		}
	}

int main()
{
	setlocale(LC_ALL, "Russian");
	int m, n;
	cin >> m >> n;
	int**a;
	a = new int *[m];
	for (int i = 0; i < m; i++)
		a[i] = new int[n+1];
	input_matrix(m, n, a);
	cout << endl;
	if (existing_of_pos_column(m, n, a))
	{
		int k = first_positive_column(m, n, a);
	new_column(k, m, n, a);
	
	output_matrix(m, n+1, a);
	}
	else output_matrix(m, n, a);
	for (int i = 0; i < m; i++)
		delete a[i];
	delete a;
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
