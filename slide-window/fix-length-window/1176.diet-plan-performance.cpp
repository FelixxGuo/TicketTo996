/*
 * A dieter tracks their daily calorie consumption over multiple days. You're
 * given an array calories where calories[i] represents the number of calories
 * consumed on day i.
 *
 * The dieter evaluates their performance by looking at every consecutive k-day
 * window in their diet. For each window of k consecutive days, they calculate
 * the total calories T consumed during that period.
 *
 * Based on the total T, they assign points as follows:
 *
 * If T < lower: Poor performance, lose 1 point
 * If T > upper: Good performance, gain 1 point
 * If lower ≤ T ≤ upper: Normal performance, no change in points
 * The dieter starts with 0 points. Your task is to calculate the final total
 * points after evaluating all possible k-day windows.
 *
 * For example, if calories = [1,2,3,4,5] and k = 1, you would evaluate:
 * lower = 3 and upper = 3 return 0
 *
 * Each of these totals would be compared against lower and upper to determine
 * points gained or lost.
 *
 * The solution uses a prefix sum array to efficiently calculate the sum of any
 * k-day window. The prefix sum s[i] stores the total calories from day 0 to day
 * i-1. This allows us to calculate any window sum as s[i+k] - s[i], which gives
 * the total calories from day i to day i+k-1.
 */
class Solution {
public:
  int dietPlanPerformance(vector<int> &calories, int k, int lower, int upper) {
    int left = 0, right = 0;
    int n = calories.size();
    int sum = 0;
    int ans = 0;
    for (right = 0; right < n; ++right) {
      sum += calories[right];
      left = right - k + 1;
      if (left < 0) {
        continue;
      }
      if (sum < lower) {
        --ans;
      } else if (sum > upper) {
        ++ans;
      }
      sum -= calories[left];
    }
    return ans;
  }
};