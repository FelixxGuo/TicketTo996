/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 *
 * https://leetcode.com/problems/reconstruct-itinerary/description/
 *
 * algorithms
 * Hard (43.85%)
 * Likes:    6247
 * Dislikes: 1918
 * Total Accepted:    520.3K
 * Total Submissions: 1.2M
 * Testcase Example: '[["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]'
 *
 * You are given a list of airline tickets where tickets[i] = [fromi, toi]
 * represent the departure and the arrival airports of one flight. Reconstruct
 * the itinerary in order and return it.
 *
 * All of the tickets belong to a man who departs from "JFK", thus, the
 * itinerary must begin with "JFK". If there are multiple valid itineraries,
 * you should return the itinerary that has the smallest lexical order when
 * read as a single string.
 *
 *
 * For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than
 * ["JFK", "LGB"].
 *
 *
 * You may assume all tickets form at least one valid itinerary. You must use
 * all the tickets once and only once.
 *
 *
 * Example 1:
 *
 *
 * Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
 * Output: ["JFK","MUC","LHR","SFO","SJC"]
 *
 *
 * Example 2:
 *
 *
 * Input: tickets =
 * [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
 * Explanation: Another possible reconstruction is
 * ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= tickets.length <= 300
 * tickets[i].length == 2
 * fromi.length == 3
 * toi.length == 3
 * fromi and toi consist of uppercase English letters.
 * fromi != toi
 *
 *
 */

// @lc code=start
class Solution1 {
public:
  vector<string> findItinerary(vector<vector<string>> &tickets) {
    vector<string> res;
    unordered_map<string, map<string, int>> ticketsMap;
    res.push_back("JFK");
    for (auto &ticket : tickets) {
      ticketsMap[ticket[0]][ticket[1]] += 1;
    }
    backtrack(tickets.size(), res, ticketsMap);
    return res;
  }
  bool backtrack(int ticketCount, vector<string> &res,
                 unordered_map<string, map<string, int>> &ticketsMap) {
    if (ticketCount + 1 == res.size()) {
      return true;
    }
    const string cur = res.back();
    unordered_map<string, map<string, int>>::iterator it = ticketsMap.find(cur);
    if (it == ticketsMap.end()) {
      return false;
    }

    for (pair<const string, int> &p : it->second) {
      if (p.second > 0) {
        res.push_back(p.first);
        --p.second;
        if (backtrack(ticketCount, res, ticketsMap)) {
          return true;
        }
        ++p.second;
        res.pop_back();
      }
    }
    return false;
  }
};

class Solution {
public:
  vector<string> findItinerary(vector<vector<string>> &tickets) {
    vector<string> res;
    unordered_map<string, multiset<string>> ticketsMap;
    for (int i = 0; i < tickets.size(); ++i) {
      ticketsMap[tickets[i][0]].insert(tickets[i][1]);
    }
    dfs("JFK", ticketsMap, res);
    reverse(res.begin(), res.end());
    return res;
  }

private:
  void dfs(const string &from,
           unordered_map<string, multiset<string>> &ticketsMap,
           vector<string> &res) {
    auto &dests = ticketsMap[from];
    while (!dests.empty()) {
      string next = *dests.begin();
      dests.erase(dests.begin());
      dfs(next, ticketsMap, res);
    }
    res.push_back(from);
  }
};
// @lc code=end
