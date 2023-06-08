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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
   if(root==NULL)return {};
    queue<TreeNode*>q;
    q.push(root);
    int flag=0;
   
    vector<vector<int>>result;
    while(!q.empty()){
       
        int size=q.size();
          vector<int>ans(size);
        for(int i=0;i<size;i++){
        TreeNode*node=q.front();q.pop();
            int k=flag?size-i-1:i;
            ans[k]=node->val;

            if(node->left){q.push(node->left);}
            if(node->right){q.push(node->right);}
        }
        result.push_back(ans);

        flag=!flag;
    }
    return result;
    }
};