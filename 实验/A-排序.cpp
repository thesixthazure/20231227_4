#define _CRT_SECURE_NO_WARNINGS

/*
 10
 6 12 458 5 4 28 19 1230 9 47
 */

//快排
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 1e6 + 10;

int q[N], n;

void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int i = l - 1, j = r + 1;
    int x = q[l + r >> 1];

    while (i < j)
    {
        while (q[++i] < x);
        while (q[--j] > x);
        if (i < j) swap(q[i], q[j]);
    }

    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);

}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++) cout << q[i] << ' ';


    return 0;
}



//归并排序
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 1e6 + 10;

int q[N], tmp[N], n;


void merge_sort(int q[], int l, int r)
{
    if (l >= r) return;
    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    int k = 0;
    int i = l;
    int j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    }
    while (i <= mid)tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];

    for (i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];

}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }

    merge_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++) cout << q[i] << ' ';

    return 0;
}



//希尔排序
#include<iostream>

using namespace std;

const int N = 110;

void shell(int a[], int n)
{
    int i, j, d;
    int temp;
    d = n / 2;
    while (d > 0)
    {
        for (i = d; i < n; i++)
        {
            temp = a[i];
            j = i - d;
            while (j >= 0 && temp < a[j])
            {
                a[j + d] = a[j];
                j = j - d;
            }
            a[j + d] = temp;
        }
        d = d / 2;
    }
}

int main()
{
    int n = 10;
    int a[11] = { 6, 12, 458, 5, 4, 28, 19, 1230, 9, 47 };

    shell(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }


    /*for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }*/

    return 0;
}


//堆排序
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e6 + 10;

int h[N], n, m;
int cnt;

void down(int u)
{
    int t = u;
    if (u * 2 <= cnt && h[u * 2] < h[t])t = u * 2;
    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t])t = u * 2 + 1;
    if (u != t)
    {
        swap(h[u], h[t]);
        down(t);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)cin >> h[i];

    cnt = n;
    for (int i = n / 2; i; i--)down(i);//最后一个非叶子节点开始排


    while (m--)
    {
        cout << h[1] << ' ';
        h[1] = h[cnt--];
        down(1);
    }



    return 0;
}

//基数排序
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 2020;
int b[N];

int main()
{
    int n, x;
    int sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (b[x])continue;
        b[x]++;
        sum++;
    }
    for (int i = 1; i <= 1500; i++)
    {
        if (b[i]) cout << i << ' ';
    }

    return 0;
}
