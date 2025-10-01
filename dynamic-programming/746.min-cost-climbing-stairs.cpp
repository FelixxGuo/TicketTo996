/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 *
 * https://leetcode.com/problems/min-cost-climbing-stairs/description/
 *
 * algorithms
 * Easy (67.56%)
 * Likes:    12107
 * Dislikes: 1863
 * Total Accepted:    1.6M
 * Total Submissions: 2.3M
 * Testcase Example:  '[10,15,20]'
 *
 * You are given an integer array cost where cost[i] is the cost of i^th step
 * on a staircase. Once you pay the cost, you can either climb one or two
 * steps.
 * 
 * You can either start from the step with index 0, or the step with index 1.
 * 
 * Return the minimum cost to reach the top of the floor.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: cost = [10,15,20]
 * Output: 15
 * Explanation: You will start at index 1.
 * - Pay 15 and climb two steps to reach the top.
 * The total cost is 15.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: cost = [1,100,1,1,1,100,1,1,100,1]
 * Output: 6
 * Explanation: You will start at index 0.
 * - Pay 1 and climb two steps to reach index 2.
 * - Pay 1 and climb two steps to reach index 4.
 * - Pay 1 and climb two steps to reach index 6.
 * - Pay 1 and climb one step to reach index 7.
 * - Pay 1 and climb two steps to reach index 9.
 * - Pay 1 and climb one step to reach the top.
 * The total cost is 6.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= cost.length <= 1000
 * 0 <= cost[i] <= 999
 * 
 * 
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution1 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n <= 1) {
            return 0;
        }

        vector<int> dp(n + 1, 0);
        dp[0] = 0, dp[1] = 0;

        for (int i = 2; i <= n; ++i) {
           dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n <= 1) {
            return 0;
        }

        int prev1 = 0, prev2 = 0, cur = 0;

        for (int i = 2; i <= n; ++i) {
            cur = min(prev1 + cost[i - 1], prev2 + cost[i - 2]);
            prev2 = prev1;
            prev1 = cur;
        }
        return cur;
    }
};
// @lc code=end

