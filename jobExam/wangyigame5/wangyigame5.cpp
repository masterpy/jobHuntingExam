// wangyigame5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

#define size 40001
int pointcoord[size][4];
double centralproperty[size][4];

int Count(int N)
{
	int result = 0;
	for (size_t i = 0; i < N - 1; i++)
	{
		for (size_t j = i + 1; j < N; j++)
		{
			double horizon = abs(centralproperty[i][0] - centralproperty[j][0]);
			double vertical = abs(centralproperty[i][1] - centralproperty[j][1]);
			if ((horizon <= centralproperty[i][2] + centralproperty[j][2]) && (vertical <= centralproperty[i][3] + centralproperty[j][3]))
			{
				result++;
			}
		}
	}
	return result;
}

double* Change(int a[])
{
	double* b = new double[4];
	b[0] = (a[0] + a[2]) / 2.0;
	b[1] = (a[1] + a[3]) / 2.0;
	b[2] = (a[2] - a[0]) / 2.0;
	b[3] = (a[1] - a[3]) / 2.0;
	return b;
}

int main(int argc, char* argv[])
{
	ifstream in(".\\input.txt");
	cin.rdbuf(in.rdbuf());

	int T;
	cin >> T;
	for (int k = 0; k < T; k++)
	{
		int N;
		cin >> N;
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				cin >> pointcoord[i][j];
			}
		}
		for (size_t i = 0; i < N; i++)
		{
			double* temp = Change(pointcoord[i]);
			for (size_t j = 0; j < 4; j++)
			{
				centralproperty[i][j] = *(temp + j);
			}
			delete[] temp;
		}
		cout << Count(N) << endl;
	}

	system("pause");
	return 0;
}

