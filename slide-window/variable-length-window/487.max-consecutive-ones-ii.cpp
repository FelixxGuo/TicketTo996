/*
 * Description
 * Given a binary array nums, return the maximum number of consecutive 1's in
 * the array if you can flip at most one 0.
 *
 *
 *
 * Example 1:
 *
 * Input: nums = [1,0,1,1,0]
 * Output: 4
 * Explanation:
 * - If we flip the first zero, nums becomes [1,1,1,1,0] and we have 4
 * consecutive ones.
 * - If we flip the second zero, nums becomes [1,0,1,1,1] and we have 3
 * consecutive ones. The max number of consecutive ones is 4. Example 2:
 *
 * Input: nums = [1,0,1,1,0,1]
 * Output: 4
 * Explanation:
 * - If we flip the first zero, nums becomes [1,1,1,1,0,1] and we have 4
 * consecutive ones.
 * - If we flip the second zero, nums becomes [1,0,1,1,1,1] and we have 4
 * consecutive ones. The max number of consecutive ones is 4.
 *
 *
 * Constraints:
 *
 * 1 <= nums.length <= 105
 * nums[i] is either 0 or 1.
 */
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    int n = nums.size(), ans = 0, numZeros = 0;
    int left = 0, right = 0;
    for (right = 0; right < n; ++right) {
      if (nums[right] == 0) {
        ++numZeros;
      }
      while (numZeros > 1) {
        if (nums[left] == 0) {
          --numZeros;
        }
        ++left;
      }
      ans = max(ans, right - left + 1);
    }
    return ans;
  }
};

int main() {
  Solution sol;
  {
    vector<int> nums = {1, 0, 1, 1, 0};
    cout << "case1: " << sol.findMaxConsecutiveOnes(nums)
         << " (expected 4)\n";
  }
  {
    vector<int> nums = {1, 0, 1, 1, 0, 1};
    cout << "case2: " << sol.findMaxConsecutiveOnes(nums)
         << " (expected 4)\n";
  }
  {
    vector<int> nums = {1, 1, 1, 1};
    cout << "case3: " << sol.findMaxConsecutiveOnes(nums)
         << " (expected 4)\n";
  }
  {
    vector<int> nums = {0, 0, 0};
    cout << "case4: " << sol.findMaxConsecutiveOnes(nums)
         << " (expected 1)\n";
  }
  {
    vector<int> nums = {1, 0, 1, 0, 1, 1, 1, 0, 1, 1};
    cout << "case5: " << sol.findMaxConsecutiveOnes(nums)
         << " (check manually)\n";
  }
  return 0;
}
