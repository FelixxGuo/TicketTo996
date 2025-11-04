/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (44.37%)
 * Likes:    4569
 * Dislikes: 332
 * Total Accepted:    841.5K
 * Total Submissions: 1.9M
 * Testcase Example:  '16'
 *
 * Given a positive integer num, return true if num is a perfect square or
 * false otherwise.
 *
 * A perfect square is an integer that is the square of an integer. In other
 * words, it is the product of some integer with itself.
 *
 * You must not use any built-in library function, such as sqrt.
 *
 *
 * Example 1:
 *
 *
 * Input: num = 16
 * Output: true
 * Explanation: We return true because 4 * 4 = 16 and 4 is an integer.
 *
 *
 * Example 2:
 *
 *
 * Input: num = 14
 * Output: false
 * Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an
 * integer.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= num <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
public:
  bool isPerfectSquare(int num) {
    int left = 1;
    int right = num;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (1LL * mid * mid > num) {
        right = mid - 1;
      } else if (1LL * mid * mid < num) {
        left = mid + 1;
      } else {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
