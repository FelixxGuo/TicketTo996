/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/
 *
 * algorithms
 * Easy (51.39%)
 * Likes:    2430
 * Dislikes: 195
 * Total Accepted:    325.4K
 * Total Submissions: 632.5K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * Given an unsorted array of integers nums, return the length of the longest
 * continuous increasing subsequence (i.e. subarray). The subsequence must be
 * strictly increasing.
 *
 * A continuous increasing subsequence is defined by two indices l and r (l <
 * r) such that it is [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for
 * each l <= i < r, nums[i] < nums[i + 1].
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,3,5,4,7]
 * Output: 3
 * Explanation: The longest continuous increasing subsequence is [1,3,5] with
 * length 3.
 * Even though [1,3,5,7] is an increasing subsequence, it is not continuous as
 * elements 5 and 7 are separated by element
 * 4.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,2,2,2,2]
 * Output: 1
 * Explanation: The longest continuous increasing subsequence is [2] with
 * length 1. Note that it must be strictly
 * increasing.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution1 {
public:
  int findLengthOfLCIS(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) {
      return 1;
    }
    int res = 0;
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i) {
      if (nums[i] > nums[i - 1]) {
        dp[i] = dp[i - 1] + 1;
      }
      if (dp[i] > res) {
        res = dp[i];
      }
    }
    return res;
  }
};

class Solution {
public:
  int findLengthOfLCIS(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) {
      return 1;
    }
    int res = 1;
    int count = 1;
    for (int i = 1; i < n; ++i) {
        if (nums[i] > nums[i - 1]) {
            ++count;
        } else {
            count = 1;
        }
        if (res < count) {
            res = count;
        }
    }
    return res;
  }
};
// @lc code=end
