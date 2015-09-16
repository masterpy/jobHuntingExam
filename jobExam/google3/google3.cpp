// google3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <ostream> 
#include <fstream> 
using namespace std;

int main(int argc, char* argv[])
{
	ifstream in(".\\input.txt");
	//streambuf *cinbuf = cin.rdbuf(); //save old buf
	cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	//ofstream out("C:\\Users\\zhengyi\\Desktop\\ConsoleApplication1\\Debug\\out.txt");
	//streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	//cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

	//std::cin.rdbuf(cinbuf);   //reset to standard input again
	//std::cout.rdbuf(coutbuf); //reset to standard output again

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		int count = 0;
		cin.ignore();
		string str;
		vector<string> v1;
		while (count<n)
		{
			getline(cin, str);
			v1.push_back(str);
			count++;
		}
		//v1.erase(v1.begin());
		int cost = 0;
		for (int k = 1; k < n; k++)
		{
			string key = v1[k];
			int t = k - 1;
			if (t >= 0 && v1[t].compare(key) > 0)
			{
				v1[t + 1] = v1[t];
				t--;
				cost++;
			}
			v1[t + 1] = key;
		}
		cout << "Case #" << i + 1 << ":" << cost << endl;
	}
	system("pause");
	return 0;
}