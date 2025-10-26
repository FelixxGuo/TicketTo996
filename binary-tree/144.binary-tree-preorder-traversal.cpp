/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (74.14%)
 * Likes:    8644
 * Dislikes: 228
 * Total Accepted:    2.2M
 * Total Submissions: 3M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the preorder traversal of its nodes'
 * values.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,3]
 *
 * Output: [1,2,3]
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
 * Output: [1,2,4,5,6,7,3,8,9]
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
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 *
 *
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 *
 */

// @lc code=start
#include <stack>
#include <vector>

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
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    traversal(root, res);
    return res;
  }

private:
  void traversal(TreeNode *node, vector<int> &res) {
    if (!node) {
      return;
    }
    res.push_back(node->val);
    traversal(node->left, res);
    traversal(node->right, res);
  }
};

class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    if (!root) {
      return res;
    }
    stack<TreeNode *> stk;
    stk.push(root);

    while (!stk.empty()) {
      TreeNode *node = stk.top();
      res.push_back(node->val);
      stk.pop();
      if (node->right) {
        stk.push(node->right);
      }
      if (node->left) {
        stk.push(node->left);
      }
    }
    return res;
  }
};
// @lc code=end
