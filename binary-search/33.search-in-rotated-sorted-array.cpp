/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (43.39%)
 * Likes:    29057
 * Dislikes: 1762
 * Total Accepted:    4M
 * Total Submissions: 9.2M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * There is an integer array nums sorted in ascending order (with distinct
 * values).
 *
 * Prior to being passed to your function, nums is possibly left rotated at an
 * unknown index k (1 <= k < nums.length) such that the resulting array is
 * [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
 * (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices
 * and become [4,5,6,7,0,1,2].
 *
 * Given the array nums after the possible rotation and an integer target,
 * return the index of target if it is in nums, or -1 if it is not in nums.
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 *
 * Example 1:
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * Example 2:
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * Example 3:
 * Input: nums = [1], target = 0
 * Output: -1
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 5000
 * -10^4 <= nums[i] <= 10^4
 * All values of nums are unique.
 * nums is an ascending array that is possibly rotated.
 * -10^4 <= target <= 10^4
 *
 *
 */

// @lc code=start
class Solution1 {
public:
  int search(vector<int> &nums, int target) {
    int minIndex = findMin(nums);
    if (target > nums.back()) {
      return lowerBound(nums, -1, minIndex, target);
    }
    return lowerBound(nums, minIndex - 1, nums.size(), target);
  }

private:
  int findMin(vector<int> &nums) {
    // binary interval set as [0, n - 2], code use the open interval
    int left = -1;
    int right = nums.size() - 1;
    while (left + 1 < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] > nums.back()) {
        left = mid;
      } else {
        right = mid;
      }
    }
    return right;
  }
  int lowerBound(vector<int> &nums, int start, int end, int target) {
    // use the open interval
    int left = start;
    int right = end;
    while (left + 1 < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] >= target) {
        right = mid;
      } else {
        left = mid;
      }
    }
    return nums[right] == target ? right : -1;
  }
};

class Solution2 {
public:
  int search(vector<int> &nums, int target) {
    int left = -1;
    int right = nums.size() - 1;
    while (left + 1 < right) {
      int mid = left + (right - left) / 2;
      // mid is in the first part, target is in the second part
      if (nums[mid] > nums.back() && target <= nums.back()) {
        left = mid;
        // mid is in the second part, target is in the first part
      } else if (nums[mid] <= nums.back() && target > nums.back()) {
        right = mid;
        // in the same part
      } else if (nums[mid] >= target) {
        right = mid;
        // in the same part
      } else {
        left = mid;
      }
    }
    return nums[right] == target ? right : -1;
  }
};

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int last = nums.back();
    auto check = [&](int i) -> bool {
      if (nums[i] > last) {
        return target > last && nums[i] >= target;
      }
      return target > last || target <= nums[i];
    };
    int left = -1;
    int right = nums.size() - 1;
    while (left + 1 < right) {
      int mid = left + (right - left) / 2;
      if (check(mid)) {
        right = mid;
      } else {
        left = mid;
      }
    }
    return nums[right] == target ? right : -1;
  }
};
// @lc code=end
