//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
//You are given an array prices where prices[i] is the price of a given stock on the ith day.

//Find the maximum profit you can achieve. You may complete at most two transactions.

//Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)  return 0;
        int max_profit = INT_MIN;
        for (int i=0; i<prices.size(); i++) {
            int l_max_profit = maxProfit(prices, 0, i);
            int r_max_profit = maxProfit(prices, i+1, prices.size()-1);
            max_profit = max(max_profit, l_max_profit + r_max_profit);
        }
        return max_profit;
    }
    
    int maxProfit(vector<int> &prices, int l, int r) {
        if (l >= r) return 0;
        int min_price = prices[l], max_profit = 0;
        for (int i=l+1; i<=r; i++) {
            max_profit = max(max_profit, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        return max_profit;
    }
};
