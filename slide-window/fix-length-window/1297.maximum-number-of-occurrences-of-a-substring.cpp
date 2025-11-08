/*
 * @lc app=leetcode id=1297 lang=cpp
 *
 * [1297] Maximum Number of Occurrences of a Substring
 *
 * https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/description/
 *
 * algorithms
 * Medium (53.78%)
 * Likes:    1208
 * Dislikes: 422
 * Total Accepted:    78K
 * Total Submissions: 144.8K
 * Testcase Example:  '"aababcaab"\n2\n3\n4'
 *
 * Given a string s, return the maximum number of occurrences of any substring
 * under the following rules:
 *
 *
 * The number of unique characters in the substring must be less than or equal
 * to maxLetters.
 * The substring size must be between minSize and maxSize inclusive.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
 * Output: 2
 * Explanation: Substring "aab" has 2 occurrences in the original string.
 * It satisfies the conditions, 2 unique letters and size 3 (between minSize
 * and maxSize).
 *
 *
 * Example 2:
 *
 *
 * Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
 * Output: 2
 * Explanation: Substring "aaa" occur 2 times in the string. It can
 * overlap.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * 1 <= maxLetters <= 26
 * 1 <= minSize <= maxSize <= min(26, s.length)
 * s consists of only lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
public:
  int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    int n = s.size();
    int left = 0, right = 0, ans = 0, num = 0;

    vector<int> letters(26, 0);
    unordered_map<string, int> cntMap;
    string windowStr;

    for (right = 0; right < n; ++right) {
      if (letters[s[right] - 'a']++ == 0) {
        num++;
      }
      left = right - minSize + 1;
      if (left < 0) {
        continue;
      }
      if (num <= maxLetters) {
        windowStr = s.substr(left, minSize);
        cntMap[windowStr]++;
        ans = max(ans, cntMap[windowStr]);
      }
      if (--letters[s[left] - 'a'] == 0) {
        num--;
      }
    }
    return ans;
  }
};
// @lc code=end
