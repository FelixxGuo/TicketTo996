/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
 *
 * https://leetcode.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (61.99%)
 * Likes:    5725
 * Dislikes: 320
 * Total Accepted:    747.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return the sum of all left leaves.
 *
 * A leaf is a node with no children. A left leaf is a leaf that is the left
 * child of another node.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 24
 * Explanation: There are two left leaves in the binary tree, with values 9 and
 * 15 respectively.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 1000].
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
  int sumOfLeftLeaves(TreeNode *root) {
    if (!root) {
      return 0;
    }
    return getSum(root);
  }

private:
  int getSum(TreeNode *node) {
    if (!node) {
      return 0;
    }
    int leftSum = getSum(node->left);
    if (node->left && !node->left->left && !node->left->right) {
      leftSum = node->left->val;
    }
    int rightSum = getSum(node->right);
    return leftSum + rightSum;
  }
};

class Solution {
public:
  int sumOfLeftLeaves(TreeNode *root) {
    int res = 0;
    getSum(root, false, res);
    return res;
  }

private:
  void getSum(TreeNode *node, bool left, int &res) {
    if (!node) {
      return;
    }
    if (!node->left && !node->right) {
      if (left) {
        res += node->val;
      }
    }
    getSum(node->left, true, res);
    getSum(node->right, false, res);
  }
};
// @lc code=end
