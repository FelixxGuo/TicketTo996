/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (59.91%)
 * Likes:    16479
 * Dislikes: 434
 * Total Accepted:    2.6M
 * Total Submissions: 4.4M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given the root of a binary tree, check whether it is a mirror of itself
 * (i.e., symmetric around its center).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,2,3,4,4,3]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,2,null,3,null,3]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 1000].
 * -100 <= Node.val <= 100
 *
 *
 *
 * Follow up: Could you solve it both recursively and iteratively?
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
  bool isSymmetric(TreeNode *root) {
    return symmetric(root->left, root->right);
  }

private:
  bool symmetric(TreeNode *left, TreeNode *right) {
    if (!left && right) {
      return false;
    }
    if (left && !right) {
      return false;
    }
    if (!left && !right) {
      return true;
    }
    if (left->val != right->val) {
      return false;
    }
    if (left->val != right->val) {
      return false;
    }
    return symmetric(left->left, right->right) &&
           symmetric(left->right, right->left);
  }
};

class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    queue<TreeNode *> que;
    que.push(root->left);
    que.push(root->right);
    while (!que.empty()) {
      TreeNode *leftNode = que.front();
      que.pop();
      TreeNode *rightNode = que.front();
      que.pop();
      if (!leftNode && !rightNode) {
        continue;
      }
      if (!leftNode && rightNode) {
        return false;
      }
      if (leftNode && !rightNode) {
        return false;
      }
      if (leftNode->val != rightNode->val) {
        return false;
      }
      que.push(leftNode->left);
      que.push(rightNode->right);
      que.push(leftNode->right);
      que.push(rightNode->left);
    }
    return true;
  }
};
// @lc code=end
