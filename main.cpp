//filename: main.cpp
#include "Extended-Euclidean/Extended-Euclidean.h" 
#include "Chinese-Remainder/Chinese-Remainder.h"
#include "Miller-Rabin/Miller-Rabin.h"
#include "EL-Gamal/EL-Gamal.h" 
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

using namespace std;

void extended_euclidean_operations() {
    int a = 35, b = 15;
    auto result = extended_euclidean(a, b);
    cout << "The Greatest Common Divisor is " << get<0>(result) << "\n";
    cout << "The coefficients for " << a << " and " << b << " are:\n";
    cout << "x: " << get<1>(result) << "\n";
    cout << "y: " << get<2>(result) << "\n";
}

void chinese_remainder_operations() {
    vector< pair<int, int> > equations;
    equations.push_back(make_pair(1, 3));
    equations.push_back(make_pair(4, 5));
    equations.push_back(make_pair(6, 7));
    int solution = ChineseRemainder(equations);
    cout << "The solution for the system of congruences is " << solution << "\n";
    cout<< "The solution is " << solution << " mod " << equations[0].second * equations[1].second * equations[2].second << "\n";
}




int main() {
    extended_euclidean_operations();
    chinese_remainder_operations();
    doing_ELGamal();//this is the the EL-Gamal function where a hello world is done
    int num = 721;
    bool result = is_Prime(num, 3);
    printf("is %d prime: %d\n",  num, result);
    
    return 0;
}
