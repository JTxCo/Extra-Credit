//Extended Euclidean Algorithm
//filename: Extended-Euclidean/Extended-Euclidean.cpp
#include <tuple>
using namespace std;

tuple<int, int, int> extended_euclidean(int a, int b) {
    // Base case
    if(b == 0) {
        return make_tuple(a, 1, 0);
    } 
   
    // Recursive call
    tuple<int,int, int> result = extended_euclidean(b, a % b);
    
    // Unpack the results
    int gcd = get<0>(result);
    int x = get<1>(result);
    int y = get<2>(result);
    
    // Compute new x and y
    return make_tuple(gcd, y, x - (a / b) * y);
}
