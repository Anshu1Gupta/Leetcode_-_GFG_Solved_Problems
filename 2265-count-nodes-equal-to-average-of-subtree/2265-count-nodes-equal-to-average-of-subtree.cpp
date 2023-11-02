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
    int size(TreeNode*root){
        if(root==NULL)return 0;
        
        int left=size(root->left);
        int right=size(root->right);
        
        return 1+left+right;
    }
    int subTree(TreeNode*root){
        if(root==NULL)return 0;
        
        int left=subTree(root->left);
        int right=subTree(root->right);
        
        return left+right+root->val;
    }
    void findCount(TreeNode*root,int &count){
        if(root==NULL)return ;
        
        findCount(root->left,count);
        findCount(root->right,count);
        
        if(root->val==subTree(root)/size(root))count++;
    }
    int averageOfSubtree(TreeNode* root) {
        int count=0;
        findCount(root,count);
        return count;
    }
};