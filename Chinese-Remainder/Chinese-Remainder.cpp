#include "../Extended-Euclidean/Extended-Euclidean.h"
#include <iostream>
#include <vector>
#include <utility>
using namespace std;


int ChineseRemainder(const vector< pair<int, int> >& equations)
{   
    int M = 1;
    for (size_t i = 0; i < equations.size(); i++)
        M *= equations[i].second;

    int sum = 0;
    for (size_t i = 0; i < equations.size(); i++)
    {
        int Mi = M / equations[i].second;
        tuple<int, int, int> inverse = extended_euclidean(Mi, equations[i].second);
        int y = get<1>(inverse); // y is the multiplicative inverse to be used
        sum += equations[i].first * y * Mi;
    }
    return sum % M;
}
