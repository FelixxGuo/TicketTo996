/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (66.97%)
 * Likes:    8562
 * Dislikes: 150
 * Total Accepted:    874.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given two integer arrays inorder and postorder where inorder is the inorder
 * traversal of a binary tree and postorder is the postorder traversal of the
 * same tree, construct and return the binary tree.
 *
 *
 * Example 1:
 *
 *
 * Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 * Output: [3,9,20,null,null,15,7]
 *
 *
 * Example 2:
 *
 *
 * Input: inorder = [-1], postorder = [-1]
 * Output: [-1]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= inorder.length <= 3000
 * postorder.length == inorder.length
 * -3000 <= inorder[i], postorder[i] <= 3000
 * inorder and postorder consist of unique values.
 * Each value of postorder also appears in inorder.
 * inorder is guaranteed to be the inorder traversal of the tree.
 * postorder is guaranteed to be the postorder traversal of the tree.
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
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int n = postorder.size();
    return buildSubTree(inorder, 0, n - 1, postorder, 0, n - 1);
  }

private:
  TreeNode *buildSubTree(vector<int> &inorder, int start1, int end1,
                         vector<int> &postorder, int start2, int end2) {
    if (start1 > end1) {
        return nullptr;
    }
    TreeNode *root = new TreeNode(postorder[end2]);
    int len = 0;
    for (int i = start1; i <= end1; ++i) {
      if (inorder[i] == postorder[end2]) {
        len = i - start1;
        break;
      }
    }
    TreeNode *left = buildSubTree(inorder, start1, start1 + len - 1,
                                      postorder, start2, start2 + len - 1);
    TreeNode *right = buildSubTree(inorder, start1 + len + 1, end1,
                                       postorder, start2 + len, end2 - 1);
    root->left = left;
    root->right = right;
    return root;
  }
};
// @lc code=end
