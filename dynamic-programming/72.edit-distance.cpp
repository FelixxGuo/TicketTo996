/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 *
 * https://leetcode.com/problems/edit-distance/description/
 *
 * algorithms
 * Medium (59.39%)
 * Likes:    16038
 * Dislikes: 304
 * Total Accepted:    1.3M
 * Total Submissions: 2.2M
 * Testcase Example:  '"horse"\n"ros"'
 *
 * Given two strings word1 and word2, return the minimum number of operations
 * required to convert word1 to word2.
 *
 * You have the following three operations permitted on a word:
 *
 *
 * Insert a character
 * Delete a character
 * Replace a character
 *
 *
 *
 * Example 1:
 *
 *
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation:
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 *
 *
 * Example 2:
 *
 *
 * Input: word1 = "intention", word2 = "execution"
 * Output: 5
 * Explanation:
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= word1.length, word2.length <= 500
 * word1 and word2 consist of lowercase English letters.
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

    for (int i = 1; i <= len1; ++i) {
      for (int j = 1; j <= len2; ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
        }
      }
    }
    return dp[len1][len2];
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
        int tmp = dp[j];
        if (word1[i - 1] == word2[j - 1]) {
          dp[j] = prev; 
        } else {
          dp[j] = min(min(dp[j], dp[j - 1]), prev) + 1;
        }
        prev = tmp;
      }
    }
    return dp[len2];
  }
};
// @lc code=end
