#include <iostream>
#include <vector>
#include "divide_and_conquer.h"
#include <bitset>
#include <sstream>
#include <algorithm>
#include "dynamic_programming.h"
#include <unordered_map>
using namespace std;



int main()
{
	char ans = 'a' ^ 'b';
	unordered_map<char, int>test(2);
	test['a'] += 1;
	cout << test[0]<<endl;
	cout << test[1] << endl;
	if (ans)
		cout << "ans" << ans;
	system("pause");
	return 0;
}