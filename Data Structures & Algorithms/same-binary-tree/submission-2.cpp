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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        } else if (!p || !q) {
            return false;
        }

        std::stack<TreeNode*> stack_;
        std::stack<TreeNode*> stack1_;
        stack_.push(p);
        stack1_.push(q);

        while (!stack_.empty() && !stack1_.empty()) {
            TreeNode* node = stack_.top();
            TreeNode* node1 = stack1_.top();
            stack_.pop();
            stack1_.pop();

            if (!node && !node1) {
                continue;   
            }

            if (!node || !node1 ||  node->val != node1->val) {
                return false;
            }

            stack_.push(node->right);
            stack1_.push(node1->right);
            stack_.push(node->left);
            stack1_.push(node1->left);
        }

        return stack_.empty() && stack1_.empty();
    }
};
