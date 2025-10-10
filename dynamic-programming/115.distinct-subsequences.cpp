/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 *
 * https://leetcode.com/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (50.72%)
 * Likes:    7214
 * Dislikes: 316
 * Total Accepted:    613.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * Given two strings s and t, return the number of distinct subsequences of s
 * which equals t.
 *
 * The test cases are generated so that the answer fits on a 32-bit signed
 * integer.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "rabbbit", t = "rabbit"
 * Output: 3
 * Explanation:
 * As shown below, there are 3 ways you can generate "rabbit" from s.
 * rabbbit
 * rabbbit
 * rabbbit
 *
 *
 * Example 2:
 *
 *
 * Input: s = "babgbag", t = "bag"
 * Output: 5
 * Explanation:
 * As shown below, there are 5 ways you can generate "bag" from s.
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, t.length <= 1000
 * s and t consist of English letters.
 *
 *
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution1 {
public:
  int numDistinct(string s, string t) {
    int len1 = s.size();
    int len2 = t.size();
    vector<vector<unsigned long long>> dp(
        len1 + 1, vector<unsigned long long>(len2 + 1, 0));
    for (int j = 0; j <= len2; ++j) {
      dp[0][j] = 0;
    }
    for (int i = 0; i <= len1; ++i) {
      dp[i][0] = 1;
    }

    for (int i = 1; i <= len1; ++i) {
      for (int j = 1; j <= len2; ++j) {
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[len1][len2];
  }
};

class Solution {
public:
  int numDistinct(string s, string t) {
    int len1 = s.size();
    int len2 = t.size();

    vector<unsigned long long> dp(len2 + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= len1; ++i) {
      for (int j = len2; j >= 1; --j) {
        if (s[i - 1] == t[j - 1]) {
          dp[j] = dp[j - 1] + dp[j];
        }
      }
    }
    return dp[len2];
  }
};
// @lc code=end
