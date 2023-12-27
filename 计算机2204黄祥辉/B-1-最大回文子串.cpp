#define _CRT_SECURE_NO_WARNINGS



//暴力算法，时间复杂度为n^2 ,空间复杂度为n 
#include <iostream>
#include <cstdio>
#include <cstring>
#include<algorithm>

using namespace std;

int r[105];

//加工字符串
string GetNewStr(string& str) {
    string s = "#";
    for (int i = 0; str[i]; ++i) {
        (s += str[i]) += '#';
    }
    return s;
}

int main() {
    string str;
    cin >> str;
    str = GetNewStr(str);
    for (int i = 0; str[i]; ++i) {
        while (i - r[i] >= 0 && str[i - r[i]] == str[i + r[i]])  ++r[i];
        --r[i];//剪掉自身的
    }
    for (int i = 0; str[i]; ++i) {
        printf("%3c", str[i]);
    }
    printf("\n");
    for (int i = 0; str[i]; ++i) {
        printf("%3d", r[i]);
    }
    printf("\n");


    //打印字符串
    int max = 0;
    int max_len=0;
    for (int i = 0; str[i]; i++)
    {
        if (r[i] > max_len)
        {
            max = i;
            max_len = r[i];
        }
    }
    cout << max_len << ' ' << max<<endl;
    for (int i = max-max_len+1; i <= max + max_len+1; i+=2)
    {
        cout << str[i] << ' ';
    }
    return 0;
}



//马拉车算法
#include <iostream>
#include <cstdio>
#include <cstring>
#include<algorithm>

using namespace std;

int r[105];

//加工字符串
string GetNewStr(string& str) {
    string s = "#";
    for (int i = 0; str[i]; ++i) {
        (s += str[i]) += '#';
    }
    return s;
}

int main() {
    string str;
    cin >> str;
    str = GetNewStr(str);
    int c = 0, ans = 0;
    for (int i = 1; str[i]; ++i) {
        if (c + r[c] > i)  r[i] = min(r[2 * c - i], c + r[c] - i);//i没有超过右边界，如果大于，则直接使用，否则会超过
        while (i - r[i] >= 0 && str[i - r[i]] == str[i + r[i]])  ++r[i];
        --r[i];
        if (i + r[i] > c + r[c])  c = i;   //超过右边界，更新C的位置
        ans = max(ans, r[i]);
    }
  
    


    //打印字符串
    int max = 0;
    int max_len = 0;
    for (int i = 0; str[i]; i++)
    {
        if (r[i] > max_len)
        {
            max = i;
            max_len = r[i];
        }
    }
    cout << max_len << ' ' << max << endl;
    for (int i = max - max_len + 1; i <= max + max_len + 1; i += 2)
    {
        cout << str[i] << ' ';
    }
    return 0;
}
