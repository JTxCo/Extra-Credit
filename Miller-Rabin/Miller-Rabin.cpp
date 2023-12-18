#include <iostream>
#include <cmath>
using namespace std;



//input n, k iterations of Miller-Rabin, output whether n is prime or not

bool milller_rabin(int n, int k) {
    //number to test n, for iterations k
    //odd number d
    int d = n-1;
    int count  = 0;
    while( d%2 == 0 ) {
        d /= 2;
        count++;
    }
    int decomposition = pow(2,count) * d;
    printf("decomposition of n-1: %d\n", decomposition);
    //random number a
    int a = 2 + rand() % (n-4);
    printf("random number a: %d\n", a);

    //x = a^d mod n
    int a_d = pow(a,d);;    
    int x = a_d % n;
    


}


bool is_Prime(int n, int k) {
    if( n<=1 || n==4 ) return false;
    if( n<=3 ) return true;
    return milller_rabin(n, k);

}