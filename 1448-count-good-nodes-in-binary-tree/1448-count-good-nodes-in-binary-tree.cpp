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

        int count = 0;
        std::queue<std::pair<TreeNode*, int>> q;
        q.push({root, INT_MIN});

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            TreeNode* node = current.first;
            int max_val = current.second;

            if (node->val >= max_val) {
                count++;
                max_val = node->val;
            }

            if (node->left) {
                q.push({node->left, max_val});
            }

            if (node->right) {
                q.push({node->right, max_val});
            }
        }

        return count;
    }
};