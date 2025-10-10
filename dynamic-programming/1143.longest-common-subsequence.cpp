/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 *
 * https://leetcode.com/problems/longest-common-subsequence/description/
 *
 * algorithms
 * Medium (58.51%)
 * Likes:    14681
 * Dislikes: 235
 * Total Accepted:    1.6M
 * Total Submissions: 2.8M
 * Testcase Example:  '"abcde"\n"ace"'
 *
 * Given two strings text1 and text2, return the length of their longest common
 * subsequence. If there is no common subsequence, return 0.
 *
 * A subsequence of a string is a new string generated from the original string
 * with some characters (can be none) deleted without changing the relative
 * order of the remaining characters.
 *
 *
 * For example, "ace" is a subsequence of "abcde".
 *
 *
 * A common subsequence of two strings is a subsequence that is common to both
 * strings.
 *
 *
 * Example 1:
 *
 *
 * Input: text1 = "abcde", text2 = "ace"
 * Output: 3
 * Explanation: The longest common subsequence is "ace" and its length is 3.
 *
 *
 * Example 2:
 *
 *
 * Input: text1 = "abc", text2 = "abc"
 * Output: 3
 * Explanation: The longest common subsequence is "abc" and its length is 3.
 *
 *
 * Example 3:
 *
 *
 * Input: text1 = "abc", text2 = "def"
 * Output: 0
 * Explanation: There is no such common subsequence, so the result is 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= text1.length, text2.length <= 1000
 * text1 and text2 consist of only lowercase English characters.
 *
 *
 */

// @lc code=start

#include <string>
#include <vector>

using namespace std;

class Solution1 {
public:
  int longestCommonSubsequence(string text1, string text2) {
    // len1 & len2 greater than 0
    int len1 = text1.size();
    int len2 = text2.size();

    vector<vector<int>> dp(len1, vector<int>(len2, 0));
    for (int i = 0; i < len1; ++i) {
      if (text1[i] == text2[0]) {
        while (i < len1) {
          dp[i][0] = 1;
          ++i;
        }
        break;
      }
    }
    for (int i = 0; i < len2; ++i) {
      if (text1[0] == text2[i]) {
        while (i < len2) {
          dp[0][i] = 1;
          ++i;
        }
        break;
      }
    }

    for (int i = 1; i < len1; ++i) {
      for (int j = 1; j < len2; ++j) {
        if (text1[i] == text2[j]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[len1 - 1][len2 - 1];
  }
};

class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int len1 = text1.size();
    int len2 = text2.size();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 2, 0));

    for (int i = 1; i <= len1; ++i) {
      for (int j = 1; j <= len2; ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[len1][len2];
  }
};
// @lc code=end
