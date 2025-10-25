/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
 *
 * https://leetcode.com/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (71.92%)
 * Likes:    3956
 * Dislikes: 300
 * Total Accepted:    422.7K
 * Total Submissions: 587.2K
 * Testcase Example:  '[2,1,3]'
 *
 * Given the root of a binary tree, return the leftmost value in the last row
 * of the tree.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [2,1,3]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,3,4,null,5,6,null,null,7]
 * Output: 7
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -2^31 <= Node.val <= 2^31 - 1
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
class Solution {
public:
  int findBottomLeftValue(TreeNode *root) {
    int res = 0;
    int depth = 0;
    int resDepth = -1;
    traversal(root, res, depth, resDepth);
    return res;
  }

private:
  void traversal(TreeNode *node, int &res, int depth, int &resDepth) {
    if (!node) {
      return;
    }
    if (!node->left && !node->right) {
      if (resDepth < depth) {
        resDepth = depth;
        res = node->val;
      }
    }
    traversal(node->left, res, depth + 1, resDepth);
    traversal(node->right, res, depth + 1, resDepth);
  }
};
// @lc code=end
