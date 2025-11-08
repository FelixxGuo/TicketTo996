/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (33.30%)
 * Likes:    2463
 * Dislikes: 406
 * Total Accepted:    641.5K
 * Total Submissions: 1.9M
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string s and an array of strings words. All the strings of
 * words are of the same length.
 *
 * A concatenated string is a string that exactly contains all the strings of
 * any permutation of words concatenated.
 *
 *
 * For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef",
 * "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is
 * not a concatenated string because it is not the concatenation of any
 * permutation of words.
 *
 *
 * Return an array of the starting indices of all the concatenated substrings
 * in s. You can return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "barfoothefoobarman", words = ["foo","bar"]
 *
 * Output: [0,9]
 *
 * Explanation:
 *
 * The substring starting at 0 is "barfoo". It is the concatenation of
 * ["bar","foo"] which is a permutation of words.
 * The substring starting at 9 is "foobar". It is the concatenation of
 * ["foo","bar"] which is a permutation of words.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "wordgoodgoodgoodbestword", words =
 * ["word","good","best","word"]
 *
 * Output: []
 *
 * Explanation:
 *
 * There is no concatenated substring.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
 *
 * Output: [6,9,12]
 *
 * Explanation:
 *
 * The substring starting at 6 is "foobarthe". It is the concatenation of
 * ["foo","bar","the"].
 * The substring starting at 9 is "barthefoo". It is the concatenation of
 * ["bar","the","foo"].
 * The substring starting at 12 is "thefoobar". It is the concatenation of
 * ["the","foo","bar"].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * 1 <= words.length <= 5000
 * 1 <= words[i].length <= 30
 * s and words[i] consist of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
public:
  vector<int> findSubstring(string s, vector<string> &words) {
    int sLen = s.size();
    int wordLen = words[0].size();
    int wordsLen = wordLen * words.size();

    vector<int> ans;
    if (wordsLen > sLen) {
      return ans;
    }
    unordered_map<string, int> wordMap;
    for (const string &word : words) {
      wordMap[word]++;
    }

    int start = 0, left = 0, right = 0;

    for (start = 0; start < wordLen; ++start) {
      unordered_map<string, int> cnt;
      int overLoaded = 0;
      for (right = start + wordLen - 1; right < sLen; right += wordLen) {
        string inWord = s.substr(right - wordLen + 1, wordLen);
        if (cnt[inWord] == wordMap[inWord]) {
          overLoaded++;
        }
        cnt[inWord]++;
        left = right - wordsLen + 1;
        if (left < 0) {
          continue;
        }
        if (overLoaded == 0) {
          ans.push_back(left);
        }
        string outWord = s.substr(left, wordLen);
        cnt[outWord]--;
        if (cnt[outWord] == wordMap[outWord]) {
          --overLoaded;
        }
      }
    }
    return ans;
  }
};
// @lc code=end
