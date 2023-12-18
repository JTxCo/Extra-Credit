#include "../Extended-Euclidean/Extended-Euclidean.h"
#include <cmath>
#include <ctime>
#include <random>

unsigned long powmod(unsigned long base, unsigned long exp, unsigned long mod)
{
    unsigned long result = 1;
    base %= mod;
    while(exp > 0) {
        if(exp & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

bool isPrime(int num) {
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int generatePrime(int low, int high) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(low, high);

    int num;
    do {
        num = dist(gen);
    } while (!isPrime(num));

    return num;
}

pair<int,int> generateKeys(int P /*prime*/, int G /*primitive root*/){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, P - 1);
    int private_key = dis(gen);
    int public_key = powmod(G, private_key, P);

    /*private key, public key*/
    return make_pair(private_key, public_key);
}

int computeSharedSecret(int private_key, int public_key, int P) {
    return powmod(public_key, private_key, P);
}
