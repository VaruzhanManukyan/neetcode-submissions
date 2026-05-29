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
            TreeNode* node = stack_.top();
            stack_.pop();

            if (node->val == subRoot->val) {
                std::stack<TreeNode*> check_main;
                std::stack<TreeNode*> check_sub;

                check_main.push(node);
                check_sub.push(subRoot);

                bool is_identical = true;

                while(!check_main.empty() && !check_sub.empty()) {
                    TreeNode* node_main = check_main.top();
                    TreeNode* node_sub = check_sub.top();
                    check_main.pop();
                    check_sub.pop();

                    if (node_main->val != node_sub->val) {
                        is_identical = false;
                        break;
                    }

                    if (node_main->left && node_sub->left) {
                        check_main.push(node_main->left);
                        check_sub.push(node_sub->left);
                    } else if (node_main->left || node_sub->left) {
                        is_identical = false;
                        break;
                    }

                    if (node_main->right && node_sub->right) {
                        check_main.push(node_main->right);
                        check_sub.push(node_sub->right);
                    } else if (node_main->right || node_sub->right) {
                        is_identical = false;
                        break;
                    }
                }
                
                if (is_identical && check_main.empty() && check_sub.empty()) {
                    return true;
                }
            }

            if (node->right) {
                stack_.push(node->right);
            } 
            if (node->left) {
                stack_.push(node->left);
            } 
        }
        return false;
    }
};
