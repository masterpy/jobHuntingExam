// qunaer1.cpp : 定义控制台应用程序的入口点。
// https://leetcode.com/problems/compare-version-numbers/

#include "stdafx.h"

#include<iostream>
#include<string>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
	int numOfLine = 0;
	cin >> numOfLine;
	cin.sync();
	string  inputStr;
	int maxA = 0;
	int maxC = 0;
	string msString;
	while (numOfLine>0)
	{
		getline(cin, inputStr);
		vector<string>  vecStr;
		int versNum = 2;

		string word;
		while (1)
		{
			int pos = inputStr.find('.');
			if (pos<0)
			{
				if (versNum == 0)
				{
					vecStr.push_back(inputStr);
				}
				else
				{
					vecStr.push_back(inputStr);
					vecStr.push_back("0");
				}
				break;
			}
			word = inputStr.substr(0, pos);
			inputStr = inputStr.substr(pos + 1);
			vecStr.push_back(word);
			versNum--;
		}

		int a = std::atoi(vecStr[0].c_str());
		int b = std::atoi(vecStr[1].c_str());
		int c = std::atoi(vecStr[2].c_str());

		if ((a>maxA) && (b % 2 == 0))
		{
			maxA = a;
			maxC = c;
			if (vecStr[2] == "0")
			{
				msString = vecStr[0] + "." + vecStr[1];
			}
			else
			{
				msString = vecStr[0] + "." + vecStr[1] + "." + vecStr[2];
			}
		}
		else 
			if (c>maxC && (b % 2 == 0))
			{
			maxA = a;
			maxC = c;
			if (vecStr[2] == "0")
			{
				msString = vecStr[0] + "." + vecStr[1];
			}
			else
			{
				msString = vecStr[0] + "." + vecStr[1] + "." + vecStr[2];
			}
		}
		cout << msString;
		numOfLine--;
	}
}