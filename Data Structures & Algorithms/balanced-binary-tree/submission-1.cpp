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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        std::stack<std::pair<bool, TreeNode*>> stack_;
        std::unordered_map<TreeNode*, int> height;
        stack_.push({false, root});

        while (!stack_.empty()) {
            auto [visited, node] = stack_.top();
            stack_.pop();

            if (!visited) {
                stack_.push({true, node});
                
                if (node->right != nullptr) {
                    stack_.push({false, node->right});
                }
                if (node->left != nullptr) {
                    stack_.push({false, node->left});
                }
            } else {
                int left = 0;
                int right = 0;
                if (node->right != nullptr) {
                    right = height[node->right];
                }
                if (node->left != nullptr) {
                    left = height[node->left];
                }

                if (std::abs(left - right) > 1) {
                    return false;
                }

                height[node] = 1 + std::max(left, right);
            }
        }
        return true;
    }
};
