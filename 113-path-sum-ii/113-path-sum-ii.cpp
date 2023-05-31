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
    void findTar(TreeNode*root,int targetSum,vector<vector<int>>&ans,vector<int>&temp){
        if(root==NULL)return;
        if(root->left==NULL&&root->right==NULL){
            if(targetSum==root->val){
                temp.push_back(root->val);
                ans.push_back(temp);
                temp.pop_back();
                
            }
            
            return;
        }
        
        temp.push_back(root->val);
        findTar(root->left,targetSum-root->val,ans,temp);
        findTar(root->right,targetSum-root->val,ans,temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        findTar(root,targetSum,ans,temp);
        return ans;
    }
};