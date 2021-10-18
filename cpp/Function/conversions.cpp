/* CONVERSIONS */

//Binary to decimal

// #include<iostream>
// #include<cmath>
// using namespace std;

// int main()
// {
//     int num, lastDigit, counter = 0, decnum = 0 ;
//     cout<<"Enter the binary number : ";
//     cin>>num;
//     int base =1;
//     while(num>0)
//     {
//         lastDigit = num%10;
//         decnum +=  lastDigit*base;
//         counter++;
//         num = num/10;
//         base *= 2;
//     }
//     cout<<"Decimal number is : "<<decnum<<endl;

//     return 0;
// }



/* Octal to decimal */

// #include<iostream>
// #include<cmath>
// using namespace std;

// int main()
// {
//     int num, lastDigit, counter = 0, decnum = 0 ;
//     cout<<"Enter the octal number : ";
//     cin>>num;
//     int base=1;
//     while(num>0)
//     {
//         lastDigit = num%10;
//         decnum +=  lastDigit*base;
//         counter++;
//         num = num/10;
//         base*=8;
//     }
//     cout<<"Decimal number is : "<<decnum<<endl;

//     return 0;
// }



/* Hexadecimal to decimal */

// #include <bits/stdc++.h>
// using namespace std;

// int hexadecimalToDecimal(string n);

// int main()
// {
//     string n;
//     cin >> n;

// cout << hexadecimalToDecimal(n) << endl;
//     return 0;
// }

// int hexadecimalToDecimal(string n)
// {
//     int ans = 0;
//     int x = 1;
//     int s = n.size();

//     for (int i = s - 1; i >= 0; i--)
//     {
//         if (n[i] >= '0' && n[i] <= '9')
//         {
//             ans += x * (n[i] - '0');
//         }
//         else if (n[i] >= 'A' && n[i] <= 'F')
//         {
//             ans += x * (n[i] - 'A' + 10);
//         }
//         x *= 16;
//     }
//     return ans;
// }



/* DECIMAL TO BINARY */

// #include <iostream>

// using namespace std;

// int decimalToBinary(int n);

// int main()
// {
//     int n;
//     cout << "Enter the decimal number : ";
//     cin >> n;

//     cout << "Binary number is : " << decimalToBinary(n) << endl;

//     return 0;
// }

// int decimalToBinary(int n)
// {
//     int x = 1;
//     int ans = 0;
//     while (x <= n)
//     {
//         x *= 2;
//     }
//     x = x / 2;
//     while (x > 0)
//     {
//         int lastDigit = n / x;
//         n -= lastDigit * x;
//         x /= 2;
//         ans = ans * 10 + lastDigit;
//     }
//     return ans;
// }



/* DECIMAL TO OCTAL */

// #include <iostream>

// using namespace std;

// int decimalToOctal(int n);

// int main()
// {
//     int n;
//     cout << "Enter the decimal number : ";
//     cin >> n;

//     cout << "Binary number is : " << decimalToOctal(n) << endl;

//     return 0;
// }

// int decimalToOctal(int n)
// {
//     int x = 1;
//     int ans = 0;
//     while (x <= n)
//     {
//         x *= 8;
//     }
//     x = x / 8;
//     while (x > 0)
//     {
//         int lastDigit = n / x;
//         n -= lastDigit * x;
//         x /= 8;
//         ans = ans * 10 + lastDigit;
//     }
//     return ans;
// }



/* DECIMAL TO HEXADECIMAL */

// #include <bits/stdc++.h>

// using namespace std;

// string decimalToHexadecimal(int n);

// int main()
// {
//     int n;
//     cout << "Enter the decimal number : ";
//     cin >> n;

//     cout << "Binary number is : " << decimalToHexadecimal(n) << endl;

//     return 0;
// }

// string decimalToHexadecimal(int n)
// {
//     int x = 1;
//     string ans = "";
//     while (x <= n)
//     {
//         x *= 16;
//     }
//     x = x / 16;
//     while (x > 0)
//     {
//         int lastDigit = n / x;
//         n -= lastDigit * x;
//         x /= 16;
//         if (lastDigit <= 9)
//         {
//             ans = ans + to_string(lastDigit);
//         }
//         else
//         {
//             char c = 'A' + lastDigit - 10;
//             ans.push_back(c);
//         }
//     }
//     return ans;
// }
