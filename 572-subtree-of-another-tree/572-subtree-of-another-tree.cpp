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
    
   bool inorder(TreeNode* root, TreeNode* subRoot){
        if(root==NULL)return false;;
        bool left=inorder(root->left,subRoot);
        bool right=inorder(root->right,subRoot);
        // if(left||right)return true;
        if(left||right)return true;
        
        if(root->val==subRoot->val){
            return check(root,subRoot);
        }
       
       return false; 
    }
    bool check(TreeNode* root, TreeNode* subRoot){
        
        if(root==NULL&&subRoot!=NULL||subRoot==NULL&&root!=NULL)return false;
        if(root==NULL&&subRoot==NULL)return true;
        
        bool left=check(root->left,subRoot->left);
        bool right=check(root->right,subRoot->right);
        
        if(left&&right&&(root->val==subRoot->val))return true;
        return false;
    }
     
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==NULL)return true;
      return inorder(root,subRoot);
    }
};