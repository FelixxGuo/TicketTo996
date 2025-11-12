/*
 * @lc app=leetcode id=2024 lang=cpp
 *
 * [2024] Maximize the Confusion of an Exam
 *
 * https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/
 *
 * algorithms
 * Medium (69.12%)
 * Likes:    3047
 * Dislikes: 52
 * Total Accepted:    135.9K
 * Total Submissions: 196K
 * Testcase Example:  '"TTFF"\n2'
 *
 * A teacher is writing a test with n true/false questions, with 'T' denoting
 * true and 'F' denoting false. He wants to confuse the students by maximizing
 * the number of consecutive questions with the same answer (multiple trues or
 * multiple falses in a row).
 *
 * You are given a string answerKey, where answerKey[i] is the original answer
 * to the i^th question. In addition, you are given an integer k, the maximum
 * number of times you may perform the following operation:
 *
 *
 * Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i]
 * to 'T' or 'F').
 *
 *
 * Return the maximum number of consecutive 'T's or 'F's in the answer key
 * after performing the operation at most k times.
 *
 *
 * Example 1:
 *
 *
 * Input: answerKey = "TTFF", k = 2
 * Output: 4
 * Explanation: We can replace both the 'F's with 'T's to make answerKey =
 * "TTTT".
 * There are four consecutive 'T's.
 *
 *
 * Example 2:
 *
 *
 * Input: answerKey = "TFFT", k = 1
 * Output: 3
 * Explanation: We can replace the first 'T' with an 'F' to make answerKey =
 * "FFFT".
 * Alternatively, we can replace the second 'T' with an 'F' to make answerKey =
 * "TFFF".
 * In both cases, there are three consecutive 'F's.
 *
 *
 * Example 3:
 *
 *
 * Input: answerKey = "TTFTTFTT", k = 1
 * Output: 5
 * Explanation: We can replace the first 'F' to make answerKey = "TTTTTFTT"
 * Alternatively, we can replace the second 'F' to make answerKey =
 * "TTFTTTTT".
 * In both cases, there are five consecutive 'T's.
 *
 *
 *
 * Constraints:
 *
 *
 * n == answerKey.length
 * 1 <= n <= 5 * 10^4
 * answerKey[i] is either 'T' or 'F'
 * 1 <= k <= n
 *
 *
 */

// @lc code=start
class Solution {
public:
  int maxConsecutiveAnswers(string answerKey, int k) {
    int left = 0, right = 0, n = answerKey.size(), ans = 0;
    unordered_map<char, int> cnt;

    for (right = 0; right < n; ++right) {
      cnt[answerKey[right]]++;
      while (cnt['T'] > k && cnt['F'] > k) {
        cnt[answerKey[left]]--;
        ++left;
      }
      ans = max(ans, right - left + 1);
    }
    return ans;
  }
};
// @lc code=end
