//https://leetcode.com/problems/zigzag-conversion/
//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

#include <cstdio>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        return method1(s, numRows);
    }
private:
    void printString(vector<string> vs) {
        for (int i=0; i<vs.size(); ++i) {
            printf("%s\n", vs[i].c_str());
        }
    }
    string method2(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
 
        string line;
        int length = s.length(); 

        return line;
    }
    string method1(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        
        string blankString(s.length(), ' ');
        vector<string> zzs(numRows, blankString);
        
        int r = 0;
        int c = 0;
        int k = 0;
        for (;;) {
            while (r < numRows) {
                zzs[r][c] = s[k];
                k++;
                if (k >= s.length()) {
                    break;
                }
                r++;
            }
            if (k >= s.length()) {
                break;
            }
            r -= 2;
            c++;
            while (r >= 0) {
                zzs[r][c] = s[k];
                k++;
                if (k >= s.length()) {
                    break;
                }
                r--;
                c++;
            }
            if (k >= s.length()) {
                break;
            }
            r += 2;
            c--;
        }
        
        string line; 
        for (int r=0; r<numRows; ++r) {
            for (int c=0; c<s.length(); ++c) {
                if (zzs[r][c] != ' ') {
                    line.push_back(zzs[r][c]);
                }
            }
        }
        printString(zzs);
        printf("%s\n", line.c_str());
        return line;
    }
};

int main() {
    Solution sln;
    string s = "abcdefghijklmn";
    int n = 5;
    sln.convert(s, n);
    return 0;
}


