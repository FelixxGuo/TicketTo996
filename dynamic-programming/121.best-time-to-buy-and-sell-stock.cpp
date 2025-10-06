/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (55.74%)
 * Likes:    34329
 * Dislikes: 1345
 * Total Accepted:    7.1M
 * Total Submissions: 12.6M
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the i^th day.
 *
 * You want to maximize your profit by choosing a single day to buy one stock
 * and choosing a different day in the future to sell that stock.
 *
 * Return the maximum profit you can achieve from this transaction. If you
 * cannot achieve any profit, return 0.
 *
 *
 * Example 1:
 *
 *
 * Input: prices = [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
 * = 6-1 = 5.
 * Note that buying on day 2 and selling on day 1 is not allowed because you
 * must buy before you sell.
 *
 *
 * Example 2:
 *
 *
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transactions are done and the max profit =
 * 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= prices.length <= 10^5
 * 0 <= prices[i] <= 10^4
 *
 *
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
  int maxProfit(vector<int> &prices) {
    int low = INT_MAX;
    int res = 0;
    for (int i = 0; i < prices.size(); ++i) {
      low = min(prices[i], low);
      res = max(res, prices[i] - low);
    }
    return res;
  }
};

class Solution2 {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>{0, 0});
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    // dp[i][0] i day have the stock to get the max profit
    // dp[i][1] i day don't have the stock to get the max profit
    // dp[i][0] = max(-prices[i], dp[i - 1][0])
    // dp[i][1] = max(prices[i] + dp[i - 1][0], dp[i - 1][1])
    for (int i = 1; i < n; ++i) {
      dp[i][0] = max(-prices[i], dp[i - 1][0]);
      dp[i][1] = max(prices[i] + dp[i - 1][0], dp[i - 1][1]);
    }
    return dp[n - 1][1];
  }
};

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> dp(2, vector<int>{0, 0});
    dp[0][0] = -prices[0];
    dp[0][1] = 0;

    for (int i = 1; i < n; ++i) {
      dp[i % 2][0] = max(-prices[i], dp[(i - 1) % 2][0]);
      dp[i % 2][1] = max(prices[i] + dp[(i - 1) % 2][0], dp[(i - 1) % 2][1]);
    }
    return dp[(n - 1) % 2][1];
  }
};
// @lc code=end
