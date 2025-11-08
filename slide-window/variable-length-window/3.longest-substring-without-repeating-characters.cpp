/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (37.57%)
 * Likes:    43525
 * Dislikes: 2128
 * Total Accepted:    8.4M
 * Total Submissions: 22.2M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string s, find the length of the longest substring without duplicate
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3. Note that "bca" and
 * "cab" are also correct answers.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not
 * a substring.
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 *
 *
 */

// @lc code=start
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int ans = 0, n = s.size();
    int left = 0, right = 0;
    vector<int> cnt(128, 0);

    for (right = 0; right < n; ++right) {
      cnt[s[right]]++;
      while (cnt[s[right]] > 1) {
        cnt[s[left]]--;
        ++left;
      }
      ans = max(ans, right - left + 1);
    }
    return ans;
  }
};
// @lc code=end
