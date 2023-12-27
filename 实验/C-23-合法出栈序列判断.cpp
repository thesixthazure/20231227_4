#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
const int N = 11;

char stk[N];
int tt;

int main()
{
	string s = "abcde";
	int n = s.size();
	string b;
	cin >> b;
	for (int i = 0; i < n; i++)
	{
		stk[--tt] = b[i];
	}
	int flag = 0;
	int j = 0;
	while (tt)
	{
		if (stk[tt] == s[j]) {
			tt--;
			j++;
		}
		else
		{
			flag = 1;
		}
	}

	if (!flag)
	{
		cout << "Y";
	}
	else
	{
		cout << "N";
	}




	return 0;
}