/*
 * Each item can be taken a limited number of times
 */
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int multiKnapSack(const vector<int> &weight, const vector<int> &value,
                    const vector<int> &nums, int sackCap) {

    assert(weight.size() == value.size());
    assert(value.size() == nums.size());

    vector<int> newWeight;
    vector<int> newValue;
    for (int i = 0; i < nums.size(); ++i) {
      int k = nums[i];
      while (k--) {
        newWeight.push_back(weight[i]);
        newValue.push_back(value[i]);
      }
    }

    vector<int> dp(sackCap + 1, 0);
    for (int i = 0; i < newWeight.size(); ++i) {
      for (int j = sackCap; j >= newWeight[i]; --j) {
        dp[j] = max(dp[j], dp[j - newWeight[i]] + newValue[i]);
      }
    }
    return dp[sackCap];
  }
};

class Solution1 {
public:
  int multiKnapSack(const vector<int> &weight, const vector<int> &value,
                    const vector<int> &nums, int sackCap) {
    assert(weight.size() == value.size());
    assert(value.size() == nums.size());
    vector<int> dp(sackCap + 1, 0);

    for (int i = 0; i < weight.size(); ++i) {
      for (int j = sackCap; j >= weight[i]; --j) {
        for (int k = 1; k <= nums[i]; ++k) {
          if (j >= k * weight[i]) {
            dp[i] = max(dp[i], dp[i - k * weight[i]] + k * value[i]);
          }
        }
      }
    }
    return dp[sackCap];
  }
};

int main() {
  Solution s;
  Solution1 s1;
  vector<int> weight = {1, 3, 4};
  vector<int> value = {15, 20, 30};
  vector<int> nums = {2, 3, 2}; // counts of each item
  int sackCap = 10;

  int ans = s.multiKnapSack(weight, value, nums, sackCap);
  cout << "Maximum value = " << ans << endl;
  ans = s1.multiKnapSack(weight, value, nums, sackCap);
  cout << "Maximum value = " << ans << endl;

  return 0;
}