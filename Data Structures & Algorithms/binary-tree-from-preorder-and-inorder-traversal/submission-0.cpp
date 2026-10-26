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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[0]);
        std::stack<TreeNode*> stack_;
        stack_.push(root);
        int size = preorder.size();
        int in_index = 0;

        for (int i = 1; i < size; ++i) {
            TreeNode* node = stack_.top();
            TreeNode* child = new TreeNode(preorder[i]);

            if (node->val != inorder[in_index]) {
                node->left = child;
            } else {
                while (!stack_.empty() && stack_.top()->val == inorder[in_index]) {
                    node = stack_.top();
                    stack_.pop();
                    ++in_index;
                }
                node->right = child;
            }
            stack_.push(child);
        }
        return root;
    }
};
