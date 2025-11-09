/*
 * @lc app=leetcode id=1446 lang=cpp
 *
 * [1446] Consecutive Characters
 *
 * https://leetcode.com/problems/consecutive-characters/description/
 *
 * algorithms
 * Easy (60.29%)
 * Likes:    1822
 * Dislikes: 35
 * Total Accepted:    215.9K
 * Total Submissions: 358K
 * Testcase Example:  '"leetcode"'
 *
 * The power of the string is the maximum length of a non-empty substring that
 * contains only one unique character.
 *
 * Given a string s, return the power of s.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "leetcode"
 * Output: 2
 * Explanation: The substring "ee" is of length 2 with the character 'e'
 * only.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "abbcccddddeeeeedcba"
 * Output: 5
 * Explanation: The substring "eeeee" is of length 5 with the character 'e'
 * only.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 500
 * s consists of only lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
public:
  int maxPower(string s) {
    int n = s.size(), i = 0, ans = 0;
    while (i < n) {
      int start = i;
      ++i;
      while (i < n && s[i] == s[i - 1]) {
        ++i;
      }
      ans = max(ans, i - start);
    }
    return ans;
  }
};
// @lc code=end
