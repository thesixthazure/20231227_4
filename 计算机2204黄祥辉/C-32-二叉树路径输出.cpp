#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stack>

using namespace std;


const int N = 20, M = 2 * N;

int pre[N];
int w[N], h[N], ne[M], e[M], idx;
int end;
int v[N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u)
{
	if (u == 15)
	{
		stack<int> q;
		int k = u;
		while (k != -1&&k!=0)
		{
			q.push(k);
			int c = k;
			k = pre[k];
			pre[c] = -1;
		}

		while (q.size())
		{
			cout << q.top();
			q.pop();
			cout << "->";
		}
		cout << endl;
		return;
	}
	for (int i = h[u]; i != -1; i=ne[i])
	{
		int j = e[i];
		if (!v[j])
		{
			pre[j] = u;
			v[j] = 1;
			dfs(j);
			v[j] = 0;
			pre[j] = -1;
		}
	}
}

int main()
{
	//将F映射成数字，是15
	memset(h, -1, sizeof h);
	add(1, 2);
	add(1, 3);
	add(2, 4);
	add(2, 8);
	add(8, 15);

	dfs(1);


	return 0;
}