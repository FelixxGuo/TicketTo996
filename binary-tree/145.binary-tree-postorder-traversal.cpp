/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (76.62%)
 * Likes:    7600
 * Dislikes: 222
 * Total Accepted:    1.8M
 * Total Submissions: 2.3M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the postorder traversal of its
 * nodes' values.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,3]
 *
 * Output: [3,2,1]
 *
 * Explanation:
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
 *
 * Output: [4,6,7,5,2,9,8,3,1]
 *
 * Explanation:
 *
 *
 *
 *
 * Example 3:
 *
 *
 * Input: root = []
 *
 * Output: []
 *
 *
 * Example 4:
 *
 *
 * Input: root = [1]
 *
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of the nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 *
 *
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution1 {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    traversal(root, res);
    return res;
  }

private:
  void traversal(TreeNode *node, vector<int> &res) {
    if (!node) {
      return;
    }
    traversal(node->left, res);
    traversal(node->right, res);
    res.push_back(node->val);
  }
};

class Solution {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    stack<TreeNode *> stk;
    if (!root) {
      return res;
    }
    stk.push(root);
    while (!stk.empty()) {
      TreeNode *node = stk.top();
      res.push_back(node->val);
      stk.pop();

      if (node->left) {
        stk.push(node->left);
      }
      if (node->right) {
        stk.push(node->right);
      }
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end
