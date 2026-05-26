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
    bool balanced = true;

    int height(TreeNode* node) {
        if (!node) {
            return 0;
        }

        int left = height(node->left);
        int right = height(node->right);
        
        if (std::abs(left - right) > 1) {
            balanced = false;
            return 0;
        }

        return 1 + std::max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        height(root); 

        return balanced;
    }
};
