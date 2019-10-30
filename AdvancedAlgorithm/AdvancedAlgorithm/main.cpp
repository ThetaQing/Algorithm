#include <iostream>
#include "greatest_common_division.h"
#include "primality_check.h"
#include "modular_exponention.h"
#include <bitset>
using namespace std;
using std::bitset;

int main()
{
	
	//std::cout << gcd_Euclid_recursion(188, 112) << endl;
	
	//std::cout << gcd_continuous_integer_test(112, 188) << endl;
	int N = 17;
	//std::cout << Primality(N) << endl;
	//std::cout << PrimalityImprove(N) << endl;
	cout << ModularExponention(2, 2, 5) << endl;
	system("pause");
	return 0;
}