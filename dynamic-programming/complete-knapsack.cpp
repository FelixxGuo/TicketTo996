/*
 * Complete Knapsack
 * Each item can be chosen unlimited times.
 * You can take as many copies of each item as you want.
 */
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int completeKnapSack(const vector<int> &weight, const vector<int> &value,
                       int sackCap) {
    assert(weight.size() == value.size());
    int n = weight.size();

    vector<int> dp(sackCap + 1, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = weight[i]; j <= sackCap; ++j) {
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
      }
    }
    return dp[sackCap];
  }
};

class Solution1 {
public:
  int completeKnapSack(const vector<int> &weight, const vector<int> &value,
                       int sackCap) {
    assert(weight.size() == value.size());
    int n = weight.size();

    vector<vector<int>> dp(n, vector<int>(sackCap + 1, 0));
    for (int j = 0; j <= sackCap; ++j) {
      if (j < weight[0]) {
        dp[0][j] = 0;
      } else {
        dp[0][j] += dp[0][j - weight[0]] + value[0];
      }
    }

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j <= sackCap; ++j) {
        if (j >= weight[i]) {
          // notice, here difference between the zero-one knapsack
          dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i]] + value[i]);
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    return dp[n - 1][sackCap];
  }
};

int main() {
  Solution sol;
  Solution sol1;

  // Best combination: take 5 items of weight 2 (total 10 weight, total value
  // 20) Expected answer = 20

  vector<int> weight = {2, 3, 4};
  vector<int> value = {4, 5, 6};
  int sackCap = 10;

  cout << "Maximum value: " << sol.completeKnapSack(weight, value, sackCap)
       << endl;
  cout << "Maximum value: " << sol1.completeKnapSack(weight, value, sackCap)
       << endl;

  return 0;
}