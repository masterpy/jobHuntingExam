// google2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include <math.h>
#include <iomanip>
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

	int T;
	cin >> T;
	int k = 0;
	while (k < T)
	{
		int V, D;
		cin >> V >> D;
		double theta = asin(9.8 * D / (V * V)) * 90 / 3.1415926535898;
		cout << "Case #" << k + 1 << ":" << fixed << setprecision(7) << theta << endl;
		k++;
	}
	system("pause");
	return 0;
}