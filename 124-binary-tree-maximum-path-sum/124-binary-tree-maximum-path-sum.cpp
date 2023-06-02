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
    int ans;
public:
    int maximum(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        int left=max(0,maximum(root->left));
        int right=max(0,maximum(root->right));
        
        ans=max(ans,root->val+left+right);
        return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;
        maximum(root);
        return ans;
    }
};