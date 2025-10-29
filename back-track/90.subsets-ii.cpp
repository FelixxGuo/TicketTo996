/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (60.12%)
 * Likes:    10651
 * Dislikes: 393
 * Total Accepted:    1.3M
 * Total Submissions: 2.2M
 * Testcase Example:  '[1,2,2]'
 *
 * Given an integer array nums that may contain duplicates, return all possible
 * subsets (the power set).
 *
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 *
 *
 * Example 1:
 * Input: nums = [1,2,2]
 * Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 * Example 2:
 * Input: nums = [0]
 * Output: [[],[0]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 *
 *
 */

// @lc code=start
class Solution1 {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> path;
    int n = nums.size();
    vector<bool> used(n, false);
    sort(nums.begin(), nums.end());
    backtrack(nums, path, res, 0, used);
    return res;
  }

private:
  void backtrack(const vector<int> &nums, vector<int> &path,
                 vector<vector<int>> &res, int start, vector<bool> &used) {
    int n = nums.size();
    res.push_back(path);
    for (int i = start; i < n; ++i) {
      if (i >= 1 && nums[i] == nums[i - 1] && !used[i - 1]) {
        continue;
      }
      used[i] = true;
      path.push_back(nums[i]);
      backtrack(nums, path, res, i + 1, used);
      used[i] = false;
      path.pop_back();
    }
  }
};

class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> path;
    sort(nums.begin(), nums.end());
    backtrack(nums, path, res, 0);
    return res;
  }

private:
  void backtrack(const vector<int> &nums, vector<int> &path,
                 vector<vector<int>> &res, int start) {
    int n = nums.size();
    res.push_back(path);
    for (int i = start; i < n; ++i) {
      if (i > start && nums[i] == nums[i - 1]) {
        continue;
      }
      path.push_back(nums[i]);
      backtrack(nums, path, res, i + 1);
      path.pop_back();
    }
  }
};
// @lc code=end
