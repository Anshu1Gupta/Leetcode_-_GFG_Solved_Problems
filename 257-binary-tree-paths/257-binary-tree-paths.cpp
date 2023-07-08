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
void f(TreeNode* root,string temp,vector<string> &ans)
  {
      temp=temp+to_string(root->val);

      if(root->left==NULL && root->right==NULL)
      {
          ans.push_back(temp);
      }
        
     if(root->left)
      f(root->left,temp+"->",ans);
     if(root->right)
      f(root->right,temp+"->",ans);

      temp.pop_back();
  }

    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string>ans;
        string temp="";
        f(root,temp,ans);
        return ans;

    }
};