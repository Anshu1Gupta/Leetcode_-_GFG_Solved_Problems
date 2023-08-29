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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int size=q.size();
            int s=size;
            double sum=0;
            while(size--){
                TreeNode*node=q.front();q.pop();
                sum+=node->val;
                
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                
            }
            ans.push_back(sum/(s*1.0));
        }
        return ans;
        
    }
};