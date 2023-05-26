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
    bool ans(TreeNode*root,long long left,long long right){
        if(root==NULL)return true;
        return(root->val>left&&root->val<right&&ans(root->left,left,root->val)&&ans(root->right,root->val,right));
        
    
        // return false;
    }
    bool isValidBST(TreeNode* root) {
        // if(root->val==2147483647||root->val==-2147483648)return true;
       long long left=INT_MIN-1l;
      long long right=INT_MAX+1l;
        cout<<left<<' '<<right<<endl;
        return ans(root,left,right);
    }
};