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
    
//     bool check(TreeNode* root, TreeNode* subRoot){
//         if(root==NULL&&subRoot==NULL)return true;
//         if(subRoot==NULL||root==NULL)return false;
        
//         if(root->val!=subRoot->val)return false;
        
//         bool left=check(root->left,subRoot->left);
//         bool right=check(root->right,subRoot->right);
        
//         // if(left&&right&&(root->val==subRoot->val))return true;
//         return left|right;
//     }
     
//     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
//        if(!root) return 0;
//         if(check(root, subRoot)) return 1;
//         bool left = isSubtree(root->left, subRoot);
//         bool right = isSubtree(root->right, subRoot);
//         return left|right;
//     }    
     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return 0;
        if(isSameTree(root, subRoot)) return 1;
        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        return left|right;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return 1;
        if(!p || !q) return 0;
        if(p->val!=q->val) return 0;
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        return left&right;
    }
};