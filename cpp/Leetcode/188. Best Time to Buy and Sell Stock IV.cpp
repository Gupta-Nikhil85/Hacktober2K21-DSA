//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
//You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

//Find the maximum profit you can achieve. You may complete at most k transactions.

//Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

class Solution {
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;
        
        if (k>n/2)
        {
            int res = 0;
            for (int i = 1; i < n; i ++)
            {
                res += Math.max(0,prices[i]-prices[i-1]);
            }
            return res;
        }
        
        int[][] dp = new int[k+1][n];
        for (int i = 1; i <= k; i ++)
        {
            int profit = 0-prices[0];
            for (int j = 1; j < n; j ++)
            {
                dp[i][j] = Math.max(dp[i][j-1], profit+prices[j]);
                profit = Math.max(profit, dp[i-1][j-1]-prices[j]);
            }
        }
        
        return dp[k][n-1];
    }
}
