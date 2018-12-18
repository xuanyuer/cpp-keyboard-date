#include <iostream>

#include "Date.hpp"

using namespace std;

int main (int argc, const char ** argv)
{
    Date date (2018, 12, 10);

    cout << date + 5 << endl;

    return 0;
}