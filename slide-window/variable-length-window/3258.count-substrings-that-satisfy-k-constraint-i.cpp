/*
 * @lc app=leetcode id=3258 lang=cpp
 *
 * [3258] Count Substrings That Satisfy K-Constraint I
 *
 * https://leetcode.com/problems/count-substrings-that-satisfy-k-constraint-i/description/
 *
 * algorithms
 * Easy (78.26%)
 * Likes:    167
 * Dislikes: 34
 * Total Accepted:    53.5K
 * Total Submissions: 68.1K
 * Testcase Example:  '"10101"\n1'
 *
 * You are given a binary string s and an integer k.
 *
 * A binary string satisfies the k-constraint if either of the following
 * conditions holds:
 *
 *
 * The number of 0's in the string is at most k.
 * The number of 1's in the string is at most k.
 *
 *
 * Return an integer denoting the number of substrings of s that satisfy the
 * k-constraint.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "10101", k = 1
 *
 * Output: 12
 *
 * Explanation:
 *
 * Every substring of s except the substrings "1010", "10101", and "0101"
 * satisfies the k-constraint.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "1010101", k = 2
 *
 * Output: 25
 *
 * Explanation:
 *
 * Every substring of s except the substrings with a length greater than 5
 * satisfies the k-constraint.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "11111", k = 1
 *
 * Output: 15
 *
 * Explanation:
 *
 * All substrings of s satisfy the k-constraint.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 50
 * 1 <= k <= s.length
 * s[i] is either '0' or '1'.
 *
 *
 */

// @lc code=start
class Solution {
public:
  int countKConstraintSubstrings(string s, int k) {
    int n = s.size();
    int left = 0, right = 0, ans = 0;
    int cnt[2] = {0, 0};
    for (right = 0; right < n; ++right) {
      cnt[s[right] - '0']++;
      while (cnt[0] > k && cnt[1] > k) {
        cnt[s[left] - '0']--;
        ++left;
      }
      ans += right - left + 1;
    }
    return ans;
  }
};
// @lc code=end
