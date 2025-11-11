/*
 * @lc app=leetcode id=1016 lang=cpp
 *
 * [1016] Binary String With Substrings Representing 1 To N
 *
 * https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/description/
 *
 * algorithms
 * Medium (58.12%)
 * Likes:    379
 * Dislikes: 539
 * Total Accepted:    46.6K
 * Total Submissions: 80K
 * Testcase Example:  '"0110"\n3'
 *
 * Given a binary string s and a positive integer n, return true if the binary
 * representation of all the integers in the range [1, n] are substrings of s,
 * or false otherwise.
 *
 * A substring is a contiguous sequence of characters within a string.
 *
 *
 * Example 1:
 * Input: s = "0110", n = 3
 * Output: true
 * Example 2:
 * Input: s = "0110", n = 4
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s[i] is either '0' or '1'.
 * 1 <= n <= 10^9
 *
 *
 */

// @lc code=start
class Solution1 {
public:
  bool queryString(string s, int n) {
    int m = s.size();
    unordered_set<int> seen;
    for (int i = 0; i < m; ++i) {
      if (s[i] == '0') {
        continue;
      }
      int x = 0;
      for (int j = i; j < m; ++j) {
        x = (x << 1) | (s[j] - '0');
        if (x > n) {
          break;
        }
        seen.insert(x);
      }
    }
    return seen.size() == n;
  }
};

class Solution2 {
public:
  bool queryString(string s, int n) {
    for (int i = 1; i <= n; ++i) {
      string bits = bitset<32>(i).to_string();
      bits = bits.substr(bits.find('1'));
      if (s.find(bits) == string::npos) {
        return false;
      }
    }
    return true;
  }
};

class Solution {
public:
  bool queryString(string s, int n) {
    if (n == 1) {
      return s.find("1") != string::npos;
    }

    int k = 31 - __builtin_clz(n);
    int m = s.size();
    // [2^k, n], [2^(k - 1), 2^k - 1]
    // [2^k, n]: length must be k + 1 + (n - 2^k + 1 - 1) = n - 2^k + k + 1
    // [2^(k - 1), 2^k - 1]: length must be k + (2^k - 1 - 2^(k - 1) + 1 - 1) =
    // 2^(k - 1) + k - 1
    if (m < max(n - (1 << k) + k + 1, (1 << (k - 1)) + k - 1)) {
      return false;
    }
    auto check = [&](int k, int lower, int upper) -> bool {
      if (lower > upper) {
        return true;
      }
      unordered_set<int> seen;
      int mask = (1 << (k - 1)) - 1;
      int x = stoi(s.substr(0, k - 1), nullptr, 2);

      for (int i = k - 1; i < m; ++i) {
        x = ((x & mask) << 1) | (s[i] - '0');
        if (lower <= x && x <= upper) {
          seen.insert(x);
        }
      }
      return seen.size() == upper - lower + 1;
    };
    return check(k, n / 2 + 1, (1 << k) - 1) && check(k + 1, 1 << k, n);
  }
};
// @lc code=end
