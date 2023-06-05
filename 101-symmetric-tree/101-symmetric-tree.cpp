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
    bool isSym(TreeNode*left,TreeNode*right){
        if(right==NULL&&left==NULL)return true;
        if(left==NULL&&right!=NULL||right==NULL&&left!=NULL)return false;
        
        bool take=isSym(left->left,right->right);
        bool ntake=isSym(left->right,right->left);
        if(take&&ntake&&left->val==right->val)return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        
        if(root==NULL)return true;
        return isSym(root->left,root->right);
    }
};