/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (72.07%)
 * Likes:    11310
 * Dislikes: 253
 * Total Accepted:    1.1M
 * Total Submissions: 1.5M
 * Testcase Example:  '"abc"'
 *
 * Given a string s, return the number of palindromic substrings in it.
 *
 * A string is a palindrome when it reads the same backward as forward.
 *
 * A substring is a contiguous sequence of characters within the string.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s consists of lowercase English letters.
 *
 *
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution1 {
public:
  int countSubstrings(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int res = 0;

    for (int i = 0; i < n; ++i) {
      dp[i][i] = true;
      ++res;
    }

    for (int i = n - 1; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        if (s[i] == s[j]) {
          if (j - i == 1 || dp[i + 1][j - 1]) {
            dp[i][j] = true;
            ++res;
          }
        }
      }
    }
    return res;
  }
};

class Solution {
public:
  int countSubstrings(string s) {
    int n = s.size();
    int res = 0;
    for (int i = 0; i < n; ++i) {
      res += extend(s, i, i, n);
      res += extend(s, i, i + 1, n);
    }
    return res;
  }

private:
  int extend(const string &s, int i, int j, int n) {
    int res = 0;
    while (i >= 0 && j < n && s[i] == s[j]) {
      ++res;
      --i;
      ++j;
    }
    return res;
  }
};
// @lc code=end
