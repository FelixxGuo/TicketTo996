/*
 * @lc app=leetcode id=2762 lang=cpp
 *
 * [2762] Continuous Subarrays
 *
 * https://leetcode.com/problems/continuous-subarrays/description/
 *
 * algorithms
 * Medium (57.97%)
 * Likes:    1472
 * Dislikes: 96
 * Total Accepted:    115.6K
 * Total Submissions: 199.4K
 * Testcase Example:  '[5,4,2,4]'
 *
 * You are given a 0-indexed integer array nums. A subarray of nums is called
 * continuous if:
 *
 *
 * Let i, i + 1, ..., j be the indices in the subarray. Then, for each pair of
 * indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2.
 *
 *
 * Return the total number of continuous subarrays.
 *
 * A subarray is a contiguous non-empty sequence of elements within an
 * array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [5,4,2,4]
 * Output: 8
 * Explanation:
 * Continuous subarray of size 1: [5], [4], [2], [4].
 * Continuous subarray of size 2: [5,4], [4,2], [2,4].
 * Continuous subarray of size 3: [4,2,4].
 * There are no subarrys of size 4.
 * Total continuous subarrays = 4 + 3 + 1 = 8.
 * It can be shown that there are no more continuous subarrays.
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3]
 * Output: 6
 * Explanation:
 * Continuous subarray of size 1: [1], [2], [3].
 * Continuous subarray of size 2: [1,2], [2,3].
 * Continuous subarray of size 3: [1,2,3].
 * Total continuous subarrays = 3 + 2 + 1 = 6.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 *
 *
 */

// @lc code=start
class Solution1 {
public:
  long long continuousSubarrays(vector<int> &nums) {
    int n = nums.size();
    int left = 0, right = 0;
    long long ans = 0;
    map<int, int> cnt;
    for (right = 0; right < n; ++right) {
      cnt[nums[right]]++;
      while (cnt.rbegin()->first - cnt.begin()->first > 2) {
        if (--cnt[nums[left]] == 0) {
          cnt.erase(nums[left]);
        }
        ++left;
      }
      ans += right - left + 1;
    }
    return ans;
  }
};

class Solution {
public:
  long long continuousSubarrays(vector<int> &nums) {
    long long ans = 0;
    deque<int> maxDq;
    deque<int> minDq;
    int left = 0, right = 0, n = nums.size();

    for (right = 0; right < n; ++right) {
      while (!maxDq.empty() && nums[right] >= nums[maxDq.back()]) {
        maxDq.pop_back();
      }
      maxDq.push_back(right);

      while (!minDq.empty() && nums[right] <= nums[minDq.back()]) {
        minDq.pop_back();
      }
      minDq.push_back(right);

      while (nums[maxDq.front()] - nums[minDq.front()] > 2) {
        if (maxDq.front() == left) {
          maxDq.pop_front();
        }
        if (minDq.front() == left) {
          minDq.pop_front();
        }
        ++left;
      }
      ans += right - left + 1;
    }
    return ans;
  }
};
// @lc code=end
