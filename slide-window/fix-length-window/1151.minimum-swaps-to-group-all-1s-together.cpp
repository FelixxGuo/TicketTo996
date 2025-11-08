/*
 * 1151. Minimum Swaps to Group All 1's Together
 * Given a binary array data, return the minimum number of swaps required to
 * group all 1’s present in the array together in any place in the array.
 *
 *
 *
 * Example 1:
 *
 * Input: [1,0,1,0,1]
 * Output: 1
 * Explanation:
 * There are 3 ways to group all 1's together:
 * [1,1,1,0,0] using 1 swap.
 * [0,1,1,1,0] using 2 swaps.
 * [0,0,1,1,1] using 1 swap.
 * The minimum is 1.
 * Example 2:
 *
 * Input: [0,0,0,1,0]
 * Output: 0
 * Explanation:
 * Since there is only one 1 in the array, no swaps needed.
 * Example 3:
 *
 * Input: [1,0,1,0,1,0,0,1,1,0,1]
 * Output: 3
 * Explanation:
 * One possible solution that uses 3 swaps is [0,0,0,0,0,1,1,1,1,1,1].
 *
 *
 * Note:
 *
 * 1 <= data.length <= 10^5
 * 0 <= data[i] <= 1
 * Difficulty:
 * Medium
 * Lock:
 * Prime
 * Company:
 * Expedia
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int minSwaps(vector<int> &data) {
    int numOnes = 0;
    for (int i = 0; i < data.size(); ++i) {
      if (data[i] == 1) {
        ++numOnes;
      }
    }
    if (numOnes == 0) {
      return 0;
    } else if (numOnes == data.size()) {
      return 0;
    }

    int left = 0, right = 0;
    int num = 0, ans = 0;
    for (right = 0; right < data.size(); ++right) {
      if (data[right]) {
        ++num;
      }
      left = right - numOnes + 1;
      if (left < 0) {
        continue;
      }
      ans = max(num, ans);
      if (data[left]) {
        --num;
      }
    }
    return numOnes - ans;
  }
};

int main() {
  Solution sol;

  vector<pair<vector<int>, int>> tests = {
      {{1, 0, 1, 0, 1}, 1},            // 示例，期望 1
      {{}, 0},                         // 空数组，期望 0
      {{0, 0, 0}, 0},                  // 全 0，期望 0
      {{1, 1, 1}, 0},                  // 全 1，期望 0
      {{1}, 0},                        // 单元素 1，期望 0
      {{0}, 0},                        // 单元素 0，期望 0
      {{1, 0, 1, 1, 0, 1}, 1},         // ones=4, windows max 3 -> 1
      {{0, 1, 0, 1, 0}, 1},            // ones=2, windows max 1 -> 1
      {{1, 0, 0, 1, 0, 1, 1, 0, 1}, 2} // 随机组合，手动确认期望 2（供参考）
  };

  for (auto &t : tests) {
    vector<int> data = t.first;
    int expected = t.second;
    int ans = sol.minSwaps(data);
    cout << "Input: [";
    for (size_t i = 0; i < data.size(); ++i) {
      cout << data[i] << (i + 1 < data.size() ? "," : "");
    }
    cout << "] => Output: " << ans << "  Expected: " << expected;
    if (ans == expected)
      cout << "  [OK]";
    else
      cout << "  [WRONG]";
    cout << endl;
  }

  return 0;
}