/*
 * @lc app=leetcode id=3413 lang=cpp
 *
 * [3413] Maximum Coins From K Consecutive Bags
 *
 * https://leetcode.com/problems/maximum-coins-from-k-consecutive-bags/description/
 *
 * algorithms
 * Medium (23.78%)
 * Likes:    186
 * Dislikes: 26
 * Total Accepted:    8.1K
 * Total Submissions: 33.7K
 * Testcase Example:  '[[8,10,1],[1,3,2],[5,6,4]]\n4'
 *
 * There are an infinite amount of bags on a number line, one bag for each
 * coordinate. Some of these bags contain coins.
 *
 * You are given a 2D array coins, where coins[i] = [li, ri, ci] denotes that
 * every bag from li to ri contains ci coins.
 *
 * The segments that coins contain are non-overlapping.
 *
 * You are also given an integer k.
 *
 * Return the maximum amount of coins you can obtain by collecting k
 * consecutive bags.
 *
 *
 * Example 1:
 *
 *
 * Input: coins = [[8,10,1],[1,3,2],[5,6,4]], k = 4
 *
 * Output: 10
 *
 * Explanation:
 *
 * Selecting bags at positions [3, 4, 5, 6] gives the maximum number of coins:
 * 2 + 0 + 4 + 4 = 10.
 *
 *
 * Example 2:
 *
 *
 * Input: coins = [[1,10,3]], k = 2
 *
 * Output: 6
 *
 * Explanation:
 *
 * Selecting bags at positions [1, 2] gives the maximum number of coins: 3 + 3
 * = 6.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= coins.length <= 10^5
 * 1 <= k <= 10^9
 * coins[i] == [li, ri, ci]
 * 1 <= li <= ri <= 10^9
 * 1 <= ci <= 1000
 * The given segments are non-overlapping.
 *
 *
 */

// @lc code=start
class Solution {
public:
  long long maximumCoins(vector<vector<int>> &coins, int k) {
    sort(
        coins.begin(), coins.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
    long long rightAns = maxConis(coins, k);

    reverse(coins.begin(), coins.end());
    for (auto &coin : coins) {
      coin[0] *= -1;
      coin[1] *= -1;
      swap(coin[0], coin[1]);
    }
    long long leftAns = maxConis(coins, k);

    return max(leftAns, rightAns);
  }

private:
  long long maxConis(const vector<vector<int>> &coins, int k) {
    int n = coins.size(), left = 0, right = 0;
    long long cover = 0, uncover = 0, ans = 0;

    for (right = 0; right < n; ++right) {
      cover += 1LL * (coins[right][1] - coins[right][0] + 1) * coins[right][2];
      int kLeft = coins[right][1] - k + 1;
      while (coins[left][1] < kLeft) {
        cover -= 1LL * (coins[left][1] - coins[left][0] + 1) * coins[left][2];
        ++left;
      }
      uncover =
          max(1LL * (kLeft - coins[left][0]) * coins[left][2], (long long)0);
      ans = max(ans, cover - uncover);
    }
    return ans;
  }
};
// @lc code=end
