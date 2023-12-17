#include "Extended-Euclidean/Extended-Euclidean.h"
#include <iostream>
using namespace std;

int main()
{
	int a = 1000, b = 660, x, y;
	cout << "GCD(a, b) = " << extended_euclidean(a, b, x, y) << endl;
	cout << "Coefficients x and y are : " << x << " " << y << endl;
	return 0;
}
