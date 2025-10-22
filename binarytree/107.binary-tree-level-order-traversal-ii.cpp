/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Medium (66.71%)
 * Likes:    5089
 * Dislikes: 330
 * Total Accepted:    777.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return the bottom-up level order traversal
 * of its nodes' values. (i.e., from left to right, level by level from leaf to
 * root).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[15,7],[9,20],[3]]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1]
 * Output: [[1]]
 *
 *
 * Example 3:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 2000].
 * -1000 <= Node.val <= 1000
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution1 {
public:
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> res;
    if (!root) {
      return res;
    }
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty()) {
      int sz = que.size();
      vector<int> level;
      for (int i = 0; i < sz; ++i) {
        TreeNode *node = que.front();
        level.push_back(node->val);
        que.pop();
        if (node->left) {
          que.push(node->left);
        }
        if (node->right) {
          que.push(node->right);
        }
      }
      res.push_back(level);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> res;
    level(root, res, 0);
    reverse(res.begin(), res.end());
    return res;
  }

private:
  void level(TreeNode *node, vector<vector<int>> &res, int depth) {
    if (!node) {
      return;
    }
    if (res.size() == depth) {
      res.push_back(vector<int>());
    }
    res[depth].push_back(node->val);
    level(node->left, res, depth + 1);
    level(node->right, res, depth + 1);
  }
};
// @lc code=end
