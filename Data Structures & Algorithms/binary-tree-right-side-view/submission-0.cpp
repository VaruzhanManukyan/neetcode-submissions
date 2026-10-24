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
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result;

        if (!root) {
            return result;
        }

        std::queue<TreeNode*> queue_;
        queue_.push(root);

        while(!queue_.empty()) {
            int size = queue_.size();

            for (int i = 0; i < size; ++i) {
                TreeNode* node =  queue_.front();
                queue_.pop();

                if (i == size - 1) {
                    result.push_back(node->val);
                }

                if (node->left) {
                    queue_.push(node->left);
                }

                if (node->right) {
                    queue_.push(node->right);
                }
            }
        }

        return result;
    }
};
