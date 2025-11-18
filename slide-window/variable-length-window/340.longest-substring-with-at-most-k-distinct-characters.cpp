/*
 * Description
 * Given a string s and an integer k, return the length of the longest substring
 * of s that contains at most k distinct characters.
 *
 *
 *
 * Example 1:
 *
 * Input: s = "eceba", k = 2
 * Output: 3
 * Explanation: The substring is "ece" with length 3.
 * Example 2:
 *
 * Input: s = "aa", k = 1
 * Output: 2
 * Explanation: The substring is "aa" with length 2.
 *
 *
 * Constraints:
 *
 * 1 <= s.length <= 5 * 104
 * 0 <= k <= 50
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    if (k == 0) {
      return 0;
    }
    int n = s.size(), left = 0, right = 0, ans = 0;
    vector<int> cnt(256, 0);
    int unique = 0;

    for (right = 0; right < n; ++right) {
      if (cnt[s[right]] == 0) {
        ++unique;
      }
      ++cnt[s[right]];
      while (unique > k) {
        if (--cnt[s[left]] == 0) {
          --unique;
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
    string s = "eceba";
    int k = 2;
    cout << "case1: " << sol.lengthOfLongestSubstringKDistinct(s, k)
         << " (expected 3)\n"; // "ece"
  }
  {
    string s = "aa";
    int k = 1;
    cout << "case2: " << sol.lengthOfLongestSubstringKDistinct(s, k)
         << " (expected 2)\n"; // "aa"
  }
  {
    string s = "a";
    int k = 0;
    cout << "case3: " << sol.lengthOfLongestSubstringKDistinct(s, k)
         << " (expected 0)\n"; // k==0 -> 0
  }
  {
    string s = "abc";
    int k = 2;
    cout << "case4: " << sol.lengthOfLongestSubstringKDistinct(s, k)
         << " (expected 2)\n"; // "ab" or "bc"
  }
  {
    string s = "ccaabbb";
    int k = 2;
    cout << "case5: " << sol.lengthOfLongestSubstringKDistinct(s, k)
         << " (expected 5)\n"; // "aabbb"
  }
  {
    string s = "abaccc";
    int k = 2;
    cout << "case6: " << sol.lengthOfLongestSubstringKDistinct(s, k)
         << " (expected 4)\n"; // "accc"
  }

  return 0;
}
