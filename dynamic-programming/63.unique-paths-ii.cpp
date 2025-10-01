/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (43.58%)
 * Likes:    9433
 * Dislikes: 551
 * Total Accepted:    1.3M
 * Total Submissions: 3M
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * You are given an m x n integer array grid. There is a robot initially
 * located at the top-left corner (i.e., grid[0][0]). The robot tries to move
 * to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only
 * move either down or right at any point in time.
 *
 * An obstacle and space are marked as 1 or 0 respectively in grid. A path that
 * the robot takes cannot include any square that is an obstacle.
 *
 * Return the number of possible unique paths that the robot can take to reach
 * the bottom-right corner.
 *
 * The testcases are generated so that the answer will be less than or equal to
 * 2 * 10^9.
 *
 *
 * Example 1:
 *
 *
 * Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 * Output: 2
 * Explanation: There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 *
 *
 * Example 2:
 *
 *
 * Input: obstacleGrid = [[0,1],[0,0]]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * m == obstacleGrid.length
 * n == obstacleGrid[i].length
 * 1 <= m, n <= 100
 * obstacleGrid[i][j] is 0 or 1.
 *
 *
 */

// @lc code=start
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    // 1 <= m, n <= 100
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
      // if there is obstacle
      if (obstacleGrid[i][0]) {
        break;
      }
      dp[i][0] = 1;
    }
    for (int j = 0; j < n; ++j) {
      // if there is obstacle
      if (obstacleGrid[0][j]) {
        break;
      }
      dp[0][j] = 1;
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (obstacleGrid[i][j]) {
          dp[i][j] = 0;
        } else {
          dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << setw(5) << dp[i][j];
      }
      cout << endl;
    }
    return dp[m - 1][n - 1];
  }
};

class Solution1 {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<int> dp(n, 0);
    if (obstacleGrid[0][0]) {
        return 0;
    }
    // must be first, initialize the first row
    dp[0] = 1;
    for (int j = 1; j < n; ++j) {
        if (obstacleGrid[0][j]) {
            dp[j] = 0;
        } else {
            // why?
            // start from the row 0
            dp[j] =  dp[j - 1];
        }
    }
    for (int i = 1; i < m; ++i) {
        // initialize the first column
        if (obstacleGrid[i][0]) {
            // why?
            // rolling array
            dp[0] = 0;
        }
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[i][j]) {
                dp[j] = 0;
            } else {
                dp[j] = dp[j] + dp[j - 1];
            }
        }
    }
    return dp[n - 1];
  }
};

/*
int main() {
  Solution sol;

  // Example grid: 0 = free cell, 1 = obstacle
  vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

  int result = sol.uniquePathsWithObstacles(grid);
  cout << "Unique paths: " << result << endl;

  return 0;
}
*/

// @lc code=end
