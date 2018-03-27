#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <Windows.h>
#include <time.h>


void main() {

	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N1 = 0;
	printf("¬ведите номер задани€\nN = ");

	scanf("%d", &N1);

	if (N1 == 1)
	{
		
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
			printf("ѕам€ть не выделена");
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
		/*a.—формировать одномерный массив, каждый элемент которого равен сумме четных положительных
		элементов соответствующего столбца двумерного массива*/

		int *a = NULL;
		int *b = NULL;
		int Str = 0;
		int Col = 0;

		srand(time(0));

		printf("¬ведите количесво строк массива Str = ");
		scanf("%d", &Str);
		printf("¬ведите количесво столбцов массива Col = ");
		scanf("%d", &Col);

		a = (int *)malloc((Str*Col) * sizeof(int));
		b = (int *)malloc((Col) * sizeof(int));

		if (a == NULL || b == NULL)
		{
			printf("ѕам€ть не выделена");
			exit(EXIT_FAILURE);
		}
		else
		{
			for (int i = 0; i < Col; i++)
			{
				for (int j = 0; j < Str; j++)
				{
					*(a + i*Col + j) = -20 + rand() % (50 + 20);
					printf("%d\t", *(a + i*Col + j));
				}
				printf("\n");
			}

			printf("\n");
			int Sum = 0;
			for (int i = 0; i < Col; i++)
			{
				for (int j = 0; j < Str; j++)
				{
					if (*(a + i*Col + j) > 0 && *(a + i*Col + j) % 2 == 0)
						Sum += *(a + i*Col + j);
				}

				*(b + i) = Sum;
				printf("%d\n", *(b + i));
				Sum = 0;
			}
		}
	}
	system("pause");
}