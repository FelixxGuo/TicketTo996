/*
 * @lc app=leetcode id=1888 lang=cpp
 *
 * [1888] Minimum Number of Flips to Make the Binary String Alternating
 *
 * https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/
 *
 * algorithms
 * Medium (40.71%)
 * Likes:    1283
 * Dislikes: 83
 * Total Accepted:    35.2K
 * Total Submissions: 86.3K
 * Testcase Example:  '"111000"'
 *
 * You are given a binary string s. You are allowed to perform two types of
 * operations on the string in any sequence:
 *
 *
 * Type-1: Remove the character at the start of the string s and append it to
 * the end of the string.
 * Type-2: Pick any character in s and flip its value, i.e., if its value is
 * '0' it becomes '1' and vice-versa.
 *
 *
 * Return the minimum number of type-2 operations you need to perform such that
 * s becomes alternating.
 *
 * The string is called alternating if no two adjacent characters are
 * equal.
 *
 *
 * For example, the strings "010" and "1010" are alternating, while the string
 * "0100" is not.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s = "111000"
 * Output: 2
 * Explanation: Use the first operation two times to make s = "100011".
 * Then, use the second operation on the third and sixth elements to make s =
 * "101010".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "010"
 * Output: 0
 * Explanation: The string is already alternating.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "1110"
 * Output: 1
 * Explanation: Use the second operation on the second element to make s =
 * "1010".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s[i] is either '0' or '1'.
 *
 *
 */

// @lc code=start
class Solution1 {
public:
  int minFlips(string s) {
    int n = s.size();
    int ans = n, cnt = 0, left = 0;
    for (int i = 0; i < n * 2 - 1; ++i) {
      if (s[i % n] % 2 != i % 2) {
        ++cnt;
      }
      left = i - n + 1;
      if (left < 0) {
        continue;
      }
      ans = min(ans, min(cnt, n - cnt));
      if (s[left % n] % 2 != left % 2) {
        --cnt;
      }
    }
    return ans;
  }
};

// xor
class Solution {
public:
  int minFlips(string s) {
    int n = s.size();
    int ans = n, cnt = 0, left = 0;
    for (int i = 0; i < 2 * n - 1; ++i) {
      cnt += (s[i % n] ^ i) & 1;
      left = i - n + 1;
      if (left < 0) {
        continue;
      }
      ans = min(ans, min(cnt, n - cnt));
      if ((s[left % n] ^ left) & 1) {
        --cnt;
      }
    }
    return ans;
  }
};
// @lc code=end
