//Chinese Remainder Theorem

#include <iostream>
#include <vector>
using namespace std;


int ChineseRemainder(const vector< pair<int, int> >& equations)
{   
    int M = 1;
    for (int i = 0; i < equations.size(); i++)
        M *= equations[i].second;
    
    int x = 0;
    
}
