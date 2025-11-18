/*
 * @lc app=leetcode id=1234 lang=cpp
 *
 * [1234] Replace the Substring for Balanced String
 *
 * https://leetcode.com/problems/replace-the-substring-for-balanced-string/description/
 *
 * algorithms
 * Medium (39.93%)
 * Likes:    1269
 * Dislikes: 224
 * Total Accepted:    44.8K
 * Total Submissions: 111.3K
 * Testcase Example:  '"QWER"'
 *
 * You are given a string s of length n containing only four kinds of
 * characters: 'Q', 'W', 'E', and 'R'.
 *
 * A string is said to be balanced if each of its characters appears n / 4
 * times where n is the length of the string.
 *
 * Return the minimum length of the substring that can be replaced with any
 * other string of the same length to make s balanced. If s is already
 * balanced, return 0.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "QWER"
 * Output: 0
 * Explanation: s is already balanced.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "QQWE"
 * Output: 1
 * Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is
 * balanced.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "QQQW"
 * Output: 2
 * Explanation: We can replace the first "QQ" to "ER".
 *
 *
 *
 * Constraints:
 *
 *
 * n == s.length
 * 4 <= n <= 10^5
 * n is a multiple of 4.
 * s contains only 'Q', 'W', 'E', and 'R'.
 *
 *
 */

// @lc code=start
// WQWRQQQW
class Solution {
public:
  int balancedString(string s) {
    int n = s.size();
    int left = 0, right = 0, ans = n;
    unordered_map<char, int> cnt;
    for (char c : s) {
      cnt[c]++;
    }
    if (cnt['Q'] == n / 4 && cnt['W'] == n / 4 && cnt['E'] == n / 4 &&
        cnt['R'] == n / 4) {
      return 0;
    }
    for (right = 0; right < n; ++right) {
      cnt[s[right]]--;
      while (cnt['Q'] <= n / 4 && cnt['W'] <= n / 4 && cnt['E'] <= n / 4 &&
             cnt['R'] <= n / 4) {
        ans = min(ans, right - left + 1);
        cnt[s[left]]++;
        ++left;
      }
    }
    return ans;
  }
};
// @lc code=end
