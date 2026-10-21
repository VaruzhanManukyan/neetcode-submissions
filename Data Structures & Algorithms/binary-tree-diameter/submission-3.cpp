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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        std::stack<std::pair<bool, TreeNode*>> stack_;
        std::unordered_map<TreeNode*, int> height;
        stack_.push({false, root});

        int diameter = 0;

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

                diameter = std::max(diameter, left + right);
                height[node] = 1 + std::max(left, right);
            }
        }
        return diameter;
    }
};
