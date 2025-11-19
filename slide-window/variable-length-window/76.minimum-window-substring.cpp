/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (46.03%)
 * Likes:    19606
 * Dislikes: 827
 * Total Accepted:    2M
 * Total Submissions: 4.2M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given two strings s and t of lengths m and n respectively, return the
 * minimum window substring of s such that every character in t (including
 * duplicates) is included in the window. If there is no such substring, return
 * the empty string "".
 *
 * The testcases will be generated such that the answer is unique.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 * Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C'
 * from string t.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "a", t = "a"
 * Output: "a"
 * Explanation: The entire string s is the minimum window.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "a", t = "aa"
 * Output: ""
 * Explanation: Both 'a's from t must be included in the window.
 * Since the largest window of s only has one 'a', return empty string.
 *
 *
 *
 * Constraints:
 *
 *
 * m == s.length
 * n == t.length
 * 1 <= m, n <= 10^5
 * s and t consist of uppercase and lowercase English letters.
 *
 *
 *
 * Follow up: Could you find an algorithm that runs in O(m + n) time?
 *
 */

// @lc code=start
class Solution {
public:
  string minWindow(string s, string t) {
    int m = s.size(), n = t.size();
    if (m < n) {
      return "";
    }
    vector<int> sVec(128, 0);
    vector<int> tVec(128, 0);
    int tSz = 0;
    for (int i = 0; i < t.size(); ++i) {
      if (tVec[t[i]]++ == 0) {
        ++tSz;
      }
    }

    int left = 0, right = 0, valid = 0;
    int ansLeft = 0, ansRight = 0, ansLen = m + 1;
    for (right = 0; right < m; ++right) {
      sVec[s[right]]++;
      if (sVec[s[right]] == tVec[s[right]]) {
        ++valid;
      }
      while (valid == tSz) {
        if (right - left + 1 < ansLen) {
          ansLen = right - left + 1;
          ansLeft = left;
          ansRight = right;
        }
        if (sVec[s[left]] == tVec[s[left]]) {
          --valid;
        }
        sVec[s[left]]--;
        ++left;
      }
    }
    return ansLen == m + 1 ? "" : s.substr(ansLeft, ansRight - ansLeft + 1);
  }
};
// @lc code=end
