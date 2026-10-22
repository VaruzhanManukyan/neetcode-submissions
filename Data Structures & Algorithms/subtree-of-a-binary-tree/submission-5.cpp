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
private:
    bool isSame(TreeNode* root, TreeNode* root1) {
        std::stack<std::pair<TreeNode*, TreeNode*>> stack_;
        stack_.push({root, root1});

        while (!stack_.empty()) {
            auto [node, node1] = stack_.top();
            stack_.pop();

            if (!node && !node1) {
                continue;
            } 

            if (!node || !node1 || node->val != node1->val) {
                return false;
            }

            stack_.push({node->left, node1->left});
            stack_.push({node->right, node1->right});
        }

        return true;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) {
            return true;
        }

        if (!root) {
            return false;
        }

        std::stack<TreeNode*> stack_;
        stack_.push(root);

        while (!stack_.empty()) {
            TreeNode* current = stack_.top();
            stack_.pop();

            if (current->val == subRoot->val && isSame(current, subRoot)) {
                return true;
            }


            if (current->left) {
                stack_.push(current->left);
            }

            if (current->right) {
                stack_.push(current->right);
            }
        }
        return false;
    }
};
