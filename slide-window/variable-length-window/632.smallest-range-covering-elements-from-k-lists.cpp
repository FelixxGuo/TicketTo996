/*
 * @lc app=leetcode id=632 lang=cpp
 *
 * [632] Smallest Range Covering Elements from K Lists
 *
 * https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/
 *
 * algorithms
 * Hard (69.85%)
 * Likes:    4322
 * Dislikes: 100
 * Total Accepted:    232K
 * Total Submissions: 331.8K
 * Testcase Example:  '[[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]'
 *
 * You have k lists of sorted integers in non-decreasing order. Find the
 * smallest range that includes at least one number from each of the k lists.
 *
 * We define the range [a, b] is smaller than range [c, d] if b - a < d - c or
 * a < c if b - a == d - c.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
 * Output: [20,24]
 * Explanation:
 * List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
 * List 2: [0, 9, 12, 20], 20 is in range [20,24].
 * List 3: [5, 18, 22, 30], 22 is in range [20,24].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
 * Output: [1,1]
 *
 *
 *
 * Constraints:
 *
 *
 * nums.length == k
 * 1 <= k <= 3500
 * 1 <= nums[i].length <= 50
 * -10^5 <= nums[i][j] <= 10^5
 * nums[i] is sorted in non-decreasing order.
 *
 *
 */

// @lc code=start
class Solution1 {
public:
  vector<int> smallestRange(vector<vector<int>> &nums) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<tuple<int, int, int>>>
        pq;
    int n = nums.size();
    int ansR = INT_MIN, ansL = INT_MIN;
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
      pq.push({nums[i][0], i, 0});
      ansR = max(nums[i][0], ansR);
    }
    ansL = get<0>(pq.top());
    r = ansR;
    for (;;) {
      auto [_, i, j] = pq.top();
      if (j + 1 == nums[i].size()) {
        break;
      }
      pq.pop();
      pq.push({nums[i][j + 1], i, j + 1});
      r = max(r, nums[i][j + 1]);
      l = get<0>(pq.top());
      if (ansR - ansL > r - l) {
        ansL = l;
        ansR = r;
      }
    }
    return {ansL, ansR};
  }
};

class Solution {
public:
  vector<int> smallestRange(vector<vector<int>> &nums) {
    int n = nums.size();
    vector<pair<int, int>> pairNums;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < nums[i].size(); ++j) {
        pairNums.push_back({nums[i][j], i});
      }
    }
    sort(pairNums.begin(), pairNums.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
           return a.first < b.first;
         });
    int left = 0, right = 0, ansLen = INT_MAX;
    int valid = 0, ansL = 0, ansR = 0;
    vector<int> cnt(n, 0);
    for (right = 0; right < pairNums.size(); ++right) {
      if (cnt[pairNums[right].second] == 0) {
        ++valid;
      }
      cnt[pairNums[right].second]++;
      while (valid == n) {
        if (ansLen > pairNums[right].first - pairNums[left].first) {
          ansLen = pairNums[right].first - pairNums[left].first;
          ansL = pairNums[left].first;
          ansR = pairNums[right].first;
        }
        if (cnt[pairNums[left].second] == 1) {
          --valid;
        }
        cnt[pairNums[left].second]--;
        ++left;
      }
    }
    return {ansL, ansR};
  }
};
// @lc code=end
