#define _CRT_SECURE_NO_WARNINGS


/*


*/

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 100;

//const int N = 15;
//int g[N][N];
//int s1[N], s2[N];//时间最早最晚
//int a1[N], a2[N];//活动最早最晚

int h_early[N], h_late[N], e[N * 2], ne[N * 2], idx;
int w[N * 2];
int n, m;//邻接表初始化

int v_early[N], v_late[N];

int d[N], s[N];//拓扑排序用

vector<int> p;
vector<vector<int>> res;

void add(int h[], int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool topsort()
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)s[++tt] = i;
    }
    while (hh <= tt)
    {
        int t = s[hh++];

        for (int i = h_early[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (--d[j] == 0)s[++tt] = j;
        }
    }

    return tt == n - 1;
}

void a()
{
    topsort();
    //最早
    v_early[1] = 0;
    for (int k = 0; k < n; k++) {
        int v_earlyr = s[k];
        for (int i = h_early[v_earlyr]; i != -1; i = ne[i]) {
            int j = e[i];
            v_early[j] = max(v_early[j], v_early[v_earlyr] + w[i]);
        }
    }
    //最晚
    memset(v_late, 0x3f, sizeof v_late);
    v_late[n] = v_early[n];
    for (int k = n - 1; k >= 0; k--) {
        int v_earlyr = s[k];
        for (int i = h_late[v_earlyr]; i != -1; i = ne[i]) {
            int j = e[i];
            v_late[j] = min(v_late[j], v_late[v_earlyr] - w[i]);
        }
    }
}

//递归获取没有时间差的
void dfs(int u) {

    p.push_back(u);

    if (h_early[u] == -1) {
        res.push_back(p);
    }

    for (int i = h_early[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (v_late[j] - v_early[j] == 0)
            dfs(j);
    }

    p.pop_back();
}


int main()
{

    //int n = 7, m = 8;
    //g[0][1] = 2;
    //g[0][2] = 4;
    //g[1][3] = 3;
    //g[2][3] = 5;
    //g[3][4] = 7;
    //g[3][5] = 3;
    //g[4][5] = 2;
    //g[5][6] = 1;

    //// Step 1: 求解最早开始时间和最早完成时间
    //for (int i = 0; i < n; i++)
    //{
    //    for (int j = 0; j < n; j++)
    //    {
    //        if (g[i][j] != 0)
    //        {
    //            s1[j] = max(s1[j], s1[i] + g[i][j]);
    //        }
    //    }
    //}

    cin >> n >> m;
    memset(h_early, -1, sizeof h_early);
    memset(h_late, -1, sizeof h_late);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(h_early, a, b, c);
        add(h_late, b, a, c);//存反向的
        d[b]++;
    }


    a();

    dfs(1);

    cout <<"关键路径数量：" << res.size();

    return 0;
}



//
//
//#include<iostream>
//
//using namespace std;
//
//const int N = 15;
//int g[N][N];
//int s1[N], s2[N];//时间最早最晚
//int a1[N], a2[N];//活动最早最晚
//
//
//int main()
//{
//    int n = 7, m = 8;
//    g[0][1] = 2;
//    g[0][2] = 4;
//    g[1][3] = 3;
//    g[2][3] = 5;
//    g[3][4] = 7;
//    g[3][5] = 3;
//    g[4][5] = 2;
//    g[5][6] = 1;
//
//    // Step 1: 求解最早开始时间和最早完成时间
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (g[i][j] != 0)
//            {
//                s1[j] = max(s1[j], s1[i] + g[i][j]);
//            }
//        }
//    }
//
//    // 初始化最早完成时间
//    int max_end_time = 0;
//    for (int i = 0; i < n; i++)
//    {
//        max_end_time = max(max_end_time, s1[i]);
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        a1[i] = max_end_time;
//    }
//
//    // Step 2: 求解最晚开始时间和最晚完成时间
//    for (int i = n - 1; i >= 0; i--)
//    {
//        for (int j = n - 1; j >= 0; j--)
//        {
//            if (g[i][j] != 0)
//            {
//                a2[i] = min(a2[i], a2[j] - g[i][j]);
//            }
//        }
//    }
//
//    // 初始化最晚开始时间
//    int min_start_time = a2[0];
//    for (int i = 1; i < n; i++)
//    {
//        min_start_time = min(min_start_time, a2[i]);
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        s2[i] = min_start_time;
//    }
//
//    // Step 3: 找出关键路径
//    cout << "关键路径上的活动：";
//    for (int i = 0; i < n; i++)
//    {
//        if (s1[i] == s2[i] && a1[i] == a2[i])
//        {
//            cout << i << " ";
//        }
//    }
//    cout << endl;
//
//    return 0;
//}