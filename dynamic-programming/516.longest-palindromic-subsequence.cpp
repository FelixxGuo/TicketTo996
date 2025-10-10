/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 *
 * https://leetcode.com/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (64.61%)
 * Likes:    10176
 * Dislikes: 339
 * Total Accepted:    689.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '"bbbab"'
 *
 * Given a string s, find the longest palindromic subsequence's length in s.
 *
 * A subsequence is a sequence that can be derived from another sequence by
 * deleting some or no elements without changing the order of the remaining
 * elements.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "bbbab"
 * Output: 4
 * Explanation: One possible longest palindromic subsequence is "bbbb".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "cbbd"
 * Output: 2
 * Explanation: One possible longest palindromic subsequence is "bb".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s consists only of lowercase English letters.
 *
 *
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
      dp[i][i] = 1;
    }
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j - 1] + 2;
        } else {
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[0][n - 1];
  }
};
// @lc code=end
