/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (81.10%)
 * Likes:    20447
 * Dislikes: 371
 * Total Accepted:    2.8M
 * Total Submissions: 3.5M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an array nums of distinct integers, return all the possible
 * permutations. You can return the answer in any order.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Example 2:
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * Example 3:
 * Input: nums = [1]
 * Output: [[1]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * All the integers of nums are unique.
 *
 *
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used(nums.size(), false);
    backtrack(nums, path, res, used);
    return res;
  }

private:
  void backtrack(const vector<int> &nums, vector<int> &path,
                 vector<vector<int>> &res, vector<bool>& used) {
    int n = nums.size();
    if (path.size() == n) {
      res.push_back(path);
      return;
    }
    for (int i = 0; i < n; ++i) {
      if (used[i]) {
        continue;
      }
      used[i] = true;
      path.push_back(nums[i]);
      backtrack(nums, path, res, used);
      used[i] = false;
      path.pop_back();
    }
  }
};
// @lc code=end
