/*
 * Description
 * Given a string s, return the length of the longest substring that contains at
 * most two distinct characters.
 *
 *
 *
 * Example 1:
 *
 * Input: s = "eceba"
 * Output: 3
 * Explanation: The substring is "ece" which its length is 3.
 * Example 2:
 *
 * Input: s = "ccaabbb"
 * Output: 5
 * Explanation: The substring is "aabbb" which its length is 5.
 *
 *
 * Constraints:
 *
 * 1 <= s.length <= 105
 * s consists of English letters.
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int n = s.size(), left = 0, right = 0, ans = 0;
    vector<int> cnt(128, 0);
    int unique = 0;

    for (right = 0; right < n; ++right) {
      if (cnt[s[right]] == 0) {
        ++unique;
      }
      cnt[s[right]]++;
      while (unique > 2) {
        if (cnt[s[left]] == 1) {
          --unique;
        }
        cnt[s[left]]--;
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
    string s = "eceba";
    cout << "case1: " << sol.lengthOfLongestSubstringTwoDistinct(s)
         << " (expected 3)\n"; // "ece"
  }
  {
    string s = "ccaabbb";
    cout << "case2: " << sol.lengthOfLongestSubstringTwoDistinct(s)
         << " (expected 5)\n"; // "aabbb"
  }
  {
    string s = "a";
    cout << "case3: " << sol.lengthOfLongestSubstringTwoDistinct(s)
         << " (expected 1)\n";
  }
  {
    string s = "abc";
    cout << "case4: " << sol.lengthOfLongestSubstringTwoDistinct(s)
         << " (expected 2)\n";
  }
  {
    string s = "ababffzzeee";
    cout << "case5: " << sol.lengthOfLongestSubstringTwoDistinct(s)
         << " (expected 5 -> \"zzeee\")\n";
  }
  return 0;
}
