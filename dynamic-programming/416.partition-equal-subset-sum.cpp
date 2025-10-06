/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (48.83%)
 * Likes:    13514
 * Dislikes: 290
 * Total Accepted:    1.3M
 * Total Submissions: 2.8M
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given an integer array nums, return true if you can partition the array into
 * two subsets such that the sum of the elements in both subsets is equal or
 * false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,5,11,5]
 * Output: true
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,5]
 * Output: false
 * Explanation: The array cannot be partitioned into equal sum subsets.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 100
 *
 *
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    // [1,2,3,5]
    int s = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      s += nums[i];
    }
    if (s % 2 != 0) {
      return false;
    }

    int target = s / 2;
    vector<int> dp(target + 1, 0);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = target; j >= nums[i]; --j) {
        dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
      }
    }
    return dp[target] == target;
  }
};

int main() {
  Solution sol;

  vector<int> nums1 = {1, 5, 11, 5};
  vector<int> nums2 = {1, 2, 3, 5};

  cout << "Test 1: {1, 5, 11, 5} => ";
  cout << (sol.canPartition(nums1) ? "true" : "false") << endl;

  cout << "Test 2: {1, 2, 3, 5} => ";
  cout << (sol.canPartition(nums2) ? "true" : "false") << endl;

  return 0;
}

// @lc code=end
