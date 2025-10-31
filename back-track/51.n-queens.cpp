/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (73.86%)
 * Likes:    13853
 * Dislikes: 336
 * Total Accepted:    1.1M
 * Total Submissions: 1.5M
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * You may return the answer in any order.
 *
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space,
 * respectively.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4
 * Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: [["Q"]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 9
 *
 *
 */

// @lc code=start
class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> path(n, string(n, '.'));
    backtrack(n, 0, path, res);
    return res;
  }
  void backtrack(int n, int row, vector<string> &path,
                 vector<vector<string>> &res) {
    if (row == n) {
      res.push_back(path);
    }
    for (int col = 0; col < n; ++col) {
      if (valid(row, col, path, n)) {
        path[row][col] = 'Q';
        backtrack(n, row + 1, path, res);
        path[row][col] = '.';
      }
    }
  }
  bool valid(int row, int col, vector<string> &path, int n) {
    for (int i = 0; i < row; ++i) {
      if (path[i][col] == 'Q') {
        return false;
      }
    }
    for (int i = 1; i <= row && i < n - col; ++i) {
      if (path[row - i][col + i] == 'Q') {
        return false;
      }
    }
    for (int i = 1; i <= row && i <= col; ++i) {
      if (path[row - i][col - i] == 'Q') {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
