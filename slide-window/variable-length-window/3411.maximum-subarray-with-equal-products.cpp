/*
 * @lc app=leetcode id=3411 lang=cpp
 *
 * [3411] Maximum Subarray With Equal Products
 *
 * https://leetcode.com/problems/maximum-subarray-with-equal-products/description/
 *
 * algorithms
 * Easy (45.59%)
 * Likes:    94
 * Dislikes: 40
 * Total Accepted:    26.9K
 * Total Submissions: 58.4K
 * Testcase Example:  '[1,2,1,2,1,1,1]'
 *
 * You are given an array of positive integers nums.
 *
 * An array arr is called product equivalent if prod(arr) == lcm(arr) *
 * gcd(arr), where:
 *
 *
 * prod(arr) is the product of all elements of arr.
 * gcd(arr) is the GCD of all elements of arr.
 * lcm(arr) is the LCM of all elements of arr.
 *
 *
 * Return the length of the longest product equivalent subarray of nums.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,1,2,1,1,1]
 *
 * Output: 5
 *
 * Explanation: 
 *
 * The longest product equivalent subarray is [1, 2, 1, 1, 1], where prod([1,
 * 2, 1, 1, 1]) = 2, gcd([1, 2, 1, 1, 1]) = 1, and lcm([1, 2, 1, 1, 1]) = 2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,3,4,5,6]
 *
 * Output: 3
 *
 * Explanation: 
 *
 * The longest product equivalent subarray is [3, 4, 5].
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,2,3,1,4,5,1]
 *
 * Output: 5
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 100
 * 1 <= nums[i] <= 10
 *
 *
 */

// @lc code=start
class Solution1 {
public:
  int maxLength(vector<int> &nums) {
    int n = nums.size(), left = 0, right = 0;
    int mul = 1, ans = 2;
    for (right = 0; right < n; ++right) {
      while (gcd(mul, nums[right]) > 1) {
        mul /= nums[left];
        ++left;
      }
      mul *= nums[right];
      ans = max(ans, right - left + 1);
    }
    return ans;
  }
};

class Solution {
public:
  int maxLength(vector<int> &nums) {
    int n = nums.size();
    int allLCM = 1, ans = 0;
    for (int i = 0; i < n; ++i) {
      allLCM = lcm(nums[i], allLCM);
    }
    for (int i = 0; i < n; ++i) {
      int p = 1, l = 1, g = 0;
      for (int j = i; j < n && p <= allLCM * 10; ++j) {
        p *= nums[j];
        l = lcm(l, nums[j]);
        g = gcd(g, nums[j]);
        if (p == l * g) {
          ans = max(ans, j - i + 1);
        }
      }
    }
    return ans;
  }
};
// @lc code=end
