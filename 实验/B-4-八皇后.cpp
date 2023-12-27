#define _CRT_SECURE_NO_WARNINGS


//.表示某一个位置的方格状态为空，Q 表示某一个位置的方格上摆着皇后。
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 10;

int n, path[N];
char g[N][N];
bool col[N], dg[N * 2], udg[N * 2];

void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i++) puts(g[i]);
        puts("");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!col[i] && !dg[u + i] && !udg[n - u + i])
        {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false;
            g[u][i] = '.';
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            g[i][j] = '.';
        }
    }

    dfs(0);

    return 0;
}