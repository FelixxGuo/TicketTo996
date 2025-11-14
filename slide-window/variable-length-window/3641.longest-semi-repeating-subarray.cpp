/*
 * You are given an integer array nums of length n and an integer k.
 *
 * A semi‑repeating subarray is a contiguous subarray in which at
 * most k elements repeat (i.e., appear more than once).
 *
 * Return the length of the longest semi‑repeating subarray in nums.
 *
 *
 *
 * Example 1:
 *
 * Input: nums = [1,2,3,1,2,3,4], k = 2
 *
 * Output: 6
 *
 * Explanation:
 *
 * The longest semi-repeating subarray is [2, 3, 1, 2, 3, 4], which has two
 * repeating elements (2 and 3).
 *
 * Example 2:
 *
 * Input: nums = [1,1,1,1,1], k = 4
 *
 * Output: 5
 *
 * Explanation:
 *
 * The longest semi-repeating subarray is [1, 1, 1, 1, 1], which has only one
 * repeating element (1).
 *
 * Example 3:
 *
 * Input: nums = [1,1,1,1,1], k = 0
 *
 * Output: 1
 *
 * Explanation:
 *
 * The longest semi-repeating subarray is [1], which has no repeating elements.
 *
 *
 *
 * Constraints:
 *
 * 1 <= nums.length <= 105
 * 1 <= nums[i] <= 105
 * 0 <= k <= nums.length
 */
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
  int longestSubarray(vector<int> &nums, int k) {
    int n = nums.size(), left = 0, right = 0, ans = 0;
    unordered_map<int, int> cnt;
    int repeatCount = 0;

    for (right = 0; right < n; ++right) {
      cnt[nums[right]]++;
      if (cnt[nums[right]] == 2) {
        ++repeatCount;
      }
      while (repeatCount > k) {
        if (cnt[nums[left]] == 2) {
          --repeatCount;
        }
        cnt[nums[left]]--;
        ++left;
      }
      ans = max(ans, right - left + 1);
    }
    return ans;
  }
};

// --- Helper function for testing ---
void test(Solution &sol, vector<int> nums, int k, int expected) {
  int result = sol.longestSubarray(nums, k);
  cout << "Input: nums = [";
  for (int i = 0; i < nums.size(); ++i)
    cout << nums[i] << (i == nums.size() - 1 ? "" : ",");
  cout << "], k = " << k << endl;
  cout << "Expected: " << expected << ", Actual: " << result;
  if (result == expected) {
    cout << " ✅ PASS" << endl;
  } else {
    cout << " ❌ FAIL" << endl;
  }
  cout << "-------------------------" << endl;
}

int main() {
  Solution sol;

  // Case 1: Basic test
  // '1' repeats, '2' repeats. Total 2 repeating elements. k=1, so we can only
  // tolerate 1. Longest valid subarray e.g., [1, 2, 1, 3] (Length 4), where
  // only '1' repeats.
  test(sol, {1, 2, 1, 3, 2}, 1, 4);

  // Case 2: k=0, no repeating numbers allowed
  // Longest subarray with unique elements is [1, 2, 3, 4], Length 4.
  test(sol, {1, 2, 3, 4, 1, 2}, 0, 4);

  // Case 3: All numbers are the same
  // k=0 -> Length 1 (Must be unique)
  // k=1 -> Length 5 (Only the number '1' repeats; this counts as 1 repeating
  // element type, so repeatCount stays 1, which is <= k)
  test(sol, {1, 1, 1, 1, 1}, 0, 1);
  test(sol, {1, 1, 1, 1, 1}, 1, 5);

  // Case 4: Multiple different repeating pairs
  // [1, 2, 3, 1, 2, 3], k=2
  // The first 5 elements [1, 2, 3, 1, 2] -> '1' repeats, '2' repeats ->
  // repeatCount=2 <= k. Length 5.
  test(sol, {1, 2, 3, 1, 2, 3}, 2, 5);

  // Case 5: Empty array (Testing robustness)
  test(sol, {}, 1, 0);

  return 0;
}