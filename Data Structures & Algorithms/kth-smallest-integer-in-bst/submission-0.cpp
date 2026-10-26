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
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> stack_;
        TreeNode* current = root;
        int count = 0;
        
        while (!stack_.empty() || current) {
            while (current) {
                stack_.push(current);
                current = current->left;
            }

            current = stack_.top();
            stack_.pop();
            ++count;
            if (count == k) {
                return current->val;
            } 

            current = current->right;
        }
        return -1;
    }
};
