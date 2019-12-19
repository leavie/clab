#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct polynominalTerm {
	double coef;
	int expo;
};

typedef struct polynominalTerm poly;

void clear(poly input[]);
void mutiple(poly a[], poly b[], poly result[]);
void inputTerm(poly input[], double coef, int expo);
void add(poly a[], poly b[], poly result[]);
int compare(int i, int j);
void print(poly input[]);

int main() 
{
	poly a[MAX], b[MAX], addResult[MAX], mutiResult[MAX];
	int expo,termOfA,termOfB;
	double coef;

	clear(a), clear(b), clear(addResult), clear(mutiResult);

	scanf("%d", &termOfA);
	for (int i = 0; i < termOfA; i++) 
	{
		scanf("%lf %d", &coef, &expo);
		inputTerm(a, coef, expo);
	}

	scanf("%d", &termOfB);
	for (int i = 0; i < termOfB; i++)
	{
		scanf("%lf %d", &coef, &expo);
		inputTerm(b, coef, expo);
	}
		
	print(a), print(b);

	add(a, b, addResult);

	print(addResult);

	mutiple(a, b, mutiResult);

	print(mutiResult);



}

void clear(poly input[])
{
	for (int i = 0; i < MAX; i++)
	{
		input[i].coef = 0;
		input[i].expo = 0;
	}

	return;
}

void mutiple(poly a[], poly b[], poly result[])
{
	int i = 0, j = 0;
	poly temp[MAX],prev[MAX];

	clear(temp), clear(prev);

	while (a[i].coef != 0 || a[i].expo != 0) 
	{
		while (b[j].coef != 0 || b[j].expo != 0) 
		{
			inputTerm(temp, a[i].coef * b[j].coef, a[i].expo + b[j].expo);
			j++;
		}
		add(temp, prev, result);
		clear(temp);
		
		for (int k = 0; k < MAX; k++) 
		{
			prev[k].coef = result[k].coef;
			prev[k].expo = result[k].expo;
		}
		
		j = 0;

		i++;
	}
}

void inputTerm(poly input[], double coef, int expo) 
{
	int i = 0;
	while (1) 
	{
		if (input[i].expo > expo) 
		{
			i++;
			continue;
		}
		else if (input[i].expo == expo) 
		{
			double sum = input[i].coef + coef;

			if (sum)
			{
				input[i].coef = sum;
				input[i].expo = expo;
				return;
			}
			else 
			{
				int count = 0;
				for (int j = i + 1; j < MAX; j++) 
					if (!(input[j].coef == 0 && input[j].expo == 0)) 
						count++;
					else
						break;

				for (int j = i; j < i + count; j++)
					input[j] = input[j + 1];

				return;
			}
		}
		else 
		{
			int count = 0;
			for (int j = i; j < MAX; j++) 
				if (!(input[j].coef == 0 && input[j].expo == 0))
					count++;
				else
					break;

			for (int j = i; j < i + count; j++)
				input[j + 1] = input[j];

			input[i].coef = coef;
			input[i].expo = expo;

			return;
		}
	}
}

void add(poly a[], poly b[], poly result[])
{
	int i = 0, j = 0, cur = 0;

	while ((a[i].coef != 0 || a[i].expo != 0) && (b[j].coef != 0 || b[j].expo != 0)) 
	{
		double sum;

		switch (compare(a[i].expo, b[j].expo)) 
		{
			case 1:
				result[cur].expo = a[i].expo;
				result[cur].coef = a[i].coef;
				cur++, i++;
				break;
			case 0:
				sum = a[i].coef + b[j].coef;
				if (sum)
				{
					result[cur].coef = sum;
					result[cur].expo = a[i].expo;
					cur++;
				}
				i++, j++;
				break;
			case -1:
				result[cur].expo = b[j].expo;
				result[cur].coef = b[j].coef;
				cur++, j++;
				break;
		}
	}

	while (a[i].coef != 0 || a[i].expo != 0) 
	{
		result[cur].expo = a[i].expo;
		result[cur].coef = a[i].coef;
		cur++, i++;
	}

	while (b[j].coef != 0 || b[j].expo != 0)
	{
		result[cur].expo = b[j].expo;
		result[cur].coef = b[j].coef;
		cur++, j++;
	}
}

void print(poly input[]) 
{
	int i = 0;
	if (!input[i].coef)
		return;
	else if (input[i].coef == 1)
		printf("X^%d ", input[i].expo);
	else if (input[i].expo != 0) 
		printf("%lfX^%d ", input[i].coef, input[i].expo);
	else
		printf("%lf", input[i].coef);

	i++;

	while (input[i].coef != 0 || input[i].expo != 0)
	{
		if (input[i].coef == 1)
			printf("+ X^%d ", input[i].expo);
		else if (input[i].expo != 0)
			printf("+ %lfX^%d ", input[i].coef, input[i].expo);
		else
			printf("+ %lf", input[i].coef);
		i++;
	}
	printf("\n");
}

int compare(int i, int j) 
{
	if (i > j)
		return 1;
	else if (i == j)
		return 0;
	else
		return -1;
}