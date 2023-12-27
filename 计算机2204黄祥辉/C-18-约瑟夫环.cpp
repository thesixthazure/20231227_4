#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);
	int c = 0;
	int m = 0;
	int a[10];
	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
	}
	while (n > 1)
	{
		for (int i = 0; i < n; i++)
		{
			c++;
			if (c == 3)
			{
				for (int j = i + 1; j < n; j++)
				{
					a[j - 1] = a[j];
				}
				m++;
				c = 0;
			}

		}
		n = n - m;

	}
	printf("%d ", a[0]);



	return 0;
}
