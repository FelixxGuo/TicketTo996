/*
 * @lc app=leetcode id=3261 lang=cpp
 *
 * [3261] Count Substrings That Satisfy K-Constraint II
 *
 * https://leetcode.com/problems/count-substrings-that-satisfy-k-constraint-ii/description/
 *
 * algorithms
 * Hard (22.15%)
 * Likes:    140
 * Dislikes: 12
 * Total Accepted:    5.5K
 * Total Submissions: 24.5K
 * Testcase Example:  '"0001111"\n2\n[[0,6]]'
 *
 * You are given a binary string s and an integer k.
 *
 * You are also given a 2D integer array queries, where queries[i] = [li, ri].
 *
 * A binary string satisfies the k-constraint if either of the following
 * conditions holds:
 *
 *
 * The number of 0's in the string is at most k.
 * The number of 1's in the string is at most k.
 *
 *
 * Return an integer array answer, where answer[i] is the number of substrings
 * of s[li..ri] that satisfy the k-constraint.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "0001111", k = 2, queries = [[0,6]]
 *
 * Output: [26]
 *
 * Explanation:
 *
 * For the query [0, 6], all substrings of s[0..6] = "0001111" satisfy the
 * k-constraint except for the substrings s[0..5] = "000111" and s[0..6] =
 * "0001111".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "010101", k = 1, queries = [[0,5],[1,4],[2,3]]
 *
 * Output: [15,9,3]
 *
 * Explanation:
 *
 * The substrings of s with a length greater than 3 do not satisfy the
 * k-constraint.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s[i] is either '0' or '1'.
 * 1 <= k <= s.length
 * 1 <= queries.length <= 10^5
 * queries[i] == [li, ri]
 * 0 <= li <= ri < s.length
 * All queries are distinct.
 *
 *
 */

// @lc code=start
class Solution {
public:
  vector<long long> countKConstraintSubstrings(string s, int k,
                                               vector<vector<int>> &queries) {
    int n = queries.size();
    vector<long long> ans(n, 0LL);

    vector<int> left(s.size(), 0);
    vector<long long> sum(s.size() + 1, 0LL);
    int cnt[2] = {0, 0};
    int leftIndex = 0;
    for (int i = 0; i < s.size(); ++i) {
      cnt[s[i] - '0']++;
      while (cnt[0] > k && cnt[1] > k) {
        cnt[s[leftIndex] - '0']--;
        ++leftIndex;
      }
      left[i] = leftIndex;
      sum[i + 1] = sum[i] + left[i];
    }

    for (int i = 0; i < n; ++i) {
      int l = queries[i][0], r = queries[i][1];
      if (left[r] <= l) {
        // [l, r]
        ans[i] = 1LL * (r - l + 1) * (r - l + 2) / 2;
      } else {
        // [l, j - 1] + [j, r]
        // i - left[i] + 1;
        int j = lower_bound(left.begin(), left.end(), l) - left.begin();
        ans[i] = (1LL * (j - l) * (j - l + 1) / 2) +
                 (1LL * (j + r) * (r - j + 1) / 2) - (sum[r + 1] - sum[j]) +
                 (r - j + 1);
      }
    }
    return ans;
  }
};
// @lc code=end
