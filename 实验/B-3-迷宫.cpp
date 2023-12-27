#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int N = 510;

int g[N][N], d[N][N], n, m;

typedef pair<int, int> PII;

int bfs()
{
    int stx, sty, edx, edy;
    cin >> stx >> sty >> edx >> edy;

    queue<PII> q;

    memset(d, -1, sizeof d);
    d[stx-1][sty-1] = 0;
    q.push({ stx-1,sty-1 });

    int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];

            if (x >= 0 && x < n && y >= 0 && y < m && d[x][y] == -1 && g[x][y] == 0)
            {
                d[x][y] = d[t.first][t.second] + 1;
                q.push({ x,y });
            }
        }
    }

    return d[edx-1][edy-1];

}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }
    }

    cout << bfs();


    return 0;
}


#include<iostream>
#include<queue>

using namespace std;

const int maxn = 1000;
int n, m;
int maze[maxn][maxn];
int startX, startY, endX, endY;
int vis[maxn][maxn];
int dis[maxn][maxn];

//递归算法实现
void dfs(int x, int y, int step) {
    if (x < 0 || x >= n || y < 0 || y >= m || maze[x][y] == 1 || vis[x][y] == 1) return;//越界或无法访问
    if (x == endX && y == endY) {
        dis[x][y] = min(dis[x][y], step);
        return;
    }
    vis[x][y] = 1;//标记该格子已经访问过
    dis[x][y] = min(dis[x][y], step);//记录到该格子的最短距离
    dfs(x + 1, y, step + 1);
    dfs(x - 1, y, step + 1);
    dfs(x, y + 1, step + 1);
    dfs(x, y - 1, step + 1);
    vis[x][y] = 0;
}



int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            vis[i][j] = 0;
            dis[i][j] = 0x3f3f3f3f;
        }
    }
    cin >> startX >> startY >> endX >> endY;
    dfs(startX-1, startY-1, 0);
    cout << dis[endX-1][endY-1] << endl;
    
    return 0;
}