/*
 * @lc app=leetcode id=1658 lang=cpp
 *
 * [1658] Minimum Operations to Reduce X to Zero
 *
 * https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/
 *
 * algorithms
 * Medium (40.20%)
 * Likes:    5698
 * Dislikes: 126
 * Total Accepted:    222.6K
 * Total Submissions: 552.6K
 * Testcase Example:  '[1,1,4,2,3]\n5'
 *
 * You are given an integer array nums and an integer x. In one operation, you
 * can either remove the leftmost or the rightmost element from the array nums
 * and subtract its value from x. Note that this modifies the array for future
 * operations.
 *
 * Return the minimum number of operations to reduce x to exactly 0 if it is
 * possible, otherwise, return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,4,2,3], x = 5
 * Output: 2
 * Explanation: The optimal solution is to remove the last two elements to
 * reduce x to zero.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [5,6,7,8,9], x = 4
 * Output: -1
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [3,2,20,1,1,3], x = 10
 * Output: 5
 * Explanation: The optimal solution is to remove the last three elements and
 * the first two elements (5 operations in total) to reduce x to zero.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
 * 1 <= x <= 10^9
 *
 *
 */

// @lc code=start
class Solution {
public:
  int minOperations(vector<int> &nums, int x) {
    int n = nums.size(), left = 0, right = 0, ans = n + 1;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int target = sum - x;
    if (target < 0) {
      return -1;
    }
    if (target == 0) {
      return n;
    }
    int countSum = 0;
    for (right = 0; right < n; ++right) {
      countSum += nums[right];
      while (countSum > target) {
        countSum -= nums[left];
        ++left;
      }
      if (countSum == target) {
        ans = min(ans, n - (right - left + 1));
      }
    }
    return ans == n + 1 ? -1 : ans;
  }
};
// @lc code=end
