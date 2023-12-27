#define _CRT_SECURE_NO_WARNINGS

//测试用例
//第一行为n,k1,k2
//3 2 3
//1 2 3
//2 1 3
//3 2 1
//2 1 3
//2 3 6


#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 10;

int main()
{
    int g1[N][N];
    int g2[N][N];
    int g3[N][N];
    int g4[N][N];
    memset(g1, 0, sizeof g1);
    memset(g2, 0, sizeof g2);
    memset(g3, 0, sizeof g3);
    memset(g4, 0, sizeof g4);

    int n,k1, k2;
    cin >> n >> k1 >> k2;
    for(int i=0;i<k1;i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g1[x][y]= z;
    }
    for (int i = 0; i < k2; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g2[x][y]= z;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            g3[i][j] = g1[i][j] + g2[i][j];
        }
    }
    cout << endl << "相加后的三元组：" << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (g3[i][j])
            {
                cout << i << ' ' << j << ' ' << g3[i][j] << endl;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            g4[i][j] = g1[i][j] * g2[i][j];
        }
    }

    cout << endl << "相乘后的三元组：" << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (g4[i][j])
            {
                cout << i << ' ' << j << ' ' << g4[i][j] << endl;
            }
        }
    }

    return 0;
}