/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (61.40%)
 * Likes:    5304
 * Dislikes: 461
 * Total Accepted:    412.3K
 * Total Submissions: 671.2K
 * Testcase Example:  '2'
 *
 * Given an integer n, break it into the sum of k positive integers, where k >=
 * 2, and maximize the product of those integers.
 *
 * Return the maximum product you can get.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 × 1 = 1.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= n <= 58
 *
 *
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
  int integerBreak(int n) {
    vector<int> dp(n + 1, 0);
    dp[2] = 1;

    for (int i = 3; i <= n; ++i) {
      // it's symmetric. only need a half
      for (int j = 1; j <= i / 2; ++j) {
        dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
      }
    }
    return dp[n];
  }
};

// using the mathmatic way:  a + b  / 2 > square(ab)
// then to k dimension
// using the function to induction the mono; get the the value is on e ~ 2.7
class Solution1 {
public:
  int integerBreak(int n) {
    if (n == 2) {
      return 1;
    }
    if (n == 3) {
        return 2;
    }
    int k = n / 3;
    int val = n % 3;
    int res = 1;
    for (int i = 0; i < k; ++i) {
      res *= 3;
    }
    if (val == 0) {
        return res;
    } else if (val == 1) {
        return res / 3 * 4;
    } else {
        return res * 2;
    }
  }
};
// @lc code=end
