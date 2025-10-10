/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (48.26%)
 * Likes:    7883
 * Dislikes: 223
 * Total Accepted:    648.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '2\n[2,4,1]'
 *
 * You are given an integer array prices where prices[i] is the price of a
 * given stock on the i^th day, and an integer k.
 *
 * Find the maximum profit you can achieve. You may complete at most k
 * transactions: i.e. you may buy at most k times and sell at most k times.
 *
 * Note: You may not engage in multiple transactions simultaneously (i.e., you
 * must sell the stock before you buy again).
 *
 *
 * Example 1:
 *
 *
 * Input: k = 2, prices = [2,4,1]
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit
 * = 4-2 = 2.
 *
 *
 * Example 2:
 *
 *
 * Input: k = 2, prices = [3,2,6,5,0,3]
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit
 * = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3),
 * profit = 3-0 = 3.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= 100
 * 1 <= prices.length <= 1000
 * 0 <= prices[i] <= 1000
 *
 *
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution1 {
public:
  int maxProfit(int k, vector<int> &prices) {
    // have the stock is the odd
    // don't have the stock is even
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2 * k + 1, 0));
    for (int i = 1; i < 2 * k + 1; ++i) {
      if (i % 2) {
        dp[0][i] = -prices[0];
      } else {
        dp[0][i] = 0;
      }
    }

    for (int i = 1; i < n; ++i) {
      for (int j = 1; j <= 2 * k; ++j) {
        if (j % 2) {
          dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
        }
      }
    }
    return dp[n - 1][2 * k];
  }
};

class Solution {
public:
  int maxProfit(int k, vector<int> &prices) {
    int n = prices.size();
    vector<int> dp(2 * k + 1, 0);
    for (int i = 1; i <= 2 * k; ++i) {
      if (i % 2) {
        dp[i] = -prices[0];
      } else {
        dp[i] = 0;
      }
    }

    for (int i = 1; i < n; ++i) {
      for (int j = 1; j <= 2 * k; ++j) {
        if (j % 2) {
          dp[j] = max(dp[j], dp[j - 1] - prices[i]);
        } else {
          dp[j] = max(dp[j], dp[j - 1] + prices[i]);
        }
      }
    }
    return dp[2 * k];
  }
};
// @lc code=end
