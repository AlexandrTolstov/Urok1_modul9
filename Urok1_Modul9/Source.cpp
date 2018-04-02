#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <cmath>

#include "GenMass.h"

using namespace std;


void main() {

	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N1 = 0;
	printf("Введите номер задания\nN = ");

	scanf("%d", &N1);

	if (N1 == 1)
	{
		int *a = NULL;
		int *b = NULL;
		int *c = NULL;
		int Str = 0;
		int Col = 0;

		GenMassTwoDimMalloc(a, &Str, &Col, -50, 50);

		b = (int *)malloc(Col * sizeof(int));
		c = (int *)malloc(Str * sizeof(int));

		if (a == NULL)
		{
			printf("Память не выделена");
			exit(EXIT_FAILURE);
		}
		else
		{
			printf("Наибольший по модулю из столбца\n");
			int MaxMod = 0;
			for (int j = 0; j < Col; j++)
			{
				for (int i = 0; i < Str; i++)
				{
					if (abs(*(a + i*Col + j)) > abs(MaxMod))
						MaxMod = *(a + i*Col + j);
				}

				*(b + j) = MaxMod;
				printf("%d\t", *(b + j));
				MaxMod = 0;
			}
			printf("\n");

			printf("Наибольший по модулю из строки\n");
			MaxMod = 0;

			for (int i = 0; i < Str; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					if (abs(*(a + i*Col + j)) > abs(MaxMod))
						MaxMod = *(a + i*Col + j);
				}

				*(c + i) = MaxMod;
				printf("%d\n", *(c + i));
				MaxMod = 0;
			}
			printf("\n");
		}
		free(a);
		free(b);
		free(c);
	}
	else if (N1 == 2)
	{
		int *a = NULL;
		int *b = NULL;
		int *c = NULL;
		int Str = 0;
		int Col = 0;

		GenMassTwoDimMalloc(a, &Str, &Col, -50, 50);

		b = (int *)malloc(Col * sizeof(int));
		c = (int *)malloc(Col * sizeof(int));

		if (a == NULL)
		{
			printf("Память не выделена");
			exit(EXIT_FAILURE);
		}
		else
		{
			printf("Первые четные элементы соответствующих столбцов\n");
			int ChetCol = 0;
			for (int j = 0; j < Col; j++)
			{
				for (int i = 0; i < Str; i++)
				{
					if (*(a + i*Col + j) % 2 == 0 && *(a + i*Col + j) != 0)
					{
						ChetCol = *(a + i*Col + j);
						i = Str - 1;
					}
					else ChetCol = 0;
				}
				*(b + j) = ChetCol;
				printf("%d\t", *(b + j));
			}
			printf("\n");

			printf("Последние нечетные элементы соответствующих столбцов\n");
			ChetCol = 0;
			for (int j = 0; j < Col; j++)
			{
				for (int i = 0; i < Str; i++)
				{
					if (*(a + i*Col + j) % 2 == 0 && *(a + i*Col + j) != 0)
					{
						ChetCol = *(a + i*Col + j);
					}
				}
				*(c + j) = ChetCol;
				printf("%d\t", *(c + j));
				ChetCol = 0;
			}
			printf("\n");
		}
		free(a);
		free(b);
		free(c);
	}
	else if (N1 == 3)
	{
		int *a = NULL;
		int *Num = NULL;
		int *Summ = NULL;
		int Str = 0;
		int Col = 0;

		GenMassTwoDimMalloc(a, &Str, &Col, 1, 50);

		Num = (int *)malloc(Col * sizeof(int));
		Summ = (int *)malloc(Str * sizeof(int));

		if (a == NULL)
		{
			printf("Память не выделена");
			exit(EXIT_FAILURE);
		}
		else
		{
			int Nam = 0;
			printf("Введите Число Nam = ");
			scanf("%d", &Nam);
			printf("Количество элементов соответствующего столбца двумерного массива, больших числа %d\n", Nam);
			int z = 0;
			for (int j = 0; j < Col; j++)
			{
				for (int i = 0; i < Str; i++)
				{
					if (*(a + i*Col + j) > Nam)
						z += 1;
				}
				*(Num + j) = z;
				printf("%d\t", *(Num + j));
				z = 0;
			}
			printf("\n");

			printf("Сумма элементов соответствующей строки %d\n");
			int Sum = 0;
			for (int i = 0; i < Str; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					Sum += *(a + i*Col + j);
				}
				*(Summ + i) = Sum;
				printf("%d\n", *(Summ + i));
				Sum = 0;
			}
			printf("\n");
		}
		free(a);
		free(Num);
		free(Summ);
	}
	else if (N1 == 4)
	{
		int *a = NULL;
		int *MusKrTrem = NULL;
		int *PolMus = NULL;
		int *OtrMus = NULL;
		int Str = 0;
		int Col = 0;

		GenMassTwoDimMalloc(a, &Str, &Col, -50, 50);

		if (a == NULL)
		{
			printf("Память не выделена");
			exit(EXIT_FAILURE);
		}
		else
		{
			int NumKrTrem = 0;
			for (int i = 0; i < Str; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					if (*(a + i*Col + j) % 3 == 0)
						NumKrTrem += 1;
				}
			}
			printf("NumKrTrem = %d\n", NumKrTrem);

			MusKrTrem = (int *)malloc(NumKrTrem * sizeof(int));

			printf("Массив из чисел кратных трем\n");
			int z = 0;
			for (int i = 0; i < Str; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					if (*(a + i*Col + j) % 3 == 0)
					{
						*(MusKrTrem + z) = *(a + i*Col + j);
						z++;
						printf("%d\t", *(a + i*Col + j));
					}
				}
			}
			printf("\n");

			int NumPol = 0;
			int NumOtr = 0;
			for (int i = 0; i < Str; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					if (*(a + i*Col + j) > 0)
						NumPol += 1;
					else if (*(a + i*Col + j) < 0)
						NumOtr += 1;
				}
			}
			printf("NumPol = %d\n", NumPol);
			printf("NumOtr = %d\n", NumOtr);

			PolMus = (int *)malloc(NumPol * sizeof(int));
			OtrMus = (int *)malloc(NumOtr * sizeof(int));

			printf("\nМассив из положительных чисел\n");
			z = 0;
			for (int i = 0; i < Str; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					if (*(a + i*Col + j) > 0)
					{
						*(PolMus + z) = *(a + i*Col + j);
						printf("%d\t", *(PolMus + z));
						z++;
					}
				}
			}
			printf("\nМассив из отрицательных чисел\n");
			z = 0;
			for (int i = 0; i < Str; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					if (*(a + i*Col + j) < 0)
					{
						*(OtrMus + z) = *(a + i*Col + j);
						printf("%d\t", *(OtrMus + z));
						z++;
					}
				}
			}
			printf("\n");
		}
		free(a);
		free(MusKrTrem);
		free(PolMus);
		free(OtrMus);
	}
	else if (N1 == 5)
	{
		int *a = NULL;
		printf("Введите массив чисел\n");

		int Num;
		int i = 0;
		char c;
		do
		{
			printf("a[%d] = ", i);
			scanf("%d", &Num);
			a = (int *)realloc(a, (i + 1) * sizeof(int));
			a[i] = Num;
			i++;
			getchar();
			printf("Продолжить (y/n) ");
			c = getchar();
		} while (c == 'y');
		for (int j = 0; j < i; j++)
			printf("%d ", *(a + j));

		printf("\n");

		printf("Сумма четных элементов массива:\n");
		int Summ = 0;

		for (int j = 0; j < i; j++)
		{
			if (*(a + j) % 2 == 0)
				Summ += *(a + j);
		}
		printf("Summ = %d\n", Summ);
		free(a);
	}
	else if (N1 == 6)
	{
		int *mass = NULL;
		int N = 0;

		GenMassMalloc(mass, &N, -50, 50);

		if (mass == NULL)
		{
			printf("Память не выделена");
			exit(EXIT_FAILURE);
		}
		else
		{
			int NumOtr = 0;
			for (int i = 0; i < N; i++)
			{
				if (*(mass + i) < 0)
					NumOtr++;
			}
			printf("\nКоличество отрицательных элементов в массиве\n");
			printf("N = %d\n", NumOtr);
		}
	}
	else if (N1 == 7)
	{
		int *mass = NULL;
		int N = 0;

		GenMassMalloc(mass, &N, 1, 10);

		if (mass == NULL)
		{
			printf("Память не выделена");
			exit(EXIT_FAILURE);
		}
		else
		{
			int Proiz = 1;
			for (int i = 0; i < N; i++)
			{
				if (abs(*(mass + i)) < 7)
					Proiz *= *(mass + i);
			}
			printf("\nПроизведение элементов, модуль которых меньше 7\n");
			printf("N = %d\n", Proiz);
		}
	}
	else if (N1 == 8)
	{
		/*1.	Ввести вещественные числа.Создать из них массив.Определить индекс второго положительного элемента массива.*/

		int *mass = NULL;
		int N = 0;

		GenMassMalloc(mass, &N, -10, 10);

		printf("\n");

		int z = 0;
		int w = 0;

		int j = 0;

		do
		{
			if ((*(mass + j)) > 0)
				z++;
			w++;
			j++;

		} while (z != 2 && j < N);
		printf("\nИндекс второго положительного элемента i = %d \n", w);

		free(mass);
	}
	else if (N1 == 9)
	{
		/*Переставить элементы массива в обратном порядке*/

		int *mass = NULL;
		int N = 0;

		GenMassMalloc(mass, &N, -10, 10);

		int j = 0;
		int z = N - 1;
		int p = 0;
		for (int i = 0; i < N / 2; i++)
		{
			p = *(mass + i);
			*(mass + i) = *(mass + z);
			*(mass + z) = p;
			z--;
		}
		printf("\n Элементы в обратном порядке\n");
		for (int i = 0; i < N; i++)
		{
			printf("%d\t", *(mass + i));
		}
		printf("\n");
	}
	else if (N1 == 10)
	{
		/*Определить среднее арифметическое элементов массива, не кратных 3*/

		int *mass = NULL;
		int N = 0;

		GenMassMalloc(mass, &N, 1, 20);

		int SredAr = 0;
		int Summ = 0;
		int z = 0;

		for (int i = 0; i < N; i++)
		{
			if (*(mass + i) % 3 != 0)
			{
				Summ += *(mass + i);
				z++;
			}
		}
		SredAr = Summ / z;

		printf("\nСреднее арифметическое эл. не кратных трем Sred = %d\n", SredAr);
	}
	else if (N1 == 11)
	{
		/*Поменять местами первый и максимальный элементы массива*/

		int *mass = NULL;
		int N = 0;
		int Max = 0;

		GenMassMalloc(mass, &N, 1, 20);

		for (int i = 0; i < N; i++)
		{
			if (*(mass + i) > Max)
			{
				Max = *(mass + i);
			}
		}

		*mass = Max;

		printf("\n");
		for (int i = 0; i < N; i++)
		{
			printf("%d\t", *(mass + i));
		}
		printf("\n");
	}
	else if (N1 == 12)
	{
		/*Ввести в StringGrid массив из 10 целых чисел.Создать два новых массива – из четных и нечётных
		элементов исходного массива.Определить, в каком массиве больше элементов.*/

		int *mass = NULL;
		int *chetMass = NULL;
		int *nechetMass = NULL;
		int N = 0;
		int Max = 0;

		GenMassMalloc(mass, &N, 1, 20);

		int iChet = 0;
		int iNeChet = 0;
		for (int i = 0; i < N; i++)
		{
			if (*(mass + i) % 2 == 0 && *(mass + i) != 0)
			{
				chetMass = (int *)realloc(chetMass, (iChet + 1) * sizeof(int));
				*(chetMass + iChet) = *(mass + i);
				iChet++;
			}
			else if (*(mass + i) % 2 != 0)
			{
				nechetMass = (int *)realloc(nechetMass, (iNeChet + 1) * sizeof(int));
				*(nechetMass + iNeChet) = *(mass + i);
				iNeChet++;
			}
		}
		printf("\nЧетный массив:\n");

		for (int i = 0; i < iChet; i++)
		{
			printf("%d\t", *(chetMass + i));
		}

		printf("\nНетный массив:\n");

		for (int i = 0; i < iNeChet; i++)
		{
			printf("%d\t", *(nechetMass + i));
		}
		printf("\n");

		printf("ChetMass = %d, nechetMass = %d", iChet, iNeChet);
	}
	else if (N1 == 13)
	{

	}
	system("pause");
}