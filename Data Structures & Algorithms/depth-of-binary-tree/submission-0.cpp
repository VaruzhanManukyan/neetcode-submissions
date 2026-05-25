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
        if (!root) {
            return 0;
        }

        std::queue<TreeNode*> queue_;
        queue_.push(root);

        int depth = 0;

        while (!queue_.empty()) {
            int level_size = queue_.size();

            for (std::size_t i = 0; i < level_size; ++i) {
                TreeNode* node = queue_.front();
                queue_.pop();

                if (node->left) {
                    queue_.push(node->left);
                } 
                if (node->right) {
                    queue_.push(node->right);
                }
            } 

            ++depth;
        }

        return depth;
    }
};
