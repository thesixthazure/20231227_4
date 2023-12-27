#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;


void get(string &s) {
    int slow = 0; 
    for (int i = 0; i < s.size(); ++i) { 
        if (s[i] != ' ') { 
            if (slow != 0) s[slow++] = ' '; 
            while (i < s.size() && s[i] != ' ') { 
                s[slow++] = s[i++];
            }
        }
    }
    s.resize(slow); 

}


int main()
{
	string s;
    getline(cin,s);

    //cout << s;
	get(s);

	cout << s;

	return 0;
}