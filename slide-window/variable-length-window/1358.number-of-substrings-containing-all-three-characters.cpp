/*
 * @lc app=leetcode id=1358 lang=cpp
 *
 * [1358] Number of Substrings Containing All Three Characters
 *
 * https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
 *
 * algorithms
 * Medium (73.32%)
 * Likes:    4293
 * Dislikes: 80
 * Total Accepted:    399.6K
 * Total Submissions: 544.7K
 * Testcase Example:  '"abcabc"'
 *
 * Given a string s consisting only of characters a, b and c.
 *
 * Return the number of substrings containing at least one occurrence of all
 * these characters a, b and c.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abcabc"
 * Output: 10
 * Explanation: The substrings containing at least one occurrence of the
 * characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab",
 * "bcabc", "cab", "cabc" and "abc" (again).
 *
 *
 * Example 2:
 *
 *
 * Input: s = "aaacb"
 * Output: 3
 * Explanation: The substrings containing at least one occurrence of the
 * characters a, b and c are "aaacb", "aacb" and "acb".
 *
 *
 * Example 3:
 *
 *
 * Input: s = "abc"
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= s.length <= 5 x 10^4
 * s only consists of a, b or c characters.
 *
 *
 */

// @lc code=start
class Solution {
public:
    int numberOfSubstrings(string s) {
      int ans = 0;
      int n = s.size();
      int cnt[3]= {};

      int left = 0, right = 0;
      for (right = 0; right < n; ++right) {
        cnt[s[right] - 'a']++;
        while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
          cnt[s[left] - 'a']--;
          ++left;
        }
        ans += left;
      }
      return ans;
    }
};
// @lc code=end

