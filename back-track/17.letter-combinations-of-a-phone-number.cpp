/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (64.51%)
 * Likes:    20385
 * Dislikes: 1106
 * Total Accepted:    2.8M
 * Total Submissions: 4.3M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in
 * any order.
 *
 * A mapping of digits to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 * Example 1:
 *
 *
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 *
 * Example 2:
 *
 *
 * Input: digits = "2"
 * Output: ["a","b","c"]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 *
 *
 */

// @lc code=start
class Solution1 {
public:
  unordered_map<char, vector<char>> map = {
      {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
      {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
      {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
      {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}},
  };
  vector<string> letterCombinations(string digits) {
    vector<string> res;
    string path;
    int index = 0;
    backtrack(digits, path, res, index);
    return res;
  }

private:
  void backtrack(string digits, string &path, vector<string> &res, int index) {
    if (path.size() == digits.size()) {
      res.push_back(path);
      return;
    }
    for (int i = index; i < digits.size(); ++i) {
      for (int j = 0; j < map[digits[i]].size(); ++j) {
        path += map[digits[i]][j];
        backtrack(digits, path, res, i + 1);
        path.pop_back();
      }
    }
  }
};

class Solution {
public:
  vector<string> letters = {
      "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
  };
  vector<string> letterCombinations(string digits) {
    vector<string> res;
    string path;
    int index = 0;
    backtrack(digits, res, path, index);
    return res;
  }

private:
  void backtrack(const string &digits, vector<string> &res, string &path,
                 int index) {
    if (index == digits.size()) {
      res.push_back(path);
      return;
    }
    int d = digits[index] - '0';
    string s = letters[d];
    for (int i = 0; i < s.size(); ++i) {
      path += s[i];
      backtrack(digits, res, path, index + 1);
      path.pop_back();
    }
  }
};
// @lc code=end
