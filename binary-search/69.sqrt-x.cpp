/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (40.76%)
 * Likes:    9317
 * Dislikes: 4616
 * Total Accepted:    2.9M
 * Total Submissions: 7M
 * Testcase Example:  '4'
 *
 * Given a non-negative integer x, return the square root of x rounded down to
 * the nearest integer. The returned integer should be non-negative as well.
 *
 * You must not use any built-in exponent function or operator.
 *
 *
 * For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: x = 4
 * Output: 2
 * Explanation: The square root of 4 is 2, so we return 2.
 *
 *
 * Example 2:
 *
 *
 * Input: x = 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since we round it down
 * to the nearest integer, 2 is returned.
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= x <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
public:
  int mySqrt(int x) {
    int left = 0;
    int right = x;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (1LL * mid * mid > x) {
        right = mid - 1;
      } else if (1LL * mid * mid < x) {
        left = mid + 1;
      } else {
        return mid;
      }
    }
    return right;
  }
};
// @lc code=end
