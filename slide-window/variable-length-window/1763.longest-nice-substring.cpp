/*
 * @lc app=leetcode id=1763 lang=cpp
 *
 * [1763] Longest Nice Substring
 *
 * https://leetcode.com/problems/longest-nice-substring/description/
 *
 * algorithms
 * Easy (63.02%)
 * Likes:    1468
 * Dislikes: 958
 * Total Accepted:    85.2K
 * Total Submissions: 134.9K
 * Testcase Example:  '"YazaAay"'
 *
 * A string s is nice if, for every letter of the alphabet that s contains, it
 * appears both in uppercase and lowercase. For example, "abABB" is nice
 * because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not
 * because 'b' appears, but 'B' does not.
 *
 * Given a string s, return the longest substring of s that is nice. If there
 * are multiple, return the substring of the earliest occurrence. If there are
 * none, return an empty string.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "YazaAay"
 * Output: "aAa"
 * Explanation: "aAa" is a nice string because 'A/a' is the only letter of the
 * alphabet in s, and both 'A' and 'a' appear.
 * "aAa" is the longest nice substring.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "Bb"
 * Output: "Bb"
 * Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The
 * whole string is a substring.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "c"
 * Output: ""
 * Explanation: There are no nice substrings.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 100
 * s consists of uppercase and lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution1 {
public:
  string longestNiceSubstring(string s) {
    auto p0 = findSubStr(s, 1);
    for (int i = 2; i <= 26; ++i) {
      auto p1 = findSubStr(s, i);
      if (p0.second < p1.second) {
        p0 = p1;
      }
    }
    if (p0.first != -1) {
      return s.substr(p0.first, p0.second);
    }
    return "";
  }

private:
  pair<int, int> findSubStr(const string &s, int count) {
    int n = s.size(), unique = 0;
    int left = 0, right = 0;
    int val = 0, index = -1, len = 0;
    vector<int> cnt(52, 0);
    for (right = 0; right < n; ++right) {
      val = getIndex(s[right]);
      if (cnt[val]++ == 0 && cnt[(val + 26) % 52] == 0) {
        ++unique;
      }
      while (unique > count) {
        val = getIndex(s[left]);
        cnt[val]--;
        if (cnt[val] == 0 && cnt[(val + 26) % 52] == 0) {
          --unique;
        }
        ++left;
      }
      if (count == unique) {
        bool same = true;
        for (int j = 0; j < 26; ++j) {
          if (cnt[j] == 0 && cnt[j + 26] != 0) {
            same = false;
            break;
          }
          if (cnt[j] != 0 && cnt[j + 26] == 0) {
            same = false;
            break;
          }
        }
        if (same) {
          if (right - left + 1 > len) {
            index = left;
            len = right - left + 1;
          }
        }
      }
    }
    return pair<int, int>{index, len};
  }

private:
  int getIndex(char c) {
    if ('A' <= c && c <= 'Z') {
      return c - 'A';
    }
    return c - 'a' + 26;
  }
};

class Solution {
public:
  string longestNiceSubstring(string s) {
    auto p0 = findSubStr(s, 1);
    for (int i = 2; i <= 26; ++i) {
      auto p1 = findSubStr(s, i);
      if (p0.second < p1.second) {
        p0 = p1;
      }
    }
    if (p0.first == -1) {
      return "";
    }
    return s.substr(p0.first, p0.second);
  }

private:
  pair<int, int> findSubStr(const string &s, int count) {
    int n = s.size(), left = 0, right = 0;
    int index = -1, len = 0;
    unordered_map<int, int> smallCnt, bigCnt;
    for (right = 0; right < n; ++right) {
      if ('a' <= s[right] && s[right] <= 'z') {
        smallCnt[s[right] - 'a']++;
      } else {
        bigCnt[s[right] - 'A']++;
      }
      while (smallCnt.size() > count || bigCnt.size() > count) {
        if ('a' <= s[left] && s[left] <= 'z') {
          smallCnt[s[left] - 'a']--;
          if (smallCnt[s[left] - 'a'] == 0) {
            smallCnt.erase(s[left] - 'a');
          }
        } else {
          bigCnt[s[left] - 'A']--;
          if (bigCnt[s[left] - 'A'] == 0) {
            bigCnt.erase(s[left] - 'A');
          }
        }
        ++left;
      }
      if (smallCnt.size() == bigCnt.size()) {
        bool isSame = true;
        for (auto &item : smallCnt) {
          if (bigCnt.find(item.first) == bigCnt.end()) {
            isSame = false;
            break;
          }
        }
        if (isSame && right - left + 1 > len) {
          len = right - left + 1;
          index = left;
        }
      }
    }
    return {index, len};
  }
};
// @lc code=end
