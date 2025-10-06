/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (55.94%)
 * Likes:    11674
 * Dislikes: 485
 * Total Accepted:    1M
 * Total Submissions: 1.8M
 * Testcase Example:  '12'
 *
 * Given an integer n, return the least number of perfect square numbers that
 * sum to n.
 *
 * A perfect square is an integer that is the square of an integer; in other
 * words, it is the product of some integer with itself. For example, 1, 4, 9,
 * and 16 are perfect squares while 3 and 11 are not.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 12
 * Output: 3
 * Explanation: 12 = 4 + 4 + 4.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 10^4
 *
 *
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i * i <= n; ++i) {
      for (int j = i * i; j <= n; ++j) {
        if (dp[j - i * i] != INT_MAX)
            dp[j] = min(dp[j], dp[j - i * i] + 1);
      }
    }
    return dp[n];
  }
};
// @lc code=end
