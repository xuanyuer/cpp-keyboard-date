#include <iostream>

#include "Date.hpp"

using namespace std;

int main (int argc, const char ** argv)
{
    Date date (2018, 12, 10);
    Date date2 (2018, 12, 1);

    cout << date - date2 << endl;

    return 0;
}