/*
 * 2107. Number of Unique Flavors After Sharing K Candies
 * Description
 * You are given a 0-indexed integer array candies, where candies[i] represents
 * the flavor of the ith candy. Your mom wants you to share these candies with
 * your little sister by giving her k consecutive candies, but you want to keep
 * as many flavors of candies as possible.
 *
 * Return the maximum number of unique flavors of candy you can keep after
 * sharing with your sister.
 *
 *
 *
 * Example 1:
 *
 * Input: candies = [1,2,2,3,4,3], k = 3
 * Output: 3
 * Explanation:
 * Give the candies in the range [1, 3] (inclusive) with flavors [2,2,3].
 * You can eat candies with flavors [1,4,3].
 * There are 3 unique flavors, so return 3.
 * Example 2:
 *
 * Input: candies = [2,2,2,2,3,3], k = 2
 * Output: 2
 * Explanation:
 * Give the candies in the range [3, 4] (inclusive) with flavors [2,3].
 * You can eat candies with flavors [2,2,2,3].
 * There are 2 unique flavors, so return 2.
 * Note that you can also share the candies with flavors [2,2] and eat the
 * candies with flavors [2,2,3,3]. Example 3:
 *
 * Input: candies = [2,4,5], k = 0
 * Output: 3
 * Explanation:
 * You do not have to give any candies.
 * You can eat the candies with flavors [2,4,5].
 * There are 3 unique flavors, so return 3.
 *
 *
 * Constraints:
 *
 * 1 <= candies.length <= 105
 * 1 <= candies[i] <= 105
 * 0 <= k <= candies.length
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int shareCandies(vector<int> &candies, int k) {
    unordered_map<int, int> uMap;
    for (int candy : candies) {
      uMap[candy]++;
    }
    if (k == 0) {
      return uMap.size();
    }
    int n = candies.size();
    if (k == n) {
      return 0;
    }
    int left = 0, right = 0;
    int ans = 0;

    for (right = 0; right < n; ++right) {
      uMap[candies[right]]--;
      if (uMap[candies[right]] == 0) {
        uMap.erase(candies[right]);
      }
      left = right - k + 1;
      if (left < 0) {
        continue;
      }
      ans = max(ans, int(uMap.size()));
      ++uMap[candies[left]];
    }
    return ans;
  }
};

int main() {
    Solution sol;

    vector<pair<vector<int>, int>> testCases = {
        {{1, 2, 3, 2, 1, 4}, 2},  // 输出 4
        {{1, 2, 3, 4}, 4},        // 输出 0
        {{1, 2, 2, 3}, 0},        // 输出 3
        {{1, 1, 1, 2, 2, 3}, 3},  // 输出 3
        {{5, 5, 5, 5}, 2}         // 输出 1
    };

    for (int i = 0; i < testCases.size(); ++i) {
        int result = sol.shareCandies(testCases[i].first, testCases[i].second);
        cout << "Test case " << i + 1 << ": " << result << endl;
    }

    return 0;
}