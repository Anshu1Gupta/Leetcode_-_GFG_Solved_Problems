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
    
    void findGood(TreeNode*root,int maxi,unordered_map<TreeNode*,int>&mp){
        if(root==NULL){
           return; 
        }
        if(root->val>=maxi){
            if(mp.find(root)==mp.end()){
                mp[root]++;
            }
        }
        
        findGood(root->left,max(maxi,root->val),mp);
        findGood(root->right,max(maxi,root->val),mp);
    }
    int goodNodes(TreeNode* root) {
      
        if(root==NULL)return 0;
        unordered_map<TreeNode*,int>mp;
        findGood(root,root->val,mp);
        return mp.size();
    }
};