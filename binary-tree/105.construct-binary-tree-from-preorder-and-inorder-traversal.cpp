/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (67.51%)
 * Likes:    16287
 * Dislikes: 596
 * Total Accepted:    1.7M
 * Total Submissions: 2.5M
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given two integer arrays preorder and inorder where preorder is the preorder
 * traversal of a binary tree and inorder is the inorder traversal of the same
 * tree, construct and return the binary tree.
 *
 *
 * Example 1:
 *
 *
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 *
 *
 * Example 2:
 *
 *
 * Input: preorder = [-1], inorder = [-1]
 * Output: [-1]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder and inorder consist of unique values.
 * Each value of inorder also appears in preorder.
 * preorder is guaranteed to be the preorder traversal of the tree.
 * inorder is guaranteed to be the inorder traversal of the tree.
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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = preorder.size();
    return build(preorder, 0, n - 1, inorder, 0, n - 1);
  }

private:
  TreeNode *build(vector<int> &preorder, int preorderStart, int preorderEnd,
                  vector<int> &inorder, int inorderStart, int inorderEnd) {
    if (preorderStart > preorderEnd) {
      return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[preorderStart]);
    int len = 0;
    for (int i = inorderStart; i <= inorderEnd; ++i) {
      if (inorder[i] == preorder[preorderStart]) {
        len = i - inorderStart;
        break;
      }
    }
    TreeNode *left = build(preorder, preorderStart + 1, preorderStart + len,
                           inorder, inorderStart, inorderStart + len - 1);
    TreeNode *right = build(preorder, preorderStart + len + 1, preorderEnd,
                            inorder, inorderStart + len + 1, inorderEnd);
    root->left = left;
    root->right = right;
    return root;
  }
};
// @lc code=end
