#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 20;
int a[N];


int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	n -= 2;
	int index = 2;
	int cnt = 0;

	int flag = 0;
	while (n--)
	{
		if ((a[index] - a[index - 1]) * (a[index] - a[index + 1]) > 0)
		{
			//cout << "Yes" << endl;
		}
		else
		{
			flag = 1;
			cnt++;
			//cout << "No"<<endl;
		}
	}

	if (!flag)cout << "�ǰڶ�" << endl;
	else cout << "���ǰڶ�" << " " << "��Ҫɾ��������"<<cnt;

	return 0;
	

}