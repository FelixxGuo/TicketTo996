/*
 * @lc app=leetcode id=2516 lang=cpp
 *
 * [2516] Take K of Each Character From Left and Right
 *
 * https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/description/
 *
 * algorithms
 * Medium (51.54%)
 * Likes:    1501
 * Dislikes: 168
 * Total Accepted:    112.1K
 * Total Submissions: 217.3K
 * Testcase Example:  '"aabaaaacaabc"\n2'
 *
 * You are given a string s consisting of the characters 'a', 'b', and 'c' and
 * a non-negative integer k. Each minute, you may take either the leftmost
 * character of s, or the rightmost character of s.
 *
 * Return the minimum number of minutes needed for you to take at least k of
 * each character, or return -1 if it is not possible to take k of each
 * character.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aabaaaacaabc", k = 2
 * Output: 8
 * Explanation:
 * Take three characters from the left of s. You now have two 'a' characters,
 * and one 'b' character.
 * Take five characters from the right of s. You now have four 'a' characters,
 * two 'b' characters, and two 'c' characters.
 * A total of 3 + 5 = 8 minutes is needed.
 * It can be proven that 8 is the minimum number of minutes needed.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "a", k = 1
 * Output: -1
 * Explanation: It is not possible to take one 'b' or 'c' so return -1.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists of only the letters 'a', 'b', and 'c'.
 * 0 <= k <= s.length
 *
 *
 */

// @lc code=start
class Solution {
public:
  int takeCharacters(string s, int k) {
    vector<int> cnt(3, 0);
    vector<int> window(3, 0);
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      cnt[s[i] - 'a']++;
    }
    int remainA = cnt[0] - k, remainB = cnt[1] - k, remainC = cnt[2] - k;
    if (remainA < 0 || remainB < 0 || remainC < 0) {
      return -1;
    }

    int left = 0, right = 0, ans = n;
    for (right = 0; right < n; ++right) {
      window[s[right] - 'a']++;
      if (window[0] > remainA || window[1] > remainB || window[2] > remainC) {
        window[s[left] - 'a']--;
        ++left;
      }
      ans = min(ans, n - (right - left + 1));
    }
    return ans;
  }
};
// @lc code=end
