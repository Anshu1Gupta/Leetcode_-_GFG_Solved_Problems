class Solution {
public:
    int res = 0;
    void dfs(TreeNode * root,long long int t){
        if(!root) return;
        if(root->val==t)res++;
        dfs(root->left,t-root->val);
        dfs(root->right,t-root->val);
    }
    int pathSum(TreeNode* root, int t) {
        if(root){
            dfs(root,t);
            pathSum(root->left,t);
            pathSum(root->right,t);
        }
        return res;
    }
};