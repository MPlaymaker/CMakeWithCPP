#include <iostream>

#include "math/operations.h"
#include "converters/converters.h"

using namespace std;

int main()
{
    int first = 10;
    int second = 20;
    int third = MathUtils::add(first, second);
    int fourth = MathUtils::subtract(second, first);
    cout << Converter::stringToInd("8") <<" "<< Converter::stringToInd("5") << endl;
    return 1;
}