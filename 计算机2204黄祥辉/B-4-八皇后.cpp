#define _CRT_SECURE_NO_WARNINGS


//.��ʾĳһ��λ�õķ���״̬Ϊ�գ�Q ��ʾĳһ��λ�õķ����ϰ��Żʺ�
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