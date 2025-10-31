/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (65.26%)
 * Likes:    10799
 * Dislikes: 328
 * Total Accepted:    936.7K
 * Total Submissions: 1.4M
 * Testcase Example:
 * '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * A sudoku solution must satisfy all of the following rules:
 *
 *
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 *
 *
 * The '.' character indicates empty cells.
 *
 *
 * Example 1:
 *
 *
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
 * Output:
 * [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 * Explanation: The input board is shown above and the only valid solution is
 * shown below:
 *
 *
 *
 *
 *
 * Constraints:
 *
 *
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit or '.'.
 * It is guaranteed that the input board has only one solution.
 *
 *
 */

// @lc code=start
class Solution {
public:
  void solveSudoku(vector<vector<char>> &board) {
    backtrack(board);
    return;
  }

private:
  bool backtrack(vector<vector<char>> &board) {
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] != '.') {
          continue;
        }
        for (char k = '1'; k <= '9'; ++k) {
          if (valid(i, j, board, k)) {
            board[i][j] = k;
            if (backtrack(board)) {
              return true;
            }
            board[i][j] = '.';
          }
        }
        return false;
      }
    }
    return true;
  }
  bool valid(int row, int col, vector<vector<char>> &board, char c) {
    for (int i = 0; i < 9; ++i) {
      if (board[row][i] == c) {
        return false;
      }
    }
    for (int i = 0; i < 9; ++i) {
      if (board[i][col] == c) {
        return false;
      }
    }
    int smallRowMin = row / 3 * 3;
    int smallRowMax = smallRowMin + 3;
    int smallColMin = col / 3 * 3;
    int smallColMax = smallColMin + 3;
    for (int i = smallRowMin; i < smallRowMax; ++i) {
      for (int j = smallColMin; j < smallColMax; ++j) {
        if (board[i][j] == c) {
          return false;
        }
      }
    }
    return true;
  }
};
// @lc code=end
