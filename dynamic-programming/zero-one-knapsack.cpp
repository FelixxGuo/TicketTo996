/*
 *  Example
 *
 *  Backpack capacity: W = 4
 *  Items:
 *  1.  Weight = 1, Value = 15
 *  2.  Weight = 3, Value = 20
 *  3.  Weight = 4, Value = 30
 *
 *  Question: What is the maximum value you can carry without exceeding the
 *  capacity?
 *
 */
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int backPackZeroOne(const vector<int> &weight, const vector<int> &value,
                      int packageCapacity) {
    assert(weight.size() == value.size());
    int m = weight.size();
    if (m == 0) {
      return 0;
    }
    vector<vector<int>> dp(m, vector<int>(packageCapacity + 1, 0));

    for (int i = 0; i < m; ++i) {
      dp[i][0] = 0;
    }
    for (int j = 0; j <= packageCapacity; ++j) {
      if (j >= weight[0]) {
        dp[0][j] = value[0];
      } else {
        dp[0][j] = 0;
      }
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j <= packageCapacity; ++j) {
        if (j >= weight[i]) {
          dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    return dp[m - 1][packageCapacity];
  }
};

class Solution1 {
public:
  int backPackZeroOne(const vector<int> &weight, const vector<int> &value,
                      int packageCapacity) {
    assert(weight.size() == value.size());
    int m = weight.size();
    if (m == 0) {
      return 0;
    }

    vector<int> dp(packageCapacity + 1, 0);
    dp[0] = 0;

    // notice the idnex must be start from 0
    for (int i = 0; i < m; ++i) {
      for (int j = packageCapacity; j >= weight[i]; --j) {
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
      }
    }
    return dp[packageCapacity];
  }
};

int main() {
  vector<int> weight = {1, 3, 4};
  vector<int> value = {15, 20, 30};
  int capacity = 4;

  Solution sol;
  int maxValue = sol.backPackZeroOne(weight, value, capacity);
  cout << "Maximum value achievable with capacity " << capacity
       << " is: " << maxValue << endl;
  Solution1 sol1;
  maxValue = sol1.backPackZeroOne(weight, value, capacity);
  cout << "Maximum value achievable with capacity " << capacity
       << " is: " << maxValue << endl;

  return 0;
}