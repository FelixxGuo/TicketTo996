/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (54.01%)
 * Likes:    5542
 * Dislikes: 816
 * Total Accepted:    577.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '"25525511135"'
 *
 * A valid IP address consists of exactly four integers separated by single
 * dots. Each integer is between 0 and 255 (inclusive) and cannot have leading
 * zeros.
 *
 *
 * For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but
 * "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP
 * addresses.
 *
 *
 * Given a string s containing only digits, return all possible valid IP
 * addresses that can be formed by inserting dots into s. You are not allowed
 * to reorder or remove any digits in s. You may return the valid IP addresses
 * in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "25525511135"
 * Output: ["255.255.11.135","255.255.111.35"]
 *
 *
 * Example 2:
 *
 *
 * Input: s = "0000"
 * Output: ["0.0.0.0"]
 *
 *
 * Example 3:
 *
 *
 * Input: s = "101023"
 * Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 20
 * s consists of digits only.
 *
 *
 */

// @lc code=start
class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    string path;
    int n = s.size();
    if (n < 4 || n > 12) {
      return res;
    }
    int count = 0;
    int start = 0;
    backtrack(s, path, res, start, count);
    return res;
  }

private:
  void backtrack(const string &s, string &path, vector<string> &res, int start,
                 int count) {
    int n = s.size();
    if (count == 3) {
      if (valid(s, start, n - 1)) {
        path += s.substr(start);
        res.push_back(path);
        return;
      }
    }

    int remain = n - start;
    int minNeed = (4 - count);
    int maxNeed = (4 - count) * 3;
    if (remain > maxNeed || remain < minNeed) {
      return;
    }

    for (int i = start; i < s.size(); ++i) {
      if (i - start >= 3) {
        break;
      }
      if (valid(s, start, i)) {
        int len = path.size();
        path += s.substr(start, i - start + 1);
        path += '.';
        backtrack(s, path, res, i + 1, count + 1);
        path.erase(len);
      } else {
        break;
      }
    }
  }

private:
  bool valid(const string &s, int i, int j) {
    int len = j - i + 1;
    if (len <= 0 || len > 3) {
      return false;
    }
    if (s[i] == '0' && len > 1) {
      return false;
    }
    int num = 0;
    for (int k = i; k <= j; ++k) {
      num = 10 * num + s[k] - '0';
    }
    return num >= 0 && num <= 255;
  }
};
// @lc code=end
