/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
 *
 * https://leetcode.com/problems/house-robber-iii/description/
 *
 * algorithms
 * Medium (55.19%)
 * Likes:    8955
 * Dislikes: 154
 * Total Accepted:    466.6K
 * Total Submissions: 844.8K
 * Testcase Example:  '[3,2,3,null,3,null,1]'
 *
 * The thief has found himself a new place for his thievery again. There is
 * only one entrance to this area, called root.
 *
 * Besides the root, each house has one and only one parent house. After a
 * tour, the smart thief realized that all houses in this place form a binary
 * tree. It will automatically contact the police if two directly-linked houses
 * were broken into on the same night.
 *
 * Given the root of the binary tree, return the maximum amount of money the
 * thief can rob without alerting the police.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,2,3,null,3,null,1]
 * Output: 7
 * Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [3,4,5,1,3,null,1]
 * Output: 9
 * Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * 0 <= Node.val <= 10^4
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <unordered_map>
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
  int rob(TreeNode *root) {
    if (!root) {
      return 0;
    }
    if (!root->left && !root->right) {
      return root->val;
    }
    int val1 = root->val;
    if (root->left) {
      val1 += rob(root->left->left) + rob(root->left->right);
    }
    if (root->right) {
      val1 += rob(root->right->left) + rob(root->right->right);
    }

    int val2 = 0;
    val1 += rob(root->left) + rob(root->right);
    return max(val1, val2);
  }
};

class Solution2 {
public:
  unordered_map<TreeNode *, int> umap;
  int rob(TreeNode *root) {
    if (!root) {
      return 0;
    }
    if (!root->left && !root->right) {
      return root->val;
    }
    if (umap[root]) {
      return umap[root];
    }
    int val1 = root->val;
    if (root->left) {
      val1 += rob(root->left->left) + rob(root->left->right);
    }
    if (root->right) {
      val1 += rob(root->right->left) + rob(root->right->right);
    }

    int val2 = rob(root->left) + rob(root->right);
    return max(val1, val2);
  }
};

class Solution {
public:
  int rob(TreeNode *root) {
    vector<int> res = robAux(root);
    return max(res[0], res[1]);
  }

private:
  vector<int> robAux(TreeNode *node) {
    if (!node) {
      return vector<int>{0, 0};
    }
    vector<int> vLeft = robAux(node->left);
    vector<int> vRight = robAux(node->right);

    int val1 = max(vLeft[0], vLeft[1]) + max(vRight[0], vRight[1]);
    int val2 = node->val + vLeft[0] + vRight[0];
    return {val1, val2};
  }
};
// @lc code=end
