#include "Extended-Euclidean/Extended-Euclidean.h"
#include <iostream>
using namespace std;

void extended_euclidean_operations(){
	int a = 1914, b = 899, x, y;
	cout << "GCD(a, b) = " << extended_euclidean(a, b, x, y) << endl;
	cout << "Coefficients x and y are : " << x << " " << y << endl;
    printf("%d * %d + %d * %d = %d\n", a, x, b, y, a * y + b * x);
}



int main()
{
    extended_euclidean_operations();
	return 0;
}
