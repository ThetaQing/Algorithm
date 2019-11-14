#include <iostream>
#include <vector>
#include "divide_and_conquer.h"
#include <bitset>
#include <sstream>
using namespace std;



int main()
{
	int* arr = new int[50] {1,2,5,3,8,4,7,10,89,23,45};
	
	int temp = FindKthElement(arr, 2, 3,1);
	cout << temp << endl;

	delete[] arr;
	system("pause");
	return 0;
}