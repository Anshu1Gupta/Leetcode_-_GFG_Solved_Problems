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
    TreeNode* merge(TreeNode*root,TreeNode*l,TreeNode*r){
       
        root->left=l;
        root->right=r;
        return root;

    }
    TreeNode*mergeSort(int l,int r,vector<int>&v){
        if(l>r)return NULL;
        int m=(l+r)/2;
        TreeNode* root=new TreeNode(v[m]);
        TreeNode*le=mergeSort(l,m-1,v);
        TreeNode*ri=mergeSort(m+1,r,v);
        TreeNode*temp=merge(root,le,ri);
        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& v) {
        int n=v.size();
       return mergeSort(0,n-1,v);


        
    }
};