/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (66.09%)
 * Likes:    17888
 * Dislikes: 480
 * Total Accepted:    2.5M
 * Total Submissions: 3.8M
 * Testcase Example:  '3\n7'
 *
 * There is a robot on an m x n grid. The robot is initially located at the
 * top-left corner (i.e., grid[0][0]). The robot tries to move to the
 * bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move
 * either down or right at any point in time.
 *
 * Given the two integers m and n, return the number of possible unique paths
 * that the robot can take to reach the bottom-right corner.
 *
 * The test cases are generated so that the answer will be less than or equal
 * to 2 * 10^9.
 *
 *
 * Example 1:
 *
 *
 * Input: m = 3, n = 7
 * Output: 28
 *
 *
 * Example 2:
 *
 *
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation: From the top-left corner, there are a total of 3 ways to reach
 * the bottom-right corner:
 * 1. Right -> Down -> Down
 * 2. Down -> Down -> Right
 * 3. Down -> Right -> Down
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= m, n <= 100
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
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      dp[i][0] = 1;
    }
    for (int j = 0; j < n; ++j) {
      dp[0][j] = 1;
    }
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
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

// use the combine mathmatics
// C(n, k) = n! / (k!)(n - k)! = (n - k + 1) * ... (n) / k!
class Solution1 {
public:
  int uniquePaths(int m, int n) {
    long long res = 1;
    int n = m + n - 2;
    int k = m - 1;
    for (int i = 1; i <= k; ++i) {
        res *= (n - i + 1) / i;
    }
    return (int)res;
  }
};

// use the dfs
class Solution2 {
public:
  int uniquePaths(int m, int n) { return dfs(0, 0, m, n); }

private:
  int dfs(int i, int j, int m, int n) {
    if (i == m - 1 && j == n - 1) {
      return 1;
    }
    if (i > m - 1 || j > n - 1) {
      return 0;
    }
    return dfs(i + 1, j, m, n) + dfs(i, j + 1, m, n);
  }
};

// use the dfs with memo
class Solution3 {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> memo(m, vector<int>(n, -1));
    dfs(0, 0, m, n, memo);
    return memo[m - 1][n - 1];
  }

private:
  int dfs(int i, int j, int m, int n, vector<vector<int>> &memo) {
    if (i == m - 1 && j == n - 1) {
      return 1;
    }
    if (i > m - 1 || j > n - 1) {
      return 0;
    }
    if (memo[i][j] != -1) {
      return memo[i][j];
    }
    return memo[i][j] = dfs(i + 1, j, m, n, memo) + dfs(i, j + 1, m, n, memo);
  }
};

// memory optimizing 2-dimesion to 1
// only use the left and above element, so use the one dimension array is enough
class Solution4 {
public:
  int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);
    // index starts at 1
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[j] = dp[j - 1] + dp[j];
      }
    }
    return dp[n - 1];
  }
};

int main() {
  Solution sol;
  int m, n;
  cout << "Enter m and n: ";
  cin >> m >> n;
  int result = sol.uniquePaths(m, n);
  cout << "Unique paths = " << result << endl;
  return 0;
}
// @lc code=end
