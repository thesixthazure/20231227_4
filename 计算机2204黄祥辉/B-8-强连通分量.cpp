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
    e[idx] = b; 
    ne[idx] = h[a];
    h[a] = idx++;
}

//bool dfs(int u)
//{
//    if (!st[u])
//    {
//        v.push_back(u);
//        st[u] = true;
//    }
//    for (int i = h[u]; i != -1; i = ne[i])
//    {
//        int j = e[i];
//        if (v.size() == 5)
//        {
//            return true;
//        }
//        if (!st[j])
//        {
//            st[j] = true;
//            v.push_back(j);
//            dfs(j);
//            st[j] = false;
//
//        }
//        cnt++;
//        if (cnt > 5)
//        {
//            return false;
//        }
//
//    }
//    return false;
//}


void dfs(int u)
{
    if (v.size() == 5)
    {
        flag = 1;
        for (int t : v)
        {
            cout << t << ' ';
        }
        cout << endl;
    }
    if (!st[u])
    {
        v.push_back(u);
        st[u] = true;
    }
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];

        if (!st[j])
        {
            v.push_back(j);
            st[j] = true;
            dfs(j);
            st[j] = false;
            v.pop_back();
        }
    }

    return;
}



int main()
{
    memset(h, -1, sizeof h);
    add(0, 1);
    add(0, 4);
    add(1, 3);
    add(2, 1);
    add(2, 4);
    add(3, 0);
    add(3, 2);
    add(4, 2);

    /*int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }*/


    for (int i = 0; i < 5; i++)
    {
        v.clear();
        memset(st, false, sizeof st);
        dfs(i);
        if (flag)
        {
            cout << i << " 可达所有" << endl;
            cnt++;
        }
        else
        {
            cout << i << " 不可达所有" << endl;
        }
        flag = 0;

    }

    ///*if (!flag)
    //{
    //    cout << "Yes" << endl;
    //}
    //else
    //{
    //    cout << "No" << endl;
    //}*/


  /*  cnt = 0;
    dfs(0);*/
    /*if (dfs(0))
    {
        cout << "Y" << endl;
    }
    else
    {
        cout << "N" << endl;
    }*/


    if (cnt == 5)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }




    return 0;
}