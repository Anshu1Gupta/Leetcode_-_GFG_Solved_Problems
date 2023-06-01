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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>q;
        if(root==NULL)return 0;
        q.push({root,0});
        long long ans=0;
        while(!q.empty()){
            long long size=q.size();
            long long mini=q.front().second;
            long long first,second;
            for(int i=0;i<size;i++){
                
               TreeNode* node=q.front().first;
                long long index=q.front().second;q.pop();
                if(i==0)first=index;
                if(i==size-1)second=index;
                if(node->left){q.push({node->left,(2*index+1)-mini});}
                if(node->right){q.push({node->right,(2*index+2)-mini});}
                
            }
            ans=max(ans,second-first+1);
        }
        return ans;
    }
};