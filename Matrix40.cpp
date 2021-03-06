// Matrix40.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Дана целочисленная матрица размера M × N. Найти номер последней из ее строк, содержащих максимальное количество 
//одинаковых элементов.

#include "pch.h"
#include <iostream>
using namespace std;

void input_matrix(int m, int n, int**a)
{
	for (int i(0); i < m; i++)
	{
		for (int j(0); j < n; j++)
			cin >> a[i][j];
	}
}
int maxnum_of_same_elements_in_row(int i, int n, int**a)
	{
		int Amount = 0, Max_Amount = 0; int j_temp;

		for (j_temp = 0; j_temp < n; j_temp++)
		{
			int Temp = a[i][j_temp];
			for (int j=0; j < n; j++)
			{
				if (a[i][j] == Temp)
					Amount++;
			}
			if (Amount > Max_Amount)
				Max_Amount = Amount;
		}
		if (Max_Amount == 1)
			Max_Amount = 0;
		return Max_Amount;
	}
void num_last_row_with_maxnum_of_same_elements(int m,int n, int**a){
	int row=0,nummax = 0;
	for (int i = 0; i < m; i++)
	{
		
		if (maxnum_of_same_elements_in_row(i, n, a) >= nummax)
		{
			
			 row= i;
			 nummax= maxnum_of_same_elements_in_row(i, n, a);
		}
		
	}
	
	cout<<row;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int m, n;
	cin >> m >> n;
	int **a = new int*[m];
	for (int i = 0; i < m; i++)
		a[i] = new int[n];
	input_matrix(m, n, a);
	num_last_row_with_maxnum_of_same_elements(m, n, a);
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
