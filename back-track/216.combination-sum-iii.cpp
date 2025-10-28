/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (72.39%)
 * Likes:    6513
 * Dislikes: 121
 * Total Accepted:    733.1K
 * Total Submissions: 1M
 * Testcase Example:  '3\n7'
 *
 * Find all valid combinations of k numbers that sum up to n such that the
 * following conditions are true:
 *
 *
 * Only numbers 1 through 9 are used.
 * Each number is used at most once.
 *
 *
 * Return a list of all possible valid combinations. The list must not contain
 * the same combination twice, and the combinations may be returned in any
 * order.
 *
 *
 * Example 1:
 *
 *
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * Explanation:
 * 1 + 2 + 4 = 7
 * There are no other valid combinations.
 *
 * Example 2:
 *
 *
 * Input: k = 3, n = 9
 * Output: [[1,2,6],[1,3,5],[2,3,4]]
 * Explanation:
 * 1 + 2 + 6 = 9
 * 1 + 3 + 5 = 9
 * 2 + 3 + 4 = 9
 * There are no other valid combinations.
 *
 *
 * Example 3:
 *
 *
 * Input: k = 4, n = 1
 * Output: []
 * Explanation: There are no valid combinations.
 * Using 4 different numbers in the range [1,9], the smallest sum we can get is
 * 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= k <= 9
 * 1 <= n <= 60
 *
 *
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> path;
    int s = 0;
    backtrack(k, n, 1, s, path, res);
    return res;
  }

private:
  void backtrack(int k, int n, int start, int &s, vector<int> &path,
                 vector<vector<int>> &res) {
    if (s == n && path.size() == k) {
      res.push_back(path);
      return;
    }
    if (s > n) {
      return;
    }
    int remain = k - path.size();
    int maxStart = 9 - remain + 1;
    for (int i = start; i <= maxStart; ++i) {
      if (s + i > n) {
        break;
      }
      s += i;
      path.push_back(i);
      backtrack(k, n, i + 1, s, path, res);
      path.pop_back();
      s -= i;
    }
  }
};
// @lc code=end
