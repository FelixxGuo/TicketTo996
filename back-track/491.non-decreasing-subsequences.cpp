/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Non-decreasing Subsequences
 *
 * https://leetcode.com/problems/non-decreasing-subsequences/description/
 *
 * algorithms
 * Medium (62.00%)
 * Likes:    3788
 * Dislikes: 237
 * Total Accepted:    199.7K
 * Total Submissions: 321.5K
 * Testcase Example:  '[4,6,7,7]'
 *
 * Given an integer array nums, return all the different possible
 * non-decreasing subsequences of the given array with at least two elements.
 * You may return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [4,6,7,7]
 * Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [4,4,3,2,1]
 * Output: [[4,4]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 15
 * -100 <= nums[i] <= 100
 *
 *
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> path;
    backtrack(nums, path, res, 0);
    return res;
  }

private:
  void backtrack(const vector<int> &nums, vector<int> &path,
                 vector<vector<int>> &res, int start) {
    int n = nums.size();
    if (path.size() >= 2) {
      res.push_back(path);
    }
    unordered_set<int> uset;
    for (int i = start; i < n; ++i) {
      if (!path.empty() && nums[i] < path.back() || uset.count(nums[i]) > 0) {
        continue;
      }
      uset.insert(nums[i]);
      path.push_back(nums[i]);
      backtrack(nums, path, res, i + 1);
      path.pop_back();
    }
  }
};
// @lc code=end
