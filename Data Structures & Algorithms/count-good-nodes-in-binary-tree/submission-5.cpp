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
    int goodNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        std::stack<std::pair<TreeNode*, int>> stack_;
        stack_.push({root, root->val});

        int count = 0;

        while (!stack_.empty()) {
            auto [node, maxAncestor] = stack_.top();
            stack_.pop();

            if (node->val >= maxAncestor) {
                ++count;
            }

            int nextMax = std::max(node->val, maxAncestor);

            if (node->right) {
                stack_.push({node->right, nextMax});
            }

            if (node->left) {
                stack_.push({node->left, nextMax});
            }
        }

        return count;
    }
};
