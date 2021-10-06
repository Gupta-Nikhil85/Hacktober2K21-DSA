#include <iostream>
#include <cmath>

using namespace std;

int isPrimeNumber(int);

int main()
{

    int n, i = 3, count, c;
    cin >> n;
    if (n >= 1)
    {
        cout << "2 ";
    }

    // iteration for n prime numbers
    // i is the number to be checked in each iteration starting from 3
    for (count = 2; count <= n; i++)
    {
        // iteration to check c is prime or not
        for (c = 2; c < i; c++)
        {
            if (i % c == 0)
                break;
        }

        if (c == i) // c is prime
        {
            cout << i << " ";
            count++; // increment the count of prime numbers
        }
    }

    return 0;
}