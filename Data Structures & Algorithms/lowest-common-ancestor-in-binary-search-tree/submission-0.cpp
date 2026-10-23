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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::stack<TreeNode*> stack_;
        std::unordered_map<TreeNode*, TreeNode*> parent;

        stack_.push(root);
        parent[root] = nullptr;

        while (!parent.count(p) || !parent.count(q)) {
            TreeNode* node = stack_.top();
            stack_.pop();

            if (node->right != nullptr) {
                stack_.push(node->right);
                parent[node->right] = node; 
            }

            if (node->left != nullptr) {
                stack_.push(node->left);
                parent[node->left] = node; 
            }
        }

        std::unordered_set<TreeNode*> ancestors;

        while (p != nullptr) {
            ancestors.insert(p);
            p = parent[p];
        }

        while (!ancestors.count(q)) {
            q = parent[q];
        }

        return q;
    }
};
