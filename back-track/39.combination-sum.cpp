/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (75.32%)
 * Likes:    20454
 * Dislikes: 510
 * Total Accepted:    2.8M
 * Total Submissions: 3.7M
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given an array of distinct integers candidates and a target integer target,
 * return a list of all unique combinations of candidates where the chosen
 * numbers sum to target. You may return the combinations in any order.
 *
 * The same number may be chosen from candidates an unlimited number of times.
 * Two combinations are unique if the frequency of at least one of the chosen
 * numbers is different.
 *
 * The test cases are generated such that the number of unique combinations
 * that sum up to target is less than 150 combinations for the given input.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [2,3,6,7], target = 7
 * Output: [[2,2,3],[7]]
 * Explanation:
 * 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple
 * times.
 * 7 is a candidate, and 7 = 7.
 * These are the only two combinations.
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,3,5], target = 8
 * Output: [[2,2,2,2],[2,3,3],[3,5]]
 *
 *
 * Example 3:
 *
 *
 * Input: candidates = [2], target = 1
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= candidates.length <= 30
 * 2 <= candidates[i] <= 40
 * All elements of candidates are distinct.
 * 1 <= target <= 40
 *
 *
 */

// @lc code=start
class Solution1 {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> path;
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
      path.push_back(candidates[i]);
      sum += candidates[i];
      backtrack(candidates, path, res, target, sum, i);
      sum -= candidates[i];
      path.pop_back();
    }
  }
};

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
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
        return;
      }
      sum += candidates[i];
      path.push_back(candidates[i]);
      backtrack(candidates, path, res, target, sum, i);
      path.pop_back();
      sum -= candidates[i];
    }
  }
};
// @lc code=end
