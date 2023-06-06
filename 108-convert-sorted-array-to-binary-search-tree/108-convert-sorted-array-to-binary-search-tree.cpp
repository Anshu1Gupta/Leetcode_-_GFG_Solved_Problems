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
    TreeNode*ConvertToBst(int low,int high,vector<int>&nums){
        if(low<=high){
            int mid=(low+high)/2;
            TreeNode* root=new TreeNode(nums[mid]);
            root->left=ConvertToBst(low,mid-1,nums);
            root->right=ConvertToBst(mid+1,high,nums);
            return root;
            
        }
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int high=nums.size()-1;
        return ConvertToBst(0,high,nums);
    }
};