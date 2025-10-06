/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (51.26%)
 * Likes:    12103
 * Dislikes: 407
 * Total Accepted:    976.3K
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * You are given an integer array nums and an integer target.
 *
 * You want to build an expression out of nums by adding one of the symbols '+'
 * and '-' before each integer in nums and then concatenate all the
 * integers.
 *
 *
 * For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1
 * and concatenate them to build the expression "+2-1".
 *
 *
 * Return the number of different expressions that you can build, which
 * evaluates to target.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,1,1,1], target = 3
 * Output: 5
 * Explanation: There are 5 ways to assign symbols to make the sum of nums be
 * target 3.
 * -1 + 1 + 1 + 1 + 1 = 3
 * +1 - 1 + 1 + 1 + 1 = 3
 * +1 + 1 - 1 + 1 + 1 = 3
 * +1 + 1 + 1 - 1 + 1 = 3
 * +1 + 1 + 1 + 1 - 1 = 3
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1], target = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 20
 * 0 <= nums[i] <= 1000
 * 0 <= sum(nums[i]) <= 1000
 * -1000 <= target <= 1000
 *
 *
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int sum = 0;
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
    }

    if ((sum + target) % 2 != 0) {
        return 0;
    }
    if (abs(target) > sum) {
        return 0;
    }
    int bagWeight = (sum + target) / 2;
    vector<int> dp(bagWeight + 1, 0);
    // calculate the method.
    dp[0] = 1;

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = bagWeight; j >= nums[i]; --j) {
        dp[j] += dp[j - nums[i]];
      }
    }
    return dp[bagWeight];
  }
};
// @lc code=end
