/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 *
 * https://leetcode.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (56.13%)
 * Likes:    11675
 * Dislikes: 809
 * Total Accepted:    2.1M
 * Total Submissions: 3.8M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, determine if it is height-balanced.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,2,3,3,null,null,4,4]
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: root = []
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 5000].
 * -10^4 <= Node.val <= 10^4
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
  bool isBalanced(TreeNode *root) {
    int height = getHeight(root);
    if (height == -1) {
      return false;
    }
    return true;
  }

private:
  int getHeight(TreeNode *node) {
    if (!node) {
      return 0;
    }
    int leftHeight = getHeight(node->left);
    if (leftHeight == -1) {
      return -1;
    }
    int rightHeight = getHeight(node->right);
    if (rightHeight == -1) {
      return -1;
    }
    return abs(leftHeight - rightHeight) > 1 ? -1
                                             : max(leftHeight, rightHeight) + 1;
  }
};
// @lc code=end
