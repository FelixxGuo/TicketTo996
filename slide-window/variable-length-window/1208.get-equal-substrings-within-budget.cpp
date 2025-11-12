/*
 * @lc app=leetcode id=1208 lang=cpp
 *
 * [1208] Get Equal Substrings Within Budget
 *
 * https://leetcode.com/problems/get-equal-substrings-within-budget/description/
 *
 * algorithms
 * Medium (59.16%)
 * Likes:    1898
 * Dislikes: 150
 * Total Accepted:    191.5K
 * Total Submissions: 323.1K
 * Testcase Example:  '"abcd"\n"bcdf"\n3'
 *
 * You are given two strings s and t of the same length and an integer
 * maxCost.
 *
 * You want to change s to t. Changing the i^th character of s to i^th
 * character of t costs |s[i] - t[i]| (i.e., the absolute difference between
 * the ASCII values of the characters).
 *
 * Return the maximum length of a substring of s that can be changed to be the
 * same as the corresponding substring of t with a cost less than or equal to
 * maxCost. If there is no substring from s that can be changed to its
 * corresponding substring from t, return 0.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abcd", t = "bcdf", maxCost = 3
 * Output: 3
 * Explanation: "abc" of s can change to "bcd".
 * That costs 3, so the maximum length is 3.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "abcd", t = "cdef", maxCost = 3
 * Output: 1
 * Explanation: Each character in s costs 2 to change to character in t,  so
 * the maximum length is 1.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "abcd", t = "acde", maxCost = 0
 * Output: 1
 * Explanation: You cannot make any change, so the maximum length is 1.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * t.length == s.length
 * 0 <= maxCost <= 10^6
 * s and t consist of only lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
public:
  int equalSubstring(string s, string t, int maxCost) {
    int left = 0, right = 0;
    int n = s.size(), ans = 0;

    for (right = 0; right < n; ++right) {
      maxCost -= abs(s[right] - t[right]);
      while (maxCost < 0) {
        maxCost += abs(s[left] - t[left]);
        ++left;
      }
      ans = max(ans, right - left + 1);
    }
    return ans;
  }
};
// @lc code=end
