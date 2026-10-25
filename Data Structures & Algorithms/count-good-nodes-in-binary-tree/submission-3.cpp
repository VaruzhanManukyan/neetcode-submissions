/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root, int maxAncestor = INT_MIN) {
        if (!root) {
            return 0;
        }

        int count = (root->val >= maxAncestor) ? 1 : 0;
        int nextMax = std::max(maxAncestor, root->val);

        return count
            + goodNodes(root->left, nextMax)
            + goodNodes(root->right, nextMax);
    }
};
