/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 *
 * https://leetcode.com/problems/last-stone-weight-ii/description/
 *
 * algorithms
 * Medium (58.35%)
 * Likes:    3316
 * Dislikes: 137
 * Total Accepted:    120.8K
 * Total Submissions: 206.7K
 * Testcase Example:  '[2,7,4,1,8,1]'
 *
 * You are given an array of integers stones where stones[i] is the weight of
 * the i^th stone.
 *
 * We are playing a game with the stones. On each turn, we choose any two
 * stones and smash them together. Suppose the stones have weights x and y with
 * x <= y. The result of this smash is:
 *
 *
 * If x == y, both stones are destroyed, and
 * If x != y, the stone of weight x is destroyed, and the stone of weight y has
 * new weight y - x.
 *
 *
 * At the end of the game, there is at most one stone left.
 *
 * Return the smallest possible weight of the left stone. If there are no
 * stones left, return 0.
 *
 *
 * Example 1:
 *
 *
 * Input: stones = [2,7,4,1,8,1]
 * Output: 1
 * Explanation:
 * We can combine 2 and 4 to get 2, so the array converts to [2,7,1,8,1] then,
 * we can combine 7 and 8 to get 1, so the array converts to [2,1,1,1] then,
 * we can combine 2 and 1 to get 1, so the array converts to [1,1,1] then,
 * we can combine 1 and 1 to get 0, so the array converts to [1], then that's
 * the optimal value.
 *
 *
 * Example 2:
 *
 *
 * Input: stones = [31,26,33,21,40]
 * Output: 5
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= stones.length <= 30
 * 1 <= stones[i] <= 100
 *
 *
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
  int lastStoneWeightII(vector<int> &stones) {
    int n = stones.size();
    int s = 0;
    for (int i = 0; i < n; ++i) {
      s += stones[i];
    }

    int target = s / 2;
    vector<int> dp(target + 1, 0);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = target; j >= stones[i]; --j) {
            dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
        }
    }
    return abs(s - dp[target] - dp[target]);
  }
};
// @lc code=end
