#include <iostream>
//#include <setlocale> не работает

using namespace std;

int main ()
{
    //setlocale(LC_ALL, "ru"); не работает
    int a, b, c, m, n;

    m = 5;
    n = 10;

    a = m + --n;
    b = m++ < ++n;
    c = n-- < --m;

    cout << "Result m + --n: " << a << endl;
    cout << "Result m++ < ++n: " << b << endl;
    cout << "Result n-- < --m: " << c << endl;

    return 0;
}