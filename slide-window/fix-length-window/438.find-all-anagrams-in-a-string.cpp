/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (52.61%)
 * Likes:    12976
 * Dislikes: 365
 * Total Accepted:    1.1M
 * Total Submissions: 2.1M
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given two strings s and p, return an array of all the start indices of p's
 * anagrams in s. You may return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "cbaebabacd", p = "abc"
 * Output: [0,6]
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "abab", p = "ab"
 * Output: [0,1,2]
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, p.length <= 3 * 10^4
 * s and p consist of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution1 {
public:
  vector<int> findAnagrams(string s, string p) {
    int n1 = s.size(), n2 = p.size();
    vector<int> ans;
    if (n2 > n1) {
      return ans;
    }
    vector<int> cnt(26, 0);
    int less = 0;
    for (int i = 0; i < n2; ++i) {
      int c = p[i] - 'a';
      if (cnt[c] == 0) {
        ++less;
      }
      cnt[c]++;
    }
    for (int i = 0; i < n1; ++i) {
      int c = s[i] - 'a';
      cnt[c]--;
      if (cnt[c] == 0) {
        --less;
      }
      if (i - n2 + 1 < 0) {
        continue;
      }
      if (less == 0) {
        ans.push_back(i - n2 + 1);
      }
      c = s[i - n2 + 1] - 'a';
      if (cnt[c]++ == 0) {
        ++less;
      }
    }
    return ans;
  }
};

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    int n1 = s.size(), n2 = p.size();
    vector<int> ans;
    if (n2 > n1) {
      return ans;
    }

    int left = 0, right = 0;
    vector<int> cnt(26, 0);
    for (int i = 0; i < n2; ++i) {
      int c = p[i] - 'a';
      cnt[c]++;
    }

    for (right = 0; right < n1; ++right) {
      int inC = s[right] - 'a';
      cnt[inC]--;
      while (cnt[inC] < 0) {
        int outC = s[left] - 'a';
        cnt[outC]++;
        left++;
      }
      if (right - left + 1 == n2) {
        ans.push_back(left);
      }
    }
    return ans;
  }
};
// @lc code=end
