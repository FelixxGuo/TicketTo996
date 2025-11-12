/*
 * @lc app=leetcode id=1695 lang=cpp
 *
 * [1695] Maximum Erasure Value
 *
 * https://leetcode.com/problems/maximum-erasure-value/description/
 *
 * algorithms
 * Medium (63.95%)
 * Likes:    3370
 * Dislikes: 64
 * Total Accepted:    284.2K
 * Total Submissions: 444.1K
 * Testcase Example:  '[4,2,4,5,6]'
 *
 * You are given an array of positive integers nums and want to erase a
 * subarray containing unique elements. The score you get by erasing the
 * subarray is equal to the sum of its elements.
 *
 * Return the maximum score you can get by erasing exactly one subarray.
 *
 * An array b is called to be a subarray of a if it forms a contiguous
 * subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some
 * (l,r).
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [4,2,4,5,6]
 * Output: 17
 * Explanation: The optimal subarray here is [2,4,5,6].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [5,2,1,2,5,2,1,2,5]
 * Output: 8
 * Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
 *
 *
 */

// @lc code=start
class Solution {
public:
  int maximumUniqueSubarray(vector<int> &nums) {
    int n = nums.size(), left = 0, right = 0, ans = 0, sum = 0;
    unordered_map<int, int> cnt;

    for (right = 0; right < n; ++right) {
      cnt[nums[right]]++;
      sum += nums[right];
      while (cnt[nums[right]] > 1) {
        cnt[nums[left]]--;
        if (cnt[nums[left]] == 0) {
          cnt.erase(nums[left]);
        }
        sum -= nums[left];
        left++;
      }
      ans = max(ans, sum);
    }
    return ans;
  }
};
// @lc code=end
