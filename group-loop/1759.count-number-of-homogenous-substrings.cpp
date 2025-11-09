/*
 * @lc app=leetcode id=1759 lang=cpp
 *
 * [1759] Count Number of Homogenous Substrings
 *
 * https://leetcode.com/problems/count-number-of-homogenous-substrings/description/
 *
 * algorithms
 * Medium (57.28%)
 * Likes:    1567
 * Dislikes: 104
 * Total Accepted:    127.6K
 * Total Submissions: 222.8K
 * Testcase Example:  '"abbcccaa"'
 *
 * Given a string s, return the number of homogenous substrings of s. Since the
 * answer may be too large, return it modulo 10^9 + 7.
 *
 * A string is homogenous if all the characters of the string are the same.
 *
 * A substring is a contiguous sequence of characters within a string.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abbcccaa"
 * Output: 13
 * Explanation: The homogenous substrings are listed as below:
 * "a"   appears 3 times.
 * "aa"  appears 1 time.
 * "b"   appears 2 times.
 * "bb"  appears 1 time.
 * "c"   appears 3 times.
 * "cc"  appears 2 times.
 * "ccc" appears 1 time.
 * 3 + 1 + 2 + 1 + 3 + 2 + 1 = 13.
 *
 * Example 2:
 *
 *
 * Input: s = "xy"
 * Output: 2
 * Explanation: The homogenous substrings are "x" and "y".
 *
 * Example 3:
 *
 *
 * Input: s = "zzzzz"
 * Output: 15
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists of lowercase letters.
 *
 *
 */

// @lc code=start
class Solution {
public:
  int countHomogenous(string s) {
    int n = s.size(), i = 0;
    int ans = 0;
    while (i < n) {
      int start = i;
      ++i;
      while (i < n && s[i] == s[i - 1]) {
        ++i;
      }
      long long len = i - start;
      ans = (ans + (len + 1) * len / 2) % (1000000000 + 7);
    }
    return ans;
  }
};
// @lc code=end
