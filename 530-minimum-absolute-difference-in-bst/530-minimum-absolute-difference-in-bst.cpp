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

   
      
    vector<int>ans;
void preorder(TreeNode*root){
        if(root!=NULL){
        preorder(root->left);
        ans.push_back(root->val);
        preorder(root->right);
        
    }
   
 }
public:

    int getMinimumDifference(TreeNode* root) {
      
        preorder(root);
      
        int mini=INT_MAX;
        for(int i=0;i<ans.size()-1;i++){
            mini=min(mini,abs(ans[i]-ans[i+1]));
        }
return mini;
    }
};