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
  void  findTree(TreeNode*root,vector<string>&ans,string &temp){
      if(root==NULL)return;  
      if(root->left==NULL&&root->right==NULL){
            string num=to_string(root->val);
          int s=temp.size();
            temp.append(num);
            ans.push_back(temp);
            while(temp.size()!=s)temp.pop_back();
            return ;
        }
        int size=temp.size();
        string num=to_string(root->val);
        temp.append(num);
        temp.append("->");
        findTree(root->left,ans,temp);
        findTree(root->right,ans,temp);
        while(temp.size()!=size){
            temp.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string>ans;
        string temp;
        findTree(root,ans,temp);
        return ans;
    }
};