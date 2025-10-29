/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (72.90%)
 * Likes:    13962
 * Dislikes: 563
 * Total Accepted:    1.2M
 * Total Submissions: 1.7M
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome. Return all possible palindrome partitioning of s.
 *
 *
 * Example 1:
 * Input: s = "aab"
 * Output: [["a","a","b"],["aa","b"]]
 * Example 2:
 * Input: s = "a"
 * Output: [["a"]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 16
 * s contains only lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution1 {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> path;
    int index = 0;
    backtrack(s, path, res, index);
    return res;
  }

private:
  bool isPalindrome(const string &s, int start, int end) {
    int i = start;
    int j = end;
    while (i < j) {
      if (s[i] != s[j]) {
        return false;
      }
      ++i;
      --j;
    }
    return true;
  }
  void backtrack(const string &s, vector<string> &path,
                 vector<vector<string>> &res, int index) {
    if (index == s.size()) {
      res.push_back(path);
      return;
    }
    for (int i = index; i < s.size(); ++i) {
      if (isPalindrome(s, index, i)) {
        path.push_back(s.substr(index, i - index + 1));
        backtrack(s, path, res, i + 1);
        path.pop_back();
      }
    }
  }
};

class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<bool>> palindromeMap(s.size(), vector<bool>(s.size(), false));
    computePalindrome(s, palindromeMap);
    int start = 0;
    backtrack(s, palindromeMap, path, res, start);
    return res;
  }

private:
  void computePalindrome(const string &s, vector<vector<bool>> &map) {
    for (int i = s.size() - 1; i >= 0; --i) {
      for (int j = i; j < s.size(); ++j) {
        if (i == j) {
          map[i][j] = true;
        } else if (j - i == 1) {
          map[i][j] = (s[i] == s[j]);
        } else {
          map[i][j] = (map[i + 1][j - 1] && s[i] == s[j]);
        }
      }
    }
  }
  void backtrack(const string &s, vector<vector<bool>> &map,
                 vector<string> &path, vector<vector<string>> &res, int index) {
    if (index == s.size()) {
      res.push_back(path);
      return;
    }
    for (int i = index; i < s.size(); ++i) {
      if (map[index][i]) {
        path.push_back(s.substr(index, i - index + 1));
        backtrack(s, map, path, res, i + 1);
        path.pop_back();
      }
    }
  }
};
// @lc code=end
