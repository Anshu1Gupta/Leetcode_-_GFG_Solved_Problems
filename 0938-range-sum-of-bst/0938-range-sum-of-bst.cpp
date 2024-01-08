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
    void findRange(TreeNode*root,int low,int high,int &sum){
        if(root==NULL)return;
        findRange(root->left,low,high,sum);
        findRange(root->right,low,high,sum);
    
        if(root->val>=low  &&  root->val<=high){
            sum+=root->val;
            cout<<root->val<<endl;
        }
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        findRange(root,low,high,sum);
        return sum;
    }
};