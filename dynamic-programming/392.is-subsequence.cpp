/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 *
 * https://leetcode.com/problems/is-subsequence/description/
 *
 * algorithms
 * Easy (48.59%)
 * Likes:    10535
 * Dislikes: 596
 * Total Accepted:    2.2M
 * Total Submissions: 4.6M
 * Testcase Example:  '"abc"\n"ahbgdc"'
 *
 * Given two strings s and t, return true if s is a subsequence of t, or false
 * otherwise.
 *
 * A subsequence of a string is a new string that is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (i.e., "ace" is a
 * subsequence of "abcde" while "aec" is not).
 *
 *
 * Example 1:
 * Input: s = "abc", t = "ahbgdc"
 * Output: true
 * Example 2:
 * Input: s = "axc", t = "ahbgdc"
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 100
 * 0 <= t.length <= 10^4
 * s and t consist only of lowercase English letters.
 *
 *
 *
 * Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k
 * >= 10^9, and you want to check one by one to see if t has its subsequence.
 * In this scenario, how would you change your code?
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isSubsequence(string s, string t) {
    int len1 = s.size();
    int len2 = t.size();
    if (len1 == 0) {
      return true;
    }
    if (len2 == 0) {
      return false;
    }

    vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
    for (int i = 0; i <= len1; ++i) {
      dp[i][0] = false;
    }
    for (int i = 0; i <= len2; ++i) {
      dp[0][i] = true;
    }

    for (int i = 1; i <= len1; ++i) {
      for (int j = 1; j <= len2; ++j) {
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = dp[i][j - 1];
        }
      }
    }
    return dp[len1][len2];
  }
};
// @lc code=end
