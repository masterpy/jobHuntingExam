// google1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <deque>
using namespace std;

#define size 5
int graph[size][size];
int visited[size];
int color[size];

bool  GraphJudge(int nodeNum)
{
	memset(visited, 0, sizeof(visited));
	memset(color, 0, sizeof(color));
	for (int k = 0; k < nodeNum; k++)
	{
		if (visited[k] == 0)
		{
			visited[k] = 1;
			color[k] = 1;
			deque<int> q;
			q.push_back(k);
			while (q.empty()==false)
			{
				int i = q.front();
				q.pop_front();
				for (int j = 0; j < nodeNum; j++)
				{
					if (graph[i][j] > 0 && i!=j)
					{
						if (visited[j] == 0)
						{
							q.push_back(j);
							visited[j] = 1;
							color[j] = 1 - color[i];
						}
						else
						{
							if (color[j] == color[i])
								return false;
						}
					}
				}
			}
		}
	}
	return true;
}

int main(int argc, char* argv[])
{
	ifstream in(".\\input.txt");
	cin.rdbuf(in.rdbuf());

	int T;
	cin >> T;
	cin.ignore();
	for (int caseNum = 0; caseNum<T; caseNum++)
	{
		int M;
		cin >> M;
		memset(graph, 0, sizeof(&graph));
		map<string, int> nameIndex;
		map<string, int>::iterator it;
		int nodecount = 0;
		for (int i = 0; i < M; i++)
		{
			int start, end;
			string p;
			cin >> p;
			it = nameIndex.find(p);
			if (it == nameIndex.end())
			{
				nameIndex[p] = nodecount;
				nodecount++;
			}
			start = nameIndex[p];
			cin >> p;
			it = nameIndex.find(p);
			if (it == nameIndex.end())
			{
				nameIndex[p] = nodecount;
				nodecount++;
			}
			end = nameIndex[p];
			graph[start][end] = 1;
		}
		if (GraphJudge(nodecount))
			cout << "Case #" << caseNum + 1 << ":" << "Yes" << endl;
		else
			cout << "Case #" << caseNum + 1 << ":" << "No" << endl;
	}
	system("pause");
	return 0;
}