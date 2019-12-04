#include <iostream>
#include <vector>
#include "divide_and_conquer.h"
#include <bitset>
#include <sstream>
#include <algorithm>
#include "dynamic_programming.h"
using namespace std;



int main()
{
	vector<int> test{ 1,2,3,2,6,4 };
	auto re = max_element(test.begin(), test.end());
	cout << *re << endl;
	maxProfit2(test);
	system("pause");
	return 0;
}