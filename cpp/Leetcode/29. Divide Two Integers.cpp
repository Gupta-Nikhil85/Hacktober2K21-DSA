// Question URL:- https://leetcode.com/problems/divide-two-integers/
// Github:- naveen701526
class Solution {
public:
    int divide(int dividend, int divisor) {
        int quotient = 0;
        int doubled = 0;

        bool minus = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);

        if (dividend > 0)
            dividend = -dividend;

        if (divisor > 0)
            divisor = -divisor;

		// doubling the divisor until abs(dividend/2) < abs(divisor) <= abs(dividend) 
        while ((dividend >> 1) < divisor) {
                divisor += divisor;
                doubled++;
        }

        do {
                while (dividend <= divisor) {
                        dividend -= divisor;
						// increment counter considering how much time we have doubled
                        quotient -= 1 << doubled;
                }
                divisor >>= 1; // dividing back the divisor to 2
                doubled--;
        } while (doubled >= 0);

        if (minus)
                return quotient;

        if (quotient == INT_MIN)
                return INT_MAX;

        return -quotient;
    }
};
