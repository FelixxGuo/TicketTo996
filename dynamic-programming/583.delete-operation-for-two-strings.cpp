/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 *
 * https://leetcode.com/problems/delete-operation-for-two-strings/description/
 *
 * algorithms
 * Medium (64.57%)
 * Likes:    6074
 * Dislikes: 92
 * Total Accepted:    353.5K
 * Total Submissions: 546.6K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * Given two strings word1 and word2, return the minimum number of steps
 * required to make word1 and word2 the same.
 *
 * In one step, you can delete exactly one character in either string.
 *
 *
 * Example 1:
 *
 *
 * Input: word1 = "sea", word2 = "eat"
 * Output: 2
 * Explanation: You need one step to make "sea" to "ea" and another step to
 * make "eat" to "ea".
 *
 *
 * Example 2:
 *
 *
 * Input: word1 = "leetcode", word2 = "etco"
 * Output: 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word1.length, word2.length <= 500
 * word1 and word2 consist of only lowercase English letters.
 *
 *
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution1 {
public:
  int minDistance(string word1, string word2) {
    int len1 = word1.size();
    int len2 = word2.size();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    for (int j = 0; j <= len2; ++j) {
      dp[0][j] = j;
    }
    for (int i = 0; i <= len1; ++i) {
      dp[i][0] = i;
    }
    dp[0][0] = 0;

    for (int i = 1; i <= len1; ++i) {
      for (int j = 1; j <= len2; ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
        }
      }
    }
    return dp[len1][len2];
  }
};

class Solution2 {
public:
  int minDistance(string word1, string word2) {
    int len1 = word1.size();
    int len2 = word2.size();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    for (int j = 0; j <= len2; ++j) {
      dp[0][j] = 0;
    }
    for (int i = 0; i <= len1; ++i) {
      dp[i][0] = 0;
    }

    for (int i = 1; i <= len1; ++i) {
      for (int j = 1; j <= len2; ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return (len1 - dp[len1][len2]) + (len2 - dp[len1][len2]);
  }
};

class Solution {
public:
  int minDistance(string word1, string word2) {
    int len1 = word1.size();
    int len2 = word2.size();

    vector<int> dp(len2 + 1, 0);
    for (int j = 0; j <= len2; ++j) {
      dp[j] = j;
    }

    for (int i = 1; i <= len1; ++i) {
      int prev = dp[0];
      dp[0] = i;
      for (int j = 1; j <= len2; ++j) {
        // dp[i - 1][j - 1]
        int tmp = dp[j];
        if (word1[i - 1] == word2[j - 1]) {
          dp[j] = prev;
        } else {
          dp[j] = min(dp[j], dp[j - 1]) + 1;
        }
        prev = tmp;
      }
    }
    return dp[len2];
  }
};
// @lc code=end
