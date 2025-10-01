/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (53.69%)
 * Likes:    23700
 * Dislikes: 983
 * Total Accepted:    4.5M
 * Total Submissions: 8.4M
 * Testcase Example:  '2'
 *
 * You are climbing a staircase. It takes n steps to reach the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 45
 * 
 * 
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution1 {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int prev = 1, cur = 2, next = 0;

        for (int i = 3; i <= n; ++i) {
            next = prev + cur;
            prev = cur;
            cur = next;
        }

        return cur;
    }
};
// @lc code=end

