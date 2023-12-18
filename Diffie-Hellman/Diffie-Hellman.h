#ifndef DIFFIE_HELLMAN_H
#define DIFFIE_HELLMAN_H

#include <utility>

unsigned long powmod(unsigned long base, unsigned long exp, unsigned long mod);
std::pair<int, int> generateKeys(int P, int G);
int computeSharedSecret(int private_key, int public_key, int P);
int generatePrime(int low, int high);

#endif
