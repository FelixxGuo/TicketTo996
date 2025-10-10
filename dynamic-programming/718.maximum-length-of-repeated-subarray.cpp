/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 *
 * https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
 *
 * algorithms
 * Medium (51.12%)
 * Likes:    7011
 * Dislikes: 178
 * Total Accepted:    348.4K
 * Total Submissions: 681.2K
 * Testcase Example:  '[1,2,3,2,1]\n[3,2,1,4,7]'
 *
 * Given two integer arrays nums1 and nums2, return the maximum length of a
 * subarray that appears in both arrays.
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
 * Output: 3
 * Explanation: The repeated subarray with maximum length is [3,2,1].
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
 * Output: 5
 * Explanation: The repeated subarray with maximum length is [0,0,0,0,0].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 100
 *
 *
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution1 {
public:
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    // dp[i][j] = dp[i - 1][j - 1] + 1 if nums1[i] == num2[j]
    int n1 = nums1.size();
    int n2 = nums2.size();
    int res = 0;
    vector<vector<int>> dp(n1, vector<int>(n2, 0));
    for (int i = 0; i < n2; ++i) {
      if (nums1[0] == nums2[i]) {
        dp[0][i] = 1;
      }
      if (res < dp[0][i]) {
        res = dp[0][i];
      }
    }
    for (int i = 0; i < n1; ++i) {
      if (nums2[0] == nums1[i]) {
        dp[i][0] = 1;
      }
      if (res < dp[i][0]) {
        res = 1;
      }
    }

    for (int i = 1; i < n1; ++i) {
      for (int j = 1; j < n2; ++j) {
        if (nums1[i] == nums2[j]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        }
        if (res < dp[i][j]) {
          res = dp[i][j];
        }
      }
    }
    return res;
  }
};

class Solution {
public:
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    vector<int> dp(n2, 0);
    int res = 0;

    for (int i = 0; i < n1; ++i) {
      for (int j = n2 - 1; j >= 0; --j) {
        if (nums1[i] == nums2[j]) {
          if (j > 0) {
            dp[j] = dp[j - 1] + 1;
          } else {
            dp[j] = 1;
          }
        } else {
          dp[j] = 0;
        }
        res = max(res, dp[j]);
      }
    }
    return res;
  }
};

// @lc code=end
