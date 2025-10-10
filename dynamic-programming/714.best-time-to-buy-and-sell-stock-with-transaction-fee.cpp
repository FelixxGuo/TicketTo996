/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
 *
 * algorithms
 * Medium (71.13%)
 * Likes:    7518
 * Dislikes: 230
 * Total Accepted:    526.6K
 * Total Submissions: 739.5K
 * Testcase Example:  '[1,3,2,8,4,9]\n2'
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the i^th day, and an integer fee representing a transaction fee.
 * 
 * Find the maximum profit you can achieve. You may complete as many
 * transactions as you like, but you need to pay the transaction fee for each
 * transaction.
 * 
 * Note:
 * 
 * 
 * You may not engage in multiple transactions simultaneously (i.e., you must
 * sell the stock before you buy again).
 * The transaction fee is only charged once for each stock purchase and
 * sale.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: prices = [1,3,2,8,4,9], fee = 2
 * Output: 8
 * Explanation: The maximum profit can be achieved by:
 * - Buying at prices[0] = 1
 * - Selling at prices[3] = 8
 * - Buying at prices[4] = 4
 * - Selling at prices[5] = 9
 * The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: prices = [1,3,7,5,10,3], fee = 3
 * Output: 6
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= prices.length <= 5 * 10^4
 * 1 <= prices[i] < 5 * 10^4
 * 0 <= fee < 5 * 10^4
 * 
 * 
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution1 {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size()        ;
        vector<vector<int>> dp(n, vector<int>(2, 0));
        // 0: have the stock
        // 1: dont have the stock
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size()        ;
        vector<int> dp(2, 0);
        // 0: have the stock
        // 1: dont have the stock
        dp[0] = -prices[0];
        dp[1] = 0;

        for (int i = 1; i < n; ++i) {
            dp[0] = max(dp[0], dp[1] - prices[i]);
            dp[1] = max(dp[1], dp[0] + prices[i] - fee);
        }
        return max(dp[0], dp[1]);
    }
};
// @lc code=end

