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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        std::stack<TreeNode*> stack_;
        stack_.push(root);
        while (!stack_.empty()) {
            TreeNode* current = stack_.top();
            stack_.pop();

            if (current->left) {
                stack_.push(current->left);
            }
            if (current->right) {
                stack_.push(current->right);
            }

            std::swap(current->left, current->right);      
        }
        return root;
    }
};
