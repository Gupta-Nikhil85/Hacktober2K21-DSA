#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int l, r;
    cin >> l >> r;

    for (int i = l - 1; i < r; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}