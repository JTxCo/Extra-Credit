#include <iostream>

//this file holds in the function for calculating the extended euclidean algorithm

using namespace std;

int extended_euclidean(int a, int b, int& x, int& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int x1=1, x2=0, y1=0, y2=1;
    int q, r;
    while (b > 0)
    {
        q = a / b;
        r = a - q * b;
        x = x2 - q * x1;
        y = y2 - q * y1;
        a = b;
        b = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }
    x = x2;
    y = y2;
    return a;
}


