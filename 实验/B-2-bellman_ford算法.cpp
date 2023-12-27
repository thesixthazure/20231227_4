#define _CRT_SECURE_NO_WARNINGS



#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 510, M = 1e5 + 10;

int n, m, k, dist[N], back[N];

struct edge
{
    int a, b, w;
}e[M];

void bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[2] = 0;//源点
    memcpy(back, dist, sizeof dist);
    for (int j = 0; j < m; j++)
    {
        int a = e[j].a, b = e[j].b, w = e[j].w;
        dist[b] = min(dist[b], back[a] + w);//松弛操作，back数组用于存储上次结果
     }
    
}

int main()
{
    cin >> n >> m ;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        e[i] = { a,b,w };
    }

    bellman_ford();

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] > 0x3f3f3f3f / 2)puts("INF");
        else cout << dist[i]<<endl;
    }
   



    return 0;
}