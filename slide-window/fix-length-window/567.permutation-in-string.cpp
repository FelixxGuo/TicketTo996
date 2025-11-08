/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (47.76%)
 * Likes:    12669
 * Dislikes: 509
 * Total Accepted:    1.3M
 * Total Submissions: 2.8M
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1,
 * or false otherwise.
 *
 * In other words, return true if one of s1's permutations is the substring of
 * s2.
 *
 *
 * Example 1:
 *
 *
 * Input: s1 = "ab", s2 = "eidbaooo"
 * Output: true
 * Explanation: s2 contains one permutation of s1 ("ba").
 *
 *
 * Example 2:
 *
 *
 * Input: s1 = "ab", s2 = "eidboaoo"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s1.length, s2.length <= 10^4
 * s1 and s2 consist of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution1 {
public:
  bool checkInclusion(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    vector<int> cnt(26, 0);
    for (int i = 0; i < n1; ++i) {
      cnt[s1[i] - 'a']++;
    }
    for (int i = 0; i < n2; ++i) {
      char c = s2[i] - 'a';
      cnt[c]--;
      if (i - n1 + 1 < 0) {
        continue;
      }
      if (checkZeros(cnt)) {
        return true;
      }
      c = s2[i - n1 + 1] - 'a';
      ++cnt[c];
    }
    return false;
  }

private:
  bool checkZeros(vector<int> cnt) {
    for (int i = 0; i < cnt.size(); ++i) {
      if (cnt[i] != 0) {
        return false;
      }
    }
    return true;
  }
};
// optimize the without to compare the vector
class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    if (n1 > n2) {
      return false;
    }
    vector<int> cnt(26, 0);
    int less = 0;
    for (int i = 0; i < n1; ++i) {
      char c = s1[i] - 'a';
      if (cnt[c] == 0) {
        ++less;
      }
      cnt[c]++;
    }
    for (int i = 0; i < n2; ++i) {
      char c = s2[i] - 'a';
      if (--cnt[c] == 0) {
        --less;
      }
      if (i - n1 + 1 < 0) {
        continue;
      }
      if (less == 0) {
        return true;
      }
      c = s2[i - n1 + 1] - 'a';
      if (cnt[c]++ == 0) {
        ++less;
      }
    }
    return false;
  }
};
// @lc code=end
