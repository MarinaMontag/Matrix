// Matrix64.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Дана матрица размера M × N. Удалить столбец, содержащий максимальный элемент матрицы.

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
int max_column(int m, int n, int**a) {
	int j_max, max = a[0][0];
	for (int j = 0; j < n; j++)
		for (int i = 0; i < m; i++)
			if (a[i][j] > max) {
				max = a[i][j];
				j_max = j;
			}
	return j_max;
}

void delete_max_column(int m, int n, int**a) {
	int j = max_column(m, n, a);
	for(int k=j;k<n;k++)
		for (int i = 0; i < m; i++) 
			a[i][k] = a[i][k + 1];
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
int main()
{
	setlocale(LC_ALL, "Russian");
	int m, n;
	cin >> m >> n;
	int**a = new int *[m];
	for (int i = 0; i < m; i++)
		a[i] = new int[n];
	input_matrix(m, n, a);
	cout << endl;
	delete_max_column(m, n, a);
	n--;
	output_matrix(m, n, a);
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
