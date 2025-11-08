/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 *
 * https://leetcode.com/problems/maximum-average-subarray-i/description/
 *
 * algorithms
 * Easy (46.06%)
 * Likes:    4140
 * Dislikes: 376
 * Total Accepted:    993.4K
 * Total Submissions: 2.1M
 * Testcase Example:  '[1,12,-5,-6,50,3]\n4'
 *
 * You are given an integer array nums consisting of n elements, and an integer
 * k.
 *
 * Find a contiguous subarray whose length is equal to k that has the maximum
 * average value and return this value. Any answer with a calculation error
 * less than 10^-5 will be accepted.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,12,-5,-6,50,3], k = 4
 * Output: 12.75000
 * Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [5], k = 1
 * Output: 5.00000
 *
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= k <= n <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
  double findMaxAverage(vector<int> &nums, int k) {
    int res = INT_MIN;
    int sum = 0;
    int left = 0;
    int right = 0;
    for (right = 0; right < nums.size(); ++right) {
      sum += nums[right];
      left = right - k + 1;
      if (left < 0) {
        continue;
      }
      res = max(res, sum);
      sum -= nums[left];
    }
    return (double)res / k;
  }
};
// @lc code=end
