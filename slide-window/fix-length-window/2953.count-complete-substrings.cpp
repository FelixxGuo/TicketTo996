/*
 * @lc app=leetcode id=2953 lang=cpp
 *
 * [2953] Count Complete Substrings
 *
 * https://leetcode.com/problems/count-complete-substrings/description/
 *
 * algorithms
 * Hard (29.12%)
 * Likes:    252
 * Dislikes: 39
 * Total Accepted:    10.3K
 * Total Submissions: 35.1K
 * Testcase Example:  '"igigee"\n2'
 *
 * You are given a string word and an integer k.
 *
 * A substring s of word is complete if:
 *
 *
 * Each character in s occurs exactly k times.
 * The difference between two adjacent characters is at most 2. That is, for
 * any two adjacent characters c1 and c2 in s, the absolute difference in their
 * positions in the alphabet is at most 2.
 *
 *
 * Return the number of complete substrings of word.
 *
 * A substring is a non-empty contiguous sequence of characters in a string.
 *
 *
 * Example 1:
 *
 *
 * Input: word = "igigee", k = 2
 * Output: 3
 * Explanation: The complete substrings where each character appears exactly
 * twice and the difference between adjacent characters is at most 2 are:
 * igigee, igigee, igigee.
 *
 *
 * Example 2:
 *
 *
 * Input: word = "aaabbbccc", k = 3
 * Output: 6
 * Explanation: The complete substrings where each character appears exactly
 * three times and the difference between adjacent characters is at most 2 are:
 * aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc, aaabbbccc.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word.length <= 10^5
 * word consists only of lowercase English letters.
 * 1 <= k <= word.length
 *
 *
 */

// @lc code=start
class Solution {
public:
  int countCompleteSubstrings(string word, int k) {
    int n = word.size(), i = 0;
    int start = 0, ans = 0;
    while (i < n) {
      start = i;
      ++i;
      while (i < n && abs(word[i] - word[i - 1]) <= 2) {
        ++i;
      }
      ans += f(word, start, i, k);
    }
    return ans;
  }

private:
  int f(const string &word, int start, int end, int k) {
    int ans = 0;
    for (int i = 1; i <= 26; ++i) {
      vector<int> cnt(26, 0);
      int win = k * i;
      int left = 0, right = 0;
      if (win > end - start) {
        break;
      }
      for (right = start; right < end; ++right) {
        cnt[word[right] - 'a']++;
        left = right - win + 1;
        if (left < start) {
          continue;
        }
        for (int j = 0; j < 26; ++j) {
          if (cnt[j] != 0 && cnt[j] != k) {
            break;
          }
          if (j == 25) {
            ans += 1;
          }
        }
        cnt[word[left] - 'a']--;
      }
    }
    return ans;
  }
};
// @lc code=end
