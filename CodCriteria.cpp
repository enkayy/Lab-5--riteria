#include <Windows.h>
#include <iostream>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	float n;// кол-во критериев
	for (;;)//проверка ввода количества критериев
	{
		cout << "Введите количество критериев:";
		cin >> n;
		if (!cin)
		{
			cout << "Введите число" << endl;
		}
		else
		{
			if (n <= 0)
			{
				cout << "Введите положительное число" << endl;
			}
			else
			{
				if (int(n) != n)
				{
					cout << "Введите целое число" << endl;
				}
				else
					break;
			}
		}
		cin.clear();
		cin.ignore(100000, '\n');
	}
	float* a = new float[n * n];
	cout << "Введите через пробел таблицу попарного сравнения критериев(только сами значения). Чтобы перейти на следующую строку таблицы нажмите Enter." << endl;

	for (int i = 0; i < n * n; i++)// ввод данных попарного сравнения
	{
		for (;;)
		{
			cin >> a[i];
			if (!cin)
			{
				cout << "Введите число" << endl;
			}
			else
			{
				if (a[i] <= 0)
				{
					cout << endl << "Введите положительное число" << endl;
				}
				else
					break;
			}
			cin.clear();
			cin.ignore(100000, '\n');
		}
	}
	float* sumstr = new float[n];// массив из сумм таблицы по строкам
	int counter = 0;
	for (int i = 0; i < n; i++)// инициализация всех элементов массива
	{
		sumstr[i] = 0;
	}
	for (int i = 0; i < n; i++)// подсчёт сумм всех строк таблицы
	{
		for (int i1 = 0; i1 < n; i1++)
		{
			sumstr[i] = sumstr[i] + a[i1 + (int(n) * counter)];
		}
		counter++;
	}
	float allsum = 0;
	for (int i = 0; i < n; i++)// подсчёт суммы всех элементов таблицы
	{
		allsum = allsum + sumstr[i];
	}
	cout.precision(2);
	for (int i = 0; i < n; i++)// вывод результата
	{
		cout << "Весовой коэффициент критерия " << i + 1 << ":" << sumstr[i] / allsum << endl;
	}
}