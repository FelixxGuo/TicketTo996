/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard (52.11%)
 * Likes:    10381
 * Dislikes: 218
 * Total Accepted:    864.1K
 * Total Submissions: 1.7M
 * Testcase Example:  '[3,3,5,0,0,3,1,4]'
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the i^th day.
 *
 * Find the maximum profit you can achieve. You may complete at most two
 * transactions.
 *
 * Note: You may not engage in multiple transactions simultaneously (i.e., you
 * must sell the stock before you buy again).
 *
 *
 * Example 1:
 *
 *
 * Input: prices = [3,3,5,0,0,3,1,4]
 * Output: 6
 * Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit
 * = 3-0 = 3.
 * Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 =
 * 3.
 *
 * Example 2:
 *
 *
 * Input: prices = [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit
 * = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you
 * are engaging multiple transactions at the same time. You must sell before
 * buying again.
 *
 *
 * Example 3:
 *
 *
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= prices.length <= 10^5
 * 0 <= prices[i] <= 10^5
 *
 *
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution1 {
public:
  int maxProfit(vector<int> &prices) {
    // dp[i][j]: the ith day with the max profit.
    // with j as the follow status [0, 1, 2, 3].
    // 0: no ops
    // 1: have the stock with the first time
    // 2: dont have the stock with the first time
    // 3: have the stock with the second time
    // 4: dont have the stock with the second time
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(5, 0));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    dp[0][2] = 0;
    dp[0][3] = -prices[0];
    dp[0][4] = 0;
    for (int i = 1; i < n; ++i) {
      dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
      dp[i][2] = max(dp[i - 1][1] + prices[i], dp[i - 1][2]);
      dp[i][3] = max(dp[i - 1][2] - prices[i], dp[i - 1][3]);
      dp[i][4] = max(dp[i - 1][3] + prices[i], dp[i - 1][4]);
    }
    return max(dp[n - 1][2], dp[n - 1][4]);
  }
};

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    vector<int> dp(5, 0);
    dp[0] = 0;
    dp[1] = -prices[0];
    dp[2] = 0;
    dp[3] = -prices[0];
    dp[4] = 0;
    for (int i = 1; i < n; ++i) {
        dp[1] = max(dp[0] - prices[i], dp[1]);
        dp[2] = max(dp[1] + prices[i], dp[2]);
        dp[3] = max(dp[2] - prices[i], dp[3]);
        dp[4] = max(dp[3] + prices[i], dp[4]);
    }
    return dp[4];
  }
};
// @lc code=end
