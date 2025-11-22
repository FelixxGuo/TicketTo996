/*
 * @lc app=leetcode id=2962 lang=cpp
 *
 * [2962] Count Subarrays Where Max Element Appears at Least K Times
 *
 * https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/
 *
 * algorithms
 * Medium (62.47%)
 * Likes:    1687
 * Dislikes: 80
 * Total Accepted:    253.4K
 * Total Submissions: 406.1K
 * Testcase Example:  '[1,3,2,3,3]\n2'
 *
 * You are given an integer array nums and a positive integer k.
 *
 * Return the number of subarrays where the maximum element of nums appears at
 * least k times in that subarray.
 *
 * A subarray is a contiguous sequence of elements within an array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,3,2,3,3], k = 2
 * Output: 6
 * Explanation: The subarrays that contain the element 3 at least 2 times are:
 * [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,4,2,1], k = 3
 * Output: 0
 * Explanation: No subarray contains the element 4 at least 3 times.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^6
 * 1 <= k <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
public:
  long long countSubarrays(vector<int> &nums, int k) {
    long long ans = 0;
    int left = 0, right = 0, n = nums.size(), maxNum = 0;
    for (int i = 0; i < n; ++i) {
      maxNum = max(maxNum, nums[i]);
    }

    int cnt = 0;
    for (right = 0; right < n; ++right) {
      if (nums[right] == maxNum) {
        ++cnt;
      }
      while (cnt == k) {
        if (nums[left] == maxNum) {
          --cnt;
        }
        ++left;
      }
      ans += left;
    }
    return ans;
  }
};
// @lc code=end
