/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 *
 * https://leetcode.com/problems/fibonacci-number/description/
 *
 * algorithms
 * Easy (73.39%)
 * Likes:    8958
 * Dislikes: 392
 * Total Accepted:    2.6M
 * Total Submissions: 3.6M
 * Testcase Example:  '2'
 *
 * The Fibonacci numbers, commonly denoted F(n) form a sequence, called the
 * Fibonacci sequence, such that each number is the sum of the two preceding
 * ones, starting from 0 and 1. That is,
 * 
 * 
 * F(0) = 0, F(1) = 1
 * F(n) = F(n - 1) + F(n - 2), for n > 1.
 * 
 * 
 * Given n, calculate F(n).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 2
 * Output: 1
 * Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 3
 * Output: 2
 * Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 4
 * Output: 3
 * Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= n <= 30
 * 
 * 
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution1 {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        int prev = 0, cur = 1, next = 0;

        for (int i = 2; i <= n; i++) {
           next = cur + prev;
           prev = cur;
           cur = next;
        }
        return cur;
    }
};

// what's the time complexity? it's O(2^n)
// it's a binary tree with the depth to be n
// and the node number will be the time complexity
// @lc code=end

