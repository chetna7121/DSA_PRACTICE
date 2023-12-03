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
    int maxLevelSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        int ans = 1;
        int maxLevelSum = INT_MIN;
        int level = 1; 
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int level_size = q.size();
            int sum = 0;
            
            for (int i = 0; i < level_size; ++i) {
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                
                if (temp->left != NULL)
                    q.push(temp->left);
                
                if (temp->right != NULL)
                    q.push(temp->right);
            }
            
            if (maxLevelSum < sum) {
                maxLevelSum = sum;
                ans = level;
            }
            
            ++level; 
        }
        
        return ans;
    }
};
