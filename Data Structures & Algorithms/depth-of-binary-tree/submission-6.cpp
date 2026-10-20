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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        std::stack<std::pair<std::int8_t, TreeNode*>> stack_{};
        stack_.push({1, root});
        std::pair<std::int8_t, TreeNode*> current{0, nullptr};
        std::int8_t depth = 0;

        while (!stack_.empty()) {
            current = stack_.top();
            stack_.pop();
            
            depth = std::max(current.first, depth);

            if (current.second->left != nullptr) {
                stack_.push({current.first + 1, current.second->left});
            }

            if (current.second->right != nullptr) {
                stack_.push({current.first + 1, current.second->right});
            }
        }

        return depth;
    }
};
