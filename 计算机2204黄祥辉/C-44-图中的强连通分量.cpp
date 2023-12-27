#define _CRT_SECURE_NO_WARNINGS


/*
测试数据
5
0 1
1 3
2 1
3 0
4 2

*/


#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 10;
int h[N], e[N], ne[N], idx;
vector<int> v;
bool st[N];
int flag;
int cnt;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}


bool dfs(int u)
{
    if (!st[u])
    {
        v.push_back(u);
        st[u] = true;
    }
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (v.size() == 5)
        {
            return true;
        }
        if (!st[j])
        {
            st[j] = true;
            v.push_back(j);
            dfs(j);
            st[j] = false;

        }
        cnt++;
        if (cnt > 5)
        {
            return false;
        }

    }
    return false;
}

int main()
{
    /*add(0, 1);
    add(1, 3);
    add(2, 1);
    add(3, 0);
    add(4, 2);*/

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }


    for (int i = 0; i < 5; i++)
    {
        cnt = 0;
        v.clear();
        memset(st, false, sizeof st);
        if (dfs(i))
        {
            cout << i << "是强连通分量" << endl;
        }
        else
        {
            flag = 1;
            cout << i << "不是强连通分量" << endl;
        }
    }

   


    /*cnt = 0;
    if (dfs(4))
    {
        cout << "Y" << endl;
    }
    else
    {
        cout << "N" << endl;
    }*/





    return 0;
}