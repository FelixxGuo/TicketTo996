/*
 * @lc app=leetcode id=3134 lang=cpp
 *
 * [3134] Find the Median of the Uniqueness Array
 *
 * https://leetcode.com/problems/find-the-median-of-the-uniqueness-array/description/
 *
 * algorithms
 * Hard (29.06%)
 * Likes:    174
 * Dislikes: 13
 * Total Accepted:    8.4K
 * Total Submissions: 28.5K
 * Testcase Example:  '[1,2,3]'
 *
 * You are given an integer array nums. The uniqueness array of nums is the
 * sorted array that contains the number of distinct elements of all the
 * subarrays of nums. In other words, it is a sorted array consisting of
 * distinct(nums[i..j]), for all 0 <= i <= j < nums.length.
 *
 * Here, distinct(nums[i..j]) denotes the number of distinct elements in the
 * subarray that starts at index i and ends at index j.
 *
 * Return the median of the uniqueness array of nums.
 *
 * Note that the median of an array is defined as the middle element of the
 * array when it is sorted in non-decreasing order. If there are two choices
 * for a median, the smaller of the two values is taken.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3]
 *
 * Output: 1
 *
 * Explanation:
 *
 * The uniqueness array of nums is [distinct(nums[0..0]), distinct(nums[1..1]),
 * distinct(nums[2..2]), distinct(nums[0..1]), distinct(nums[1..2]),
 * distinct(nums[0..2])] which is equal to [1, 1, 1, 2, 2, 3]. The uniqueness
 * array has a median of 1. Therefore, the answer is 1.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,4,3,4,5]
 *
 * Output: 2
 *
 * Explanation:
 *
 * The uniqueness array of nums is [1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3,
 * 3]. The uniqueness array has a median of 2. Therefore, the answer is 2.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [4,3,5,4]
 *
 * Output: 2
 *
 * Explanation:
 *
 * The uniqueness array of nums is [1, 1, 1, 1, 2, 2, 2, 3, 3, 3]. The
 * uniqueness array has a median of 2. Therefore, the answer is 2.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
public:
  int medianOfUniquenessArray(vector<int> &nums) {
    int n = nums.size();
    long long k = (1LL * n * (n + 1) / 2 + 1) / 2;
    int left = 0, right = n;

    auto check = [&](int upper) -> bool {
      int start = 0, end = 0;
      long long ans = 0;
      unordered_map<int, int> cnt;
      for (end = 0; end < n; ++end) {
        cnt[nums[end]]++;
        while (cnt.size() > upper) {
          cnt[nums[start]]--;
          if (cnt[nums[start]] == 0) {
            cnt.erase(nums[start]);
          }
          ++start;
        }
        ans += end - start + 1;
        if (ans >= k) {
          return true;
        }
      }
      return false;
    };

    while (left + 1 < right) {
      int mid = left + (right - left) / 2;
      if (check(mid)) {
        right = mid;
      } else {
        left = mid;
      }
    }
    return right;
  }
};
// @lc code=end
