#define _CRT_SECURE_NO_WARNINGS



//�����㷨��ʱ�临�Ӷ�Ϊn^2 ,�ռ临�Ӷ�Ϊn 
#include <iostream>
#include <cstdio>
#include <cstring>
#include<algorithm>

using namespace std;

int r[105];

//�ӹ��ַ���
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
        --r[i];//���������
    }
    for (int i = 0; str[i]; ++i) {
        printf("%3c", str[i]);
    }
    printf("\n");
    for (int i = 0; str[i]; ++i) {
        printf("%3d", r[i]);
    }
    printf("\n");


    //��ӡ�ַ���
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



//�������㷨
#include <iostream>
#include <cstdio>
#include <cstring>
#include<algorithm>

using namespace std;

int r[105];

//�ӹ��ַ���
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
        if (c + r[c] > i)  r[i] = min(r[2 * c - i], c + r[c] - i);//iû�г����ұ߽磬������ڣ���ֱ��ʹ�ã�����ᳬ��
        while (i - r[i] >= 0 && str[i - r[i]] == str[i + r[i]])  ++r[i];
        --r[i];
        if (i + r[i] > c + r[c])  c = i;   //�����ұ߽磬����C��λ��
        ans = max(ans, r[i]);
    }
  
    


    //��ӡ�ַ���
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
