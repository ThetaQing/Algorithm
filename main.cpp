#include <iostream>
#include "greatest_common_division.h"
#include "primality_check.h"
using namespace std;

int main()
{
	
	//std::cout << gcd_Euclid_recursion(188, 112) << endl;
	
	//std::cout << gcd_continuous_integer_test(112, 188) << endl;
	int N = 17;
	std::cout << primality(N) << endl;
	std::cout << primality_improve(N) << endl;
	system("pause");
	return 0;
}