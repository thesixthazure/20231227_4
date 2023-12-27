#define _CRT_SECURE_NO_WARNINGS


//测试数据
//5 5
//1 3 5 7 9
//2 4 6 8 10



#include<iostream>

using namespace std;

const int N = 11;

int a1[N], a2[N], b[N];

int n, m;


int main()
{
	cin >> n >> m;
	for (int i =0; i <n; i++)
	{
		cin >> a1[i];
	}
	for (int i =0; i <m; i++)
	{
		cin >> a2[i];
	}

	int i = 0, j = 0;
	int k = 0;
	while (i < m && j < n)
	{
		if (a1[i] <= a2[j])
		{
			b[k++] = a1[i++];
		}
		else
		{
			b[k++] = a2[j++];
		}
	}

	while (i == m && j < n)b[k++] = a2[j++];
	while (j == n && i < m)b[k++] = a1[i++];

	for (int i = 0; i < m + n; i++)
	{
		cout << b[i] << ' ';
	}
	cout << endl;
	double mid;
	if ((m + n) % 2 == 0)
	{
		int l = (m + n) / 2-1;
		int r = l+1;
		mid = (b[l] + b[r]) / 2.0;
	}
	else
	{
		int l = (m + n) / 2.0-1;
		mid = b[l];
	}

	cout <<"中位数是：" << mid;

	return 0;
}