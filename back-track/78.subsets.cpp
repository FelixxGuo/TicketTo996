/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (81.43%)
 * Likes:    18747
 * Dislikes: 333
 * Total Accepted:    2.8M
 * Total Submissions: 3.4M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of unique elements, return all possible subsets
 * (the power set).
 *
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0]
 * Output: [[],[0]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * All the numbers of nums are unique.
 *
 *
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> path;
    backtrack(nums, path, res, 0);
    return res;
  }
  void backtrack(const vector<int> &nums, vector<int> &path,
                 vector<vector<int>> &res, int start) {
    int n = nums.size();
    res.push_back(path);
    for (int i = start; i < n; ++i) {
      path.push_back(nums[i]);
      backtrack(nums, path, res, i + 1);
      path.pop_back();
    }
  }
};
// @lc code=end
