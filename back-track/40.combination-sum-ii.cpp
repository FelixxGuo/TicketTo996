/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (58.18%)
 * Likes:    11944
 * Dislikes: 370
 * Total Accepted:    1.5M
 * Total Submissions: 2.6M
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sum to target.
 *
 * Each number in candidates may only be used once in the combination.
 *
 * Note: The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 *
 *
 */

// @lc code=start
class Solution1 {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> path;
    sort(candidates.begin(), candidates.end());
    vector<bool> used(candidates.size(), false);
    int sum = 0;
    int start = 0;
    backtrack(candidates, target, sum, path, res, start, used);
    return res;
  }

private:
  void backtrack(const vector<int> &candidates, int target, int sum,
                 vector<int> &path, vector<vector<int>> &res, int start,
                 vector<bool> &used) {
    if (sum > target) {
      return;
    }
    if (sum == target) {
      res.push_back(path);
      return;
    }
    for (int i = start; i < candidates.size(); ++i) {
      if (i >= 1 && candidates[i] == candidates[i - 1] && !used[i - 1]) {
        continue;
      }
      if (sum + candidates[i] > target) {
        break;
      }
      sum += candidates[i];
      path.push_back(candidates[i]);
      used[i] = true;
      backtrack(candidates, target, sum, path, res, i + 1, used);
      used[i] = false;
      path.pop_back();
      sum -= candidates[i];
    }
  }
};

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> path;
    sort(candidates.begin(), candidates.end());
    int sum = 0;
    int start = 0;
    backtrack(candidates, path, res, target, sum, start);
    return res;
  }

private:
  void backtrack(const vector<int> &candidates, vector<int> &path,
                 vector<vector<int>> &res, int target, int sum, int start) {
    if (sum > target) {
      return;
    }
    if (sum == target) {
      res.push_back(path);
      return;
    }
    for (int i = start; i < candidates.size(); ++i) {
      if (sum + candidates[i] > target) {
        break;
      }
      if (i > start && candidates[i] == candidates[i - 1]) {
        continue;
      }
      path.push_back(candidates[i]);
      sum += candidates[i];
      backtrack(candidates, path, res, target, sum, i + 1);
      sum -= candidates[i];
      path.pop_back();
    }
  }
};
// @lc code=end
