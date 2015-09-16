// wangyigame1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

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
		int result[4];
		for (int k = 0; k < 4; k++)
		{
			result[k] = 0;
		}
		getline(cin, input);
		for (int k = 0; k < input.length(); k++)
		{
			if (input[k] == '9')
				result[0]++;
			else
				if (input[k] == '7' &&result[0] > result[1])
					result[1]++;
				else
					if (input[k] == '0'&&result[1] > result[2])
						result[2]++;
					else
						if (input[k] == '6' &&result[2] > result[3])
							result[3]++;
		}
		cout << result[3] << endl;
	}
	system("pause");
	return 0;
}