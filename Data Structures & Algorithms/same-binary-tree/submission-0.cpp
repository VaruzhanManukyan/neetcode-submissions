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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }

        if (!p || !q) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        std::stack<TreeNode*> stack1;
        std::stack<TreeNode*> stack2;
        stack1.push(p);
        stack2.push(q);

        while (!stack1.empty() && !stack2.empty()) {
            TreeNode* node1 = stack1.top();
            TreeNode* node2 = stack2.top();
            stack1.pop();
            stack2.pop();

            if (node1->val != node2->val) {
                return false;
            }

            if (node1->right) {
                if (!node2->right) {
                    return false;
                }
                stack1.push(node1->right);
                stack2.push(node2->right);
            } else if (node2->right) {
                return false;
            }
            if (node1->left) {
                if (!node2->left) {
                    return false;
                }
                stack1.push(node1->left);
                stack2.push(node2->left);
            } else if (node2->left) {
                return false;
            }
        } 
        return stack1.empty() && stack2.empty();
    }
};
