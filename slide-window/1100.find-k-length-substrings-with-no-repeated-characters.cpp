/*
 * 1100. Find K-Length Substrings With No Repeated Characters
 * Given a string S, return the number of substrings of length K with no
 * repeated characters.
 *
 *
 *
 * Example 1:
 *
 * Input: S = "havefunonleetcode", K = 5
 * Output: 6
 * Explanation:
 * There are 6 substrings they are :
 * 'havef','avefu','vefun','efuno','etcod','tcode'. Example 2:
 *
 * Input: S = "home", K = 5
 * Output: 0
 * Explanation:
 * Notice K can be larger than the length of S. In this case is not possible to
 * find any substring.
 *
 *
 * Note:
 *
 * 1 <= S.length <= 10^4
 * All characters of S are lowercase English letters.
 * 1 <= K <= 10^4
 * Difficulty:
 * Medium
 * Lock:
 * Prime
 * Company:
 * Amazon
 */

class Solution {
public:
  int numKLenSubstrNoRepeats(string s, int k) {
    int n = s.size();
    if (k > n) {
      return 0;
    }
    int ans = 0;
    int left = 0, right = 0;
    unordered_map<char, int> uMap;
    for (right = 0; right < n; ++right) {
      uMap[s[right]]++;
      left = right - k + 1;
      if (left < 0) {
        continue;
      }

      if (uMap.size() == k) {
        ++ans;
      }
      if (--uMap[s[left]] == 0) {
        uMap.erase(s[left]);
      }
    }
    return ans;
  }
};

class Solution {
public:
  int numKLenSubstrNoRepeats(string s, int k) {
    int left = 0, right = 0;
    int n = s.size();
    if (k > n) {
      return 0;
    }
    vector<int> freq(26, 0);
    int unique = 0, ans = 0;

    for (right = 0; right < n; ++right) {
      int letterR = s[right] - 'a';
      if (freq[letterR]++ == 0) {
        ++unique;
      }
      left = right - k + 1;
      if (left < 0) {
        continue;
      }
      if (unique == k) {
        ++ans;
      }
      int letterL = s[left] - 'a';
      if (--freq[letterL] == 0) {
        --unique;
      }
    }
    return ans;
  }
};