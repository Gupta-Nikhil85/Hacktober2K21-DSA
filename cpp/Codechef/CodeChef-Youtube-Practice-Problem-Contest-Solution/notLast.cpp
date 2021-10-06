#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    string s = to_string(n);
    int slen = s.length();
    int flag = 0;

    for (int i = 0; i < slen - 1; i++)
    {
        if (s[slen - 2] == '7')
        {
            flag = 1;
        }
    }
    if (flag == 1)
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }

    return 0;
}