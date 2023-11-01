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
    void findMode(TreeNode*root,unordered_map<int,int>&mp){
        if(root==NULL)return;
        mp[root->val]++;
        findMode(root->left,mp);
        findMode(root->right,mp);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>mp;
        findMode(root,mp);
        int maxi=0;
        for(auto it:mp){
            maxi=max(maxi,it.second);
        }
        vector<int>ans;
        for(auto it:mp){
            if(maxi==it.second){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};