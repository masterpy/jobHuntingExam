// wangyigame2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <string>
#include <fstream>
using namespace std;

int CharType(char c)
{
	if (c == '(')
		return -1;
	if (c == ')')
		return -2;
	if (int(c) > 60)
		return -(c - 'A') - 3;
	else
		return c - '0';
}

int CharLength(string s, int point)
{
	int result = 0;
	while (point + 1 < s.length()&&CharType(s[point+1])>=0)
	{
		result = result * 10 + CharType(s[point + 1]);
		point++;
	}
	return result == 0 ? 1 : result;
}

int main()
{
	ifstream in(".\\input.txt");
	cin.rdbuf(in.rdbuf());

	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		stack<int> s;
		s.push(0);
		for (int k = 0; k < input.length(); k++)
		{
			int type = CharType(input[k]);
			if (type >= 0)
				continue;
			if (type==-1)
			{
				s.push(0);
				continue;
			}
			if (type<-2)
			{
				s.top() += CharLength(input, k);
			}
			if (type==-2)
			{
				int temp = s.top();
				s.pop();
				s.top() += temp* CharLength(input, k);
			}
		}
		cout << s.top() << endl;
	}
	system("pause");
	return 0;
}