/*
 * @lc app=leetcode id=2271 lang=cpp
 *
 * [2271] Maximum White Tiles Covered by a Carpet
 *
 * https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/description/
 *
 * algorithms
 * Medium (35.21%)
 * Likes:    826
 * Dislikes: 57
 * Total Accepted:    20.9K
 * Total Submissions: 59K
 * Testcase Example:  '[[1,5],[10,11],[12,18],[20,25],[30,32]]\n10'
 *
 * You are given a 2D integer array tiles where tiles[i] = [li, ri] represents
 * that every tile j in the range li <= j <= ri is colored white.
 *
 * You are also given an integer carpetLen, the length of a single carpet that
 * can be placed anywhere.
 *
 * Return the maximum number of white tiles that can be covered by the
 * carpet.
 *
 *
 * Example 1:
 *
 *
 * Input: tiles = [[1,5],[10,11],[12,18],[20,25],[30,32]], carpetLen = 10
 * Output: 9
 * Explanation: Place the carpet starting on tile 10.
 * It covers 9 white tiles, so we return 9.
 * Note that there may be other places where the carpet covers 9 white tiles.
 * It can be shown that the carpet cannot cover more than 9 white tiles.
 *
 *
 * Example 2:
 *
 *
 * Input: tiles = [[10,11],[1,1]], carpetLen = 2
 * Output: 2
 * Explanation: Place the carpet starting on tile 10.
 * It covers 2 white tiles, so we return 2.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= tiles.length <= 5 * 10^4
 * tiles[i].length == 2
 * 1 <= li <= ri <= 10^9
 * 1 <= carpetLen <= 10^9
 * The tiles are non-overlapping.
 *
 *
 */

// @lc code=start
class Solution {
public:
  struct cmp {
    bool operator()(const vector<int> &a, const vector<int> &b) const {
      return a[0] < b[0];
    }
  };
  int maximumWhiteTiles(vector<vector<int>> &tiles, int carpetLen) {
    sort(tiles.begin(), tiles.end(), cmp());
    int cover = 0, left = 0, ans = 0;
    int carpetLeft = 0;
    for (auto &tile : tiles) {
      cover += tile[1] - tile[0] + 1;
      carpetLeft = tile[1] - carpetLen + 1;
      while (tiles[left][1] < carpetLeft) {
        cover -= tiles[left][1] - tiles[left][0] + 1;
        ++left;
      }
      int uncover = max(carpetLeft - tiles[left][0], 0);
      ans = max(ans, cover - uncover);
    }
    return ans;
  }
};
// @lc code=end
