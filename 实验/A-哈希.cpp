#define _CRT_SECURE_NO_WARNINGS


//开放寻址法
//开放寻址法的冲突率在负载因子较高时会有一定的上升趋势。

//测试数据
//3
//I 111 a a
//I 222 b b
//Q 111

//I表示插入，Q表示是否存在
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 200003, null = 0x3f3f3f3f;

struct h
{
	int phone;
	char name;
	char address;
}h[N];

int find(int x)
{
	int t = (x % N + N) % N;
	while (h[t].phone != null && h[t].phone != x)
	{
		t++;
		if (t == N) t = 0;
	}
	return t;
}


int main()
{
	memset(h, 0x3f, sizeof h);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int phone;
		char name;
		char address;
		char op;
		cin >> op;
		if (op == 'I')
		{
			cin >> phone >> name>>address;
			h[find(phone)].phone = phone;
			h[find(phone)].name = name;
			h[find(phone)].address = address;
		}
		else
		{
			cin >> phone;
			if (h[find(phone)].phone == null)puts("No");
			else puts("Yes");
		}
	}

	return 0;
}


//平方探测法
//3
//I 111 a a
//I 222 b b
//Q 111

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 200003, null = 0x3f3f3f3f;

struct h
{
	int phone;
	char name;
	char address;
}h[N];

int find(int x)
{
	int t = (x % N + N) % N;
	int d = 1;
	while (h[t].phone != null && h[t].phone != x)
	{
		//t++;
		int cnt = 0;
		if (cnt % 2 == 0)
		{
			d = d * d;//往前平方
		}
		else
		{
			d = -d * d;//往后平方
		}
		t = (t + d + N) % N;
		d++, cnt++;
		if (t == N) t = 0;
	}
	return t;
}


int main()
{
	memset(h, 0x3f, sizeof h);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int phone;
		char name;
		char address;
		char op;
		cin >> op;
		if (op == 'I')
		{
			cin >> phone >> name >> address;
			h[find(phone)].phone = phone;
			h[find(phone)].name = name;
			h[find(phone)].address = address;
		}
		else
		{
			cin >> phone;
			if (h[find(phone)].phone == null)puts("No");
			else puts("Yes");
		}
	}

	return 0;
}


//拉链法
//在负载因子较高时，拉链法的冲突率相对较低。
//测试数据
5
I 111 a a
I 222 b b
I 333 c c
Q 222
Q 555
//I表示新增数据，Q表示查询是否存在
#include<algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100003;

int h[N], e[N], ne[N], idx;
char name[N], address[N];

void insert(int x, char a, char b)
{
	int k = (x % N + N) % N;
	e[idx] = x;
	ne[idx] = h[k];
	name[idx] = a;
	address[idx] = b;
	h[k] = idx++;
}

bool find(int x)
{
	int k = (x % N + N) % N;
	for (int i = h[k]; i != -1; i = ne[i])
		if (e[i] == x)
			return true;

	return false;
}

int main()
{
	int n;
	cin >> n;

	memset(h, -1, sizeof h);

	while (n--)
	{
		char op;
		int x;
		char a, b;

		cin >> op >> x;

		if (op == 'I')
		{
			cin >> a >> b;
			insert(x, a, b);

		}
		else
		{
			if (find(x)) puts("Yes");
			else puts("No");
		}
	}

	return 0;
}
