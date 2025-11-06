/*
 * @lc app=leetcode id=2134 lang=cpp
 *
 * [2134] Minimum Swaps to Group All 1's Together II
 *
 * https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/
 *
 * algorithms
 * Medium (65.58%)
 * Likes:    2065
 * Dislikes: 41
 * Total Accepted:    172.1K
 * Total Submissions: 262.4K
 * Testcase Example:  '[0,1,0,1,1,0,0]'
 *
 * A swap is defined as taking two distinct positions in an array and swapping
 * the values in them.
 *
 * A circular array is defined as an array where we consider the first element
 * and the last element to be adjacent.
 *
 * Given a binary circular array nums, return the minimum number of swaps
 * required to group all 1's present in the array together at any location.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [0,1,0,1,1,0,0]
 * Output: 1
 * Explanation: Here are a few of the ways to group all the 1's together:
 * [0,0,1,1,1,0,0] using 1 swap.
 * [0,1,1,1,0,0,0] using 1 swap.
 * [1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
 * There is no way to group all 1's together with 0 swaps.
 * Thus, the minimum number of swaps required is 1.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,1,1,1,0,0,1,1,0]
 * Output: 2
 * Explanation: Here are a few of the ways to group all the 1's together:
 * [1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the
 * array).
 * [1,1,1,1,1,0,0,0,0] using 2 swaps.
 * There is no way to group all 1's together with 0 or 1 swaps.
 * Thus, the minimum number of swaps required is 2.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,1,0,0,1]
 * Output: 0
 * Explanation: All the 1's are already grouped together due to the circular
 * property of the array.
 * Thus, the minimum number of swaps required is 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * nums[i] is either 0 or 1.
 *
 *
 */

// @lc code=start
class Solution1 {
public:
  int minSwaps(vector<int> &nums) {
    int n = nums.size();
    int numOnes = 0;
    for (int &num : nums) {
      if (num == 1) {
        numOnes += 1;
      }
    }
    if (numOnes == 0 || numOnes == n) {
      return 0;
    }

    int cnt = 0;
    for (int i = 0; i < numOnes; ++i) {
      if (nums[i] == 1) {
        ++cnt;
      }
    }
    int ans = cnt;

    for (int i = numOnes; i < n + numOnes; ++i) {
      if (nums[i % n] == 1) {
        ++cnt;
      }
      if (nums[i - numOnes] == 1) {
        --cnt;
      }
      ans = max(ans, cnt);
    }
    return numOnes - ans;
  }
};

class Solution {
public:
  int minSwaps(vector<int> &nums) {
    int n = nums.size();
    int win = accumulate(nums.begin(), nums.end(), 0);
    if (win == 0 || win == n) {
      return 0;
    }

    int cnt = 0, right = 0, left = 0, ans = n + 1;
    for (right = 0; right < n + win - 1; ++right) {
      if (nums[right % n] == 0) {
        cnt++;
      }
      left = right - win + 1;
      if (left < 0) {
        continue;
      }
      ans = min(ans, cnt);
      if (nums[left] == 0) {
        --cnt;
      }
    }
    return ans;
  }
};
// @lc code=end
