// Matrix84.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Дана квадратная матрица A порядка M. Найти среднее арифметиче-ское элементов каждой ее диагонали, параллельной г
//лавной (начиная с од-ноэлементной диагонали A1,M).

#include "pch.h"
#include <iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void input_matrix(int m, int**a) {
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++) 
		{
			a[i][j] = rand() % 100;
		}
}
void output_matrix(int m, int**a)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)

			cout <<setw(3)<< a[i][j] << " ";
		cout << endl;
	}
}

double average_arithmetic(int k, int m, int**a)
{
	double sum = 0, counter = 0;
	for (int i = (k < 0 ? -k : 0); i < (k < 0 ? m : m - k); i++)
	{
		sum += a[i][i + k];
		counter++;
	}
	return sum / counter;
}



int main()
{
	setlocale(LC_ALL, "Russian");
	int m;
	cin >> m;
	int**a;
	a = new int *[m];
	for (int i = 0; i < m; i++)
		a[i] = new int[m];
	input_matrix(m, a);
	output_matrix(m, a);
	for (int k = m - 1; k > -m; k--)
	{
		if (k == 0) continue;

		cout << "Mean value = " << average_arithmetic(k, m, a) << endl;
	}
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
