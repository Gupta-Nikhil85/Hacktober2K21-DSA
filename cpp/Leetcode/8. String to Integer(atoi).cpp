//https://leetcode.com/problems/string-to-integer-atoi/
//Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

#include <climits>
#include <cstdio>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int number = 0;
        bool isMinus = false;
        bool hasDigitOrSign = false;
        
        for (int i=0; i<str.length(); ++i) {
            if (str[i] == ' ') {
                if (hasDigitOrSign) {
                    break;
                } else {
                    continue;
                }
            } else if (str[i] == '+') {
                if (hasDigitOrSign) {
                    break;
                } else {
                    hasDigitOrSign = true;
                    continue;
                }
            } else if (str[i] == '-') {
                if (hasDigitOrSign) {
                    break;
                } else {
                    hasDigitOrSign = true;
                    isMinus = true;
                }
            } else if (str[i] >= '0' && str[i] <= '9') {
                if (!hasDigitOrSign) { 
                    hasDigitOrSign = true;
                }
                int digit = (int)(str[i]-'0');
                if (isMinus) {
                    int oldNumber = number;
                    number = number*10;
                    printf("%d, ", number);
                    if (number/10 > oldNumber) {
                        number = INT_MIN;
                        break;
                    }
                    oldNumber = number;
                    number -= digit;
                    printf("%d\n", number);
                    if (number > oldNumber) {
                        number = INT_MIN;
                        break;
                    }
                } else {
                    int oldNumber = number;
                    number = number*10;
                    printf("%d, ", number);
                    if (number/10 < oldNumber) {
                        number = INT_MAX;
                        break;
                    }
                    oldNumber = number;
                    number += digit;
                    printf("%d\n", number);
                    if (number < oldNumber) {
                        number = INT_MAX;
                        break;
                    }
                }
            } else {
                break;
            }
        }
        
        return number;
    }
};


int main(int argc, char** argv) {
    Solution s;
    int number = s.myAtoi(argv[1]);        
    printf("%d\n", number);
}


