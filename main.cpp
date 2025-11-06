#include <iostream>

#include "math/operations.h"

using namespace std;

int main()
{
    int first = 10;
    int second = 20;
    int third = MathUtils::add(first, second);
    int fourth = MathUtils::subtract(second, first);
    cout << third <<" "<< fourth << endl;
    return 1;
}