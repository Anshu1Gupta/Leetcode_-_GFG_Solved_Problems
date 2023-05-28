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
TreeNode*build(vector<int>& preorder,int prestart,int preend, vector<int>& inorder,int instart,int inend,unordered_map<int,int>&mp){
    if(prestart>preend||instart>inend)return NULL;
    TreeNode* node=new TreeNode(preorder[prestart]);
    int ind=mp[node->val];
    int numsleft=-instart+ind;
    
    node->left=build(preorder,prestart+1,prestart+numsleft,inorder,instart,ind-1,mp);
    node->right=build(preorder,prestart+numsleft+1,preend,inorder,ind+1,inend,mp);
    return node;
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        } TreeNode*root=build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
};