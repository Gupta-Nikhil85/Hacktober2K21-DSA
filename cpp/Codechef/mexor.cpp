//problem link - https://www.codechef.com/OCT21C/problems/MEXOR
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        int a = 1;
        if (x == 0)
        {
            cout << "1" << endl;
        }
        else if (x == 1 || x == 2)
        {
            cout << "2" << endl;
        }
        else
        {
            while (2 * a <= x)
                a *= 2;
            if (a == x)
                cout << x << endl;
            else if (x == (2 * a - 1))
                cout << x + 1 << endl;
            else
                cout << a << endl;
        }
    }
    return 0;
}
