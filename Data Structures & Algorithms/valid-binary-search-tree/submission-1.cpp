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
    bool isValidBST(TreeNode* root) {
       std::stack<TreeNode*> stack_;
       TreeNode* previous = nullptr;
       TreeNode* current = root;

        while (!stack_.empty() || current) {
            while (current) {
                stack_.push(current);
                current = current->left;
            }

            current = stack_.top();
            stack_.pop();

            if (previous && previous->val >= current->val) {
                return false;
            }

            previous = current;
            current = current->right;
        } 
        return true;
    }
};
