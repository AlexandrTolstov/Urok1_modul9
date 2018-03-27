#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <cmath>

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

		srand(time(0));

		printf("Введите количесво строк массива Str = ");
		scanf("%d", &Str);
		printf("Введите количесво столбцов массива Col = ");
		scanf("%d", &Col);

		printf("Str = %d\n", Str);
		printf("Col = %d\n", Col);
		a = (int *)malloc((Str*Col) * sizeof(int));
		b = (int *)malloc((Col) * sizeof(int));
		c = (int *)malloc((Str) * sizeof(int));

		if (a == NULL)
		{
			printf("Память не выделена");
			exit(EXIT_FAILURE);
		}
		else
		{
			for (int i = 0; i < Str; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					*(a + i*Str + j) = -50 + rand() % (50 + 50);
					printf("%d\t", *(a + i*Str + j));
				}
				printf("\n");
			}

			printf("\n");
			printf("Наибольший по модулю из столбца\n");
			int MaxMod = 0;
			for (int i = 0; i < Col; i++)
			{
				for (int j = 0; j < Str; j++)
				{
					if (abs(*(a + i + j*Str)) > abs(MaxMod))
						MaxMod = *(a + i+ j*Str);
				}

				*(b + i) = MaxMod;
				printf("%d\t", *(b + i));
				MaxMod = 0;
			}
			printf("\n");

			printf("Наибольший по модулю из строки\n");
			MaxMod = 0;

			for (int i = 0; i < Str; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					if (abs(*(a + i*Str + j)) > abs(MaxMod))
						MaxMod = *(a + i*Str + j);
				}

				*(b + i) = MaxMod;
				printf("%d\n", *(b + i));
				MaxMod = 0;
			}
			printf("\n");
		}
	}
	else if (N1 == 2)
	{
		
	}
	else if (N1 == 3)
	{
		
	}
	else if (N1 == 4)
	{
		
	}
	else if (N1 == 10)
	{
		
	}
	else if (N1 == 11)
	{
		
	}
	else if (N1 == 12)
	{
		
	}
	else if (N1 == 13)
	{
		int len = 0;
		scanf("%d", &len);

		float *p = NULL;
		//p = (int *)malloc(sizeof(int)*len);
		p = (float *)calloc(len, sizeof(float));
		if (p == NULL)
		{
			printf("Память не выделена");
			exit(EXIT_FAILURE);
		}
		else
		{
			int i = 0;
			int number = 0;

			printf("%d", len);

			printf("Enter val (q for exit): ");
			while (i < len && scanf("%f", &p[i]) == 1)
				i++;

			printf("Enter %d elements: \n", number = i);

			printf("\n-------------------------\n");
			for (i = 0; i < number; i++)
			{
				printf("%7.2f \n", p[i]);
			}
		}
		free(p);
	}
	else if (N1 == 14)
	{
		
	}
	system("pause");
}