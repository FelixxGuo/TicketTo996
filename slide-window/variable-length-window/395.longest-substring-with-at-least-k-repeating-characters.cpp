/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
 *
 * algorithms
 * Medium (45.65%)
 * Likes:    6621
 * Dislikes: 563
 * Total Accepted:    279.7K
 * Total Submissions: 611.5K
 * Testcase Example:  '"aaabb"\n3'
 *
 * Given a string s and an integer k, return the length of the longest
 * substring of s such that the frequency of each character in this substring
 * is greater than or equal to k.
 *
 * if no such substring exists, return 0.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aaabb", k = 3
 * Output: 3
 * Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "ababbc", k = 2
 * Output: 5
 * Explanation: The longest substring is "ababb", as 'a' is repeated 2 times
 * and 'b' is repeated 3 times.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of only lowercase English letters.
 * 1 <= k <= 10^5
 *
 *
 */

// @lc code=start
class Solution {
public:
  int longestSubstring(string s, int k) {
    int ans = 0;
    for (int i = 1; i <= 26; ++i) {
      ans = max(ans, findSubStr(s, k, i));
    }
    return ans;
  }

private:
  int findSubStr(const string &s, int k, int count) {
    int n = s.size(), res = 0;
    int left = 0, right = 0;
    vector<int> cnt(26, 0);
    int unique = 0, valid = 0;
    for (right = 0; right < n; ++right) {
      int val = s[right] - 'a';
      if (cnt[val] == 0) {
        ++unique;
      }
      cnt[val]++;
      if (cnt[val] == k) {
        valid++;
      }
      while (unique > count) {
        val = s[left] - 'a';
        if (cnt[val] == k) {
          valid--;
        }
        cnt[val]--;
        if (cnt[val] == 0) {
          --unique;
        }
        ++left;
      }
      if (valid == count) {
        res = max(res, right - left + 1);
      }
    }
    return res;
  }
};
// @lc code=end
