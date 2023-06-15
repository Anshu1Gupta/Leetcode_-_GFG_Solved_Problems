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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL)return 0;
        queue<TreeNode*>q;
        q.push(root);
        int sum=-1e9;
        int res=0;
        int level=0;
        while(!q.empty()){
            level++;
            int size=q.size();
            int levelSum=0;
            while(size--){
            TreeNode*node=q.front();q.pop();
                levelSum+=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(levelSum>sum){
                sum=levelSum;
                res=level;
            }
        }
        return res;
    }
};