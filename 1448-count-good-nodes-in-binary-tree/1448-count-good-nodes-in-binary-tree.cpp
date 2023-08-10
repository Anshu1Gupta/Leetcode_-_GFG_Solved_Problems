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
    int ans=0;
    void findGood(TreeNode*root,int maxi){
        if(root==NULL){
           return; 
        }
        if(root->val>=maxi){
           ans++;
        }
        
        findGood(root->left,max(maxi,root->val));
        findGood(root->right,max(maxi,root->val));
    }
    int goodNodes(TreeNode* root) {
      
        if(root==NULL)return 0;
        unordered_map<TreeNode*,int>mp;
        findGood(root,root->val);
        return ans;
    }
};