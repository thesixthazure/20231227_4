#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int a = 0, b = 0, c = 0, d = 0;

	
		while (n >= 25)
		{
			n -= 25;
			a++;
		}
		while (n >= 10)
		{
			n -= 10;
			b++;
		}
		while (n >= 5)
		{
			n -= 5;
			c++;
		}
		d = n;
	

		cout << "��Ҫ25�֣�" << a << endl; 
		cout << "��Ҫ10�֣�" << b << endl;
		cout << "��Ҫ5�֣�" << c << endl;
		cout << "��Ҫ1�֣�" <<d << endl;
}