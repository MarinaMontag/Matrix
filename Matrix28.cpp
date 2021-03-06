// Matrix28.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Дана матрица размера M × N. Найти минимальный среди максимальных элементов ее столбцов.

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

	int max_element_of_column(int j,int m,int n,int **a) {
		
		int max = a[0][j];
		for (int i = 0; i < m; i++)
			if (a[i][j] > max)max = a[i][j];
		return max;
	}
	
	void min_of_max(int**a, int n, int m)
	{
		int min = max_element_of_column(0, m, n, a);
		for (int j=1; j < n; j++)
			if (max_element_of_column(j, m, n, a) < min)
				min = max_element_of_column(j, m, n, a);
		cout << min;
	}

int main()
{
	setlocale(LC_ALL, "Russian");
	int m, n;
	cin >> m >> n;
	int**a = new int *[m];
	for (int i = 0; i < m; i++)
		a[i] = new int[n];
	input_matrix(m, n, a);
	
	 min_of_max(a,n,m);
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
