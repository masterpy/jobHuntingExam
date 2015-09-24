// qunaer2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;
using std::sort;
#define size 15
int a[size], b[size], c[size];

void func(int length1, int length2, int length3)
{
	sort(a, a + length1);
	sort(b, b + length2);
	sort(c, c + length3);
	int p1 = 0, p2 = 0, p3 = 0;
	while (p1<length1 && p2<length2 && p3<length3)
	{
		if (a[p1] == b[p2] && b[p2] == c[p3])
		{
			cout << a[p1] << " ";
			p1++;
			p2++;
			p3++;
		}
		else
		{
			int temp = max(max(a[p1], b[p2]), c[p3]);
			while (a[p1]<temp)
			{
				p1++;
			}
			while (b[p2]<temp)
			{
				p2++;
			}while (c[p3]<temp)
			{
				p3++;
			}
		}
	}
	cout << endl;
}

int main(int argc, char* argv[])
{
	ifstream in(".\\input.txt");
	cin.rdbuf(in.rdbuf());
	int length1, length2, length3;
	cin >> length1;
	for (int i = 0; i < length1; i++)
		cin >> a[i];
	cin >> length2;
	for (int i = 0; i < length2; i++)
		cin >> b[i];
	cin >> length3;
	for (int i = 0; i < length3; i++)
		cin >> c[i];
	func(length1, length2, length3);
	system("pause");
	return 0;
}