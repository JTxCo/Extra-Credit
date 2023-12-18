#include <iostream>
#include <cmath>
using namespace std;



//input n, k iterations of Miller-Rabin, output whether n is prime or not

int modular_pow(int base, int exponent, int modulus) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return result;
}

bool miller_rabin(int n) {
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;

    int d = n - 1;
    int count = 0;
    while (d % 2 == 0) {
        d /= 2;
        count++;
    }

    // int decomposition = (1 << count) * d;
    int a = 2 + (std::rand() % (n - 4));
    int x = modular_pow(a, d, n);

    if (x == 1 || x == n - 1)
        return true;

    for (int i = 0; i < count - 1; i++) {
        x = modular_pow(x, 2, n);
        if (x == n - 1)
            return true;
    }

    return false;
}

bool is_Prime(int n, int k) {
    for (int i = 0; i < k; i++)
        if (miller_rabin(n) == false)
            return false;
    return true;
}