/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (37.57%)
 * Likes:    11258
 * Dislikes: 10418
 * Total Accepted:    2.5M
 * Total Submissions: 6.5M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (i.e.,
 * x^n).
 *
 *
 * Example 1:
 *
 *
 * Input: x = 2.00000, n = 10
 * Output: 1024.00000
 *
 *
 * Example 2:
 *
 *
 * Input: x = 2.10000, n = 3
 * Output: 9.26100
 *
 *
 * Example 3:
 *
 *
 * Input: x = 2.00000, n = -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 *
 *
 *
 * Constraints:
 *
 *
 * -100.0 < x < 100.0
 * -2^31 <= n <= 2^31-1
 * n is an integer.
 * Either x is not zero or n > 0.
 * -10^4 <= x^n <= 10^4
 *
 *
 */

// @lc code=start
class Solution1 {
public:
  double myPow(double x, int n) {
    long long number = n;
    if (number < 0) {
      number = abs(number);
      x = 1 / x;
    }
    double ans = 1.0;
    int bit = 0;
    while (number) {
      bit = (number & 1);
      if (bit) {
        ans *= x;
      }
      number >>= 1;
      x *= x;
    }
    return ans;
  }
};

class Solution {
public:
  double myPow(double x, int n) {
    long long number = n;
    if (n < 0) {
      number = -number;
      x = 1 / x;
    }
    return pow(x, number);
  }

private:
  double pow(double x, long long n) {
    if (n == 0) {
      return 1;
    }
    double val = pow(x, n / 2);
    if (n % 2) {
      return val * val * x;
    }
    return val * val;
  }
};
// @lc code=end
