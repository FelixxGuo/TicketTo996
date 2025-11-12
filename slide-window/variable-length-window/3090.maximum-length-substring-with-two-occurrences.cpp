/*
 * @lc app=leetcode id=3090 lang=cpp
 *
 * [3090] Maximum Length Substring With Two Occurrences
 *
 * https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/description/
 *
 * algorithms
 * Easy (64.27%)
 * Likes:    245
 * Dislikes: 20
 * Total Accepted:    58K
 * Total Submissions: 89.8K
 * Testcase Example:  '"bcbbbcba"'
 *
 * Given a string s, return the maximum length of a substring such that it
 * contains at most two occurrences of each character.
 *
 * Example 1:
 *
 *
 * Input: s = "bcbbbcba"
 *
 * Output: 4
 *
 * Explanation:
 * The following substring has a length of 4 and contains at most two
 * occurrences of each character: "bcbbbcba".
 *
 * Example 2:
 *
 *
 * Input: s = "aaaa"
 *
 * Output: 2
 *
 * Explanation:
 * The following substring has a length of 2 and contains at most two
 * occurrences of each character: "aaaa".
 *
 *
 * Constraints:
 *
 *
 * 2 <= s.length <= 100
 * s consists only of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
public:
  int maximumLengthSubstring(string s) {
    int ans = 0, n = s.size();
    int left = 0, right = 0;
    vector<int> cnt(26, 0);
    for (right = 0; right < n; ++right) {
      int inVal = s[right] - 'a';
      cnt[inVal]++;
      while (cnt[inVal] > 2) {
        int outVal = s[left] - 'a';
        cnt[outVal]--;
        ++left;
      }
      ans = max(ans, right - left + 1);
    }
    return ans;
  }
};
// @lc code=end
