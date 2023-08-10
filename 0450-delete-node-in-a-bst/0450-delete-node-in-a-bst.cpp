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
    int minRight(TreeNode*root){
        TreeNode*temp=root;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp->val;
    }
    TreeNode* modifyTree(TreeNode* root,int key){
        if(root==NULL)return NULL;
        
        if(root->val>key){
            root->left=modifyTree(root->left,key);
        }
        else if(root->val<key){
            root->right=modifyTree(root->right,key);
        }
        
        else{
            if(root->left==NULL)return root->right;
            else if(root->right==NULL)return root->left;
            
            else{
                root->val=minRight(root->right);
                root->right=modifyTree(root->right,root->val);
            }
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        return modifyTree(root,key);
    }
};