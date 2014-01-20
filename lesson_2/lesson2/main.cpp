#include <iostream>

using namespace std;

int main()
{
    int a = 0, b = 0;

    const bool cond = a > 3;

    (cond ? a : b) = 1;

    cout << "a = " << a << "  b = " << b << endl;
    return 0;
}
